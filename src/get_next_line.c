/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekravts <moonriver7609@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:18:07 by dekravts          #+#    #+#             */
/*   Updated: 2024/11/19 07:21:37 by dekravts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"
#include "../incs/so_long.h"

static char	*red(char *line, int fd)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && new_present(line, '\n') == 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		line = cpy_do_new(line, buffer);
	}
	free(buffer);
	return (line);
}

static char	*gnl(char *line)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	res = (char *)malloc((i + 2) * sizeof(char));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		res[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

static char	*obrezanie(char *line)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	if (line[i] == '\0')
		return (free(line), NULL);
	str = (char *)malloc(((ft_strlen(line) - i + 1)) * sizeof(char));
	if (!line[i])
		return (free(line), NULL);
	while (line[i] != '\0')
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = red(line, fd);
	next_line = gnl(line);
	line = obrezanie(line);
	return (next_line);
}

// int	main(void)
// {
// 	int	fd = open("z.txt", O_RDWR);
// 	char	*chto = get_next_line(0);
// 	// chto = get_next_line(fd);
// 	printf("%s", chto);
// 	chto = get_next_line(0);
// 	printf("%s", chto);
// 	// chto = get_next_line(fd);
// 	// printf("%s",chto);
// 	free(chto);
// 	close(fd);
// }