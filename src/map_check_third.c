/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_third.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekravts <moonriver7609@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:17:12 by dekravts          #+#    #+#             */
/*   Updated: 2024/11/19 07:24:00 by dekravts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

char	**duplicate_map(char **map)
{
	int		rows;
	char	**map_copy;
	int		i;

	rows = count_rows(map);
	map_copy = malloc((rows + 1) * sizeof(char *));
	i = 0;
	while (i < rows)
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[rows] = NULL;
	return (map_copy);
}

int	validate_map(t_vars *var)
{
	if (!validate_required_elements(var))
		return (0);
	if (!validate_wall_boundaries(var->map))
		return (0);
	if (!validate_path(var))
		return (0);
	return (1);
}
