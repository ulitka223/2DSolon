/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekravts <moonriver7609@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:02:36 by dekravts          #+#    #+#             */
/*   Updated: 2024/11/19 07:21:51 by dekravts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"
#include "../incs/so_long.h"

int	count_characters(char **map, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	validate_required_elements(t_vars *var)
{
	int	player_count;
	int	exit_count;

	player_count = count_characters(var->map, 'P');
	var->count_c = count_characters(var->map, 'C');
	exit_count = count_characters(var->map, 'E');
	if (player_count != 1 || var->count_c < 1 || exit_count != 1)
	{
		write(2, "Error: Invalid number of elements.\n", 35);
		return (0);
	}
	return (1);
}

int	check_top_bottom_walls(char **map, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[count_rows(map) - 1][i] != '1')
		{
			write(2, "Error: Map is not surrounded by walls.\n", 39);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_side_walls(char **map, int width)
{
	int	i;
	int	rows;

	rows = count_rows(map);
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
		{
			write(2, "Error: Map is not surrounded by walls.\n", 39);
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_wall_boundaries(char **map)
{
	int	width;

	width = ft_strlen(map[0]);
	if (!check_top_bottom_walls(map, width))
		return (0);
	if (!check_side_walls(map, width))
		return (0);
	return (1);
}
