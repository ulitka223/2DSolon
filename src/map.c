/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekravts <moonriver7609@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:36:30 by dekravts          #+#    #+#             */
/*   Updated: 2024/11/19 01:45:03 by dekravts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"
#include "../incs/so_long.h"

size_t	counter(int fd)
{
	char	*buffer;
	size_t	lenght;
	int		bytes;

	lenght = 0;
	buffer = malloc(2 * sizeof(char));
	bytes = read(fd, buffer, 1);
	while (bytes)
	{
		if (buffer[0] == '\n')
			lenght += 0;
		else
			lenght++;
		bytes = read(fd, buffer, 1);
	}
	free(buffer);
	return (lenght);
}

void	helper(int *fd, const char *filename)
{
	close(*fd);
	*fd = open(filename, O_RDONLY);
}

char	**read_map(const char *filename)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * ((counter(fd) + 1)));
	helper(&fd, filename);
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	render_map(t_vars *var, char **map)
{
	int		i;
	int		j;
	int		y;
	int		x;
	void	*img;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			x = j * 32;
			y = i * 32;
			if (map[i][j] == 'P')
				render_player(var, x, y, &img);
			else
				img = render_map_two(var, map[i][j]);
			mlx_put_image_to_window(var->mlx, var->win, img, x, y);
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	char **map;
// 	t_vars var;

// 	map = read_map("maps/map1.ber");
// 	render_map(&var, map);
// 	for (int i = 0; map[i] != NULL; i++)
// 		printf("%s\n", map[i]);
// 	free_map(map);
// }