/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_sec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekravts <moonriver7609@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:10:51 by dekravts          #+#    #+#             */
/*   Updated: 2024/11/19 07:05:39 by dekravts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	flood_fill(t_vars *vars, int x, int y, char **map)
{
	if (x < 0 || y < 0 || !map[y] || map[y][x] == '\0' || map[y][x] == '1'
		|| map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		vars->count_c++;
	else if (map[y][x] == 'E')
		vars->count_m++;
	map[y][x] = 'X';
	flood_fill(vars, x + 1, y, map);
	flood_fill(vars, x - 1, y, map);
	flood_fill(vars, x, y + 1, map);
	flood_fill(vars, x, y - 1, map);
}

int	find_player(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
			{
				vars->x = j;
				vars->y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	write(2, "Error: No player found.\n", 24);
	return (0);
}

int	has_exit_path(t_vars *vars)
{
	if (vars->map[vars->y - 1][vars->x] != '1' && vars->map[vars->y
		- 1][vars->x] != 'E')
		return (1);
	if (vars->map[vars->y + 1][vars->x] != '1' && vars->map[vars->y
		+ 1][vars->x] != 'E')
		return (1);
	if (vars->map[vars->y][vars->x - 1] != '1' && vars->map[vars->y][vars->x
		- 1] != 'E')
		return (1);
	if (vars->map[vars->y][vars->x + 1] != '1' && vars->map[vars->y][vars->x
		+ 1] != 'E')
		return (1);
	return (0);
}

int	validate_path(t_vars *vars)
{
	char	**map_copy;

	if (!find_player(vars))
		return (0);
	if (!has_exit_path(vars))
	{
		write(2, "Error: Player has nowhere to move.\n", 35);
		return (0);
	}
	vars->count_c = 0;
	vars->count_m = 0;
	map_copy = duplicate_map(vars->map);
	flood_fill(vars, vars->x, vars->y, map_copy);
	free_map(map_copy);
	if (vars->count_c != count_characters(vars->map, 'C')
		|| vars->count_m != count_characters(vars->map, 'E'))
	{
		write(2, "Error: Not all items are reachable.\n", 36);
		return (0);
	}
	return (1);
}

int	count_rows(char **map)
{
	int	count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}
