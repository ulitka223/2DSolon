/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekravts <moonriver7609@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:00:30 by dekravts          #+#    #+#             */
/*   Updated: 2024/11/19 07:21:55 by dekravts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	*render_map_two(t_vars *var, char current_obj)
{
	void	*imgur;

	imgur = NULL;
	if (current_obj == '0')
		imgur = var->txt.back;
	else if (current_obj == 'C')
	{
		imgur = var->txt.collec;
	}
	else if (current_obj == 'E')
		imgur = var->txt.exit;
	else if (current_obj == '1')
		imgur = var->txt.wall;
	return (imgur);
}

void	render_player(t_vars *var, int x, int y, void **img)
{
	if (var->direction == UP)
		*img = var->txt.player_up;
	else if (var->direction == DOWN)
		*img = var->txt.player_d;
	else if (var->direction == RIGHT)
		*img = var->txt.player_r;
	else if (var->direction == LEFT)
		*img = var->txt.player_l;
	else
		*img = var->txt.player_up;
	var->x = x;
	var->y = y;
}
