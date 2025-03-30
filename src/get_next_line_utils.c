/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekravts <moonriver7609@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 03:30:39 by dekravts          #+#    #+#             */
/*   Updated: 2024/11/19 06:46:50 by dekravts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"
#include "../incs/so_long.h"

int	new_present(char *line, char c)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*cpy_do_new(char *line, char *buffer)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (line == NULL)
	{
		line = (char *)malloc(sizeof(char) * 1);
		line[i] = '\0';
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer)
				+ 2));
	while (line[i])
	{
		result[i] = line[i];
		i++;
	}
	while (buffer[j])
		result[i++] = buffer[j++];
	result[ft_strlen(line) + ft_strlen(buffer)] = '\0';
	free(line);
	return (result);
}
