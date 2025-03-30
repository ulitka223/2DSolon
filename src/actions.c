/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekravts <moonriver7609@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:21:14 by dekravts          #+#    #+#             */
/*   Updated: 2024/11/19 06:46:22 by dekravts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	wrapper(t_vars *var)
{
	mlx_clear_window(var->mlx, var->win);
	render_map(var, var->map);
	write(1, "\n", 1);
}

void	move_up(t_vars *var)
{
	var->direction = UP;
	if (var->map[var->y / TILE - 1][var->x / TILE] == 'C')
	{
		var->map[var->y / TILE][var->x / TILE] = '0';
		var->map[var->y / TILE - 1][var->x / TILE] = 'P';
		var->count_c--;
		ft_putnbr(++var->count_m);
	}
	else if (var->map[var->y / TILE - 1][var->x / TILE] == 'E')
	{
		if (var->count_c == 0)
		{
			var->map[var->y / TILE][var->x / TILE] = '0';
			var->map[var->y / TILE - 1][var->x / TILE] = 'P';
			mlx_clear_window(var->mlx, var->win);
			close_window(var);
		}
	}
	else if (var->map[var->y / TILE - 1][var->x / TILE] != '1')
	{
		var->map[var->y / TILE][var->x / TILE] = '0';
		var->map[var->y / TILE - 1][var->x / TILE] = 'P';
		ft_putnbr(++var->count_m);
	}
	wrapper(var);
}

void	move_left(t_vars *var)
{
	var->direction = LEFT;
	if (var->map[var->y / TILE][var->x / TILE - 1] == 'C')
	{
		var->map[var->y / TILE][var->x / TILE] = '0';
		var->map[var->y / TILE][var->x / TILE - 1] = 'P';
		var->count_c--;
		ft_putnbr(++var->count_m);
	}
	else if (var->map[var->y / TILE][var->x / TILE - 1] == 'E')
	{
		if (var->count_c == 0)
		{
			var->map[var->y / TILE][var->x / TILE] = '0';
			var->map[var->y / TILE][var->x / TILE - 1] = 'P';
			mlx_clear_window(var->mlx, var->win);
			close_window(var);
		}
	}
	else if (var->map[var->y / TILE][var->x / TILE - 1] != '1')
	{
		var->map[var->y / TILE][var->x / TILE] = '0';
		var->map[var->y / TILE][var->x / TILE - 1] = 'P';
		ft_putnbr(++var->count_m);
	}
	wrapper(var);
}

void	move_down(t_vars *var)
{
	var->direction = DOWN;
	if (var->map[var->y / TILE + 1][var->x / TILE] == 'C')
	{
		var->map[var->y / TILE][var->x / TILE] = '0';
		var->map[var->y / TILE + 1][var->x / TILE] = 'P';
		var->count_c--;
		ft_putnbr(++var->count_m);
	}
	else if (var->map[var->y / TILE + 1][var->x / TILE] == 'E')
	{
		if (var->count_c == 0)
		{
			var->map[var->y / TILE][var->x / TILE] = '0';
			var->map[var->y / TILE + 1][var->x / TILE] = 'P';
			mlx_clear_window(var->mlx, var->win);
			close_window(var);
		}
	}
	else if (var->map[var->y / TILE + 1][var->x / TILE] != '1')
	{
		var->map[var->y / TILE][var->x / TILE] = '0';
		var->map[var->y / TILE + 1][var->x / TILE] = 'P';
		ft_putnbr(++var->count_m);
	}
	wrapper(var);
}

void	move_right(t_vars *var)
{
	var->direction = RIGHT;
	if (var->map[var->y / TILE][var->x / TILE + 1] == 'C')
	{
		var->map[var->y / TILE][var->x / TILE] = '0';
		var->map[var->y / TILE][var->x / TILE + 1] = 'P';
		var->count_c--;
		ft_putnbr(++var->count_m);
	}
	else if (var->map[var->y / TILE][var->x / TILE + 1] == 'E')
	{
		if (var->count_c == 0)
		{
			var->map[var->y / TILE][var->x / TILE] = '0';
			var->map[var->y / TILE][var->x / TILE + 1] = 'P';
			mlx_clear_window(var->mlx, var->win);
			close_window(var);
		}
	}
	else if (var->map[var->y / TILE][var->x / TILE + 1] != '1')
	{
		var->map[var->y / TILE][var->x / TILE] = '0';
		var->map[var->y / TILE][var->x / TILE + 1] = 'P';
		ft_putnbr(++var->count_m);
	}
	wrapper(var);
}
