/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekravts <moonriver7609@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:07:03 by dekravts          #+#    #+#             */
/*   Updated: 2024/11/19 07:24:13 by dekravts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"
#include "../incs/so_long.h"

int	action(int key, t_vars *var)
{
	if (key == 53)
	{
		mlx_destroy_window(var->mlx, var->win);
		free_map(var->map);
		free_img(var);
		free(var->mlx);
		exit(0);
	}
	else if (key == 13)
		move_up(var);
	else if (key == 0)
		move_left(var);
	else if (key == 1)
		move_down(var);
	else if (key == 2)
		move_right(var);
	return (1);
}

int	close_window(t_vars *var)
{
	mlx_destroy_window(var->mlx, var->win);
	free_map(var->map);
	free_img(var);
	free(var->mlx);
	exit(0);
}

void	count_width(t_vars *var)
{
	size_t	m_w;
	int		m_h;

	m_w = ft_strlen(var->map[0]);
	m_h = 0;
	while (var->map[m_h])
		m_h++;
	var->width = m_w * TILE;
	var->height = m_h * TILE;
}

int	main(int argc, char **argv)
{
	t_vars	var;

	if (argc != 2)
	{
		write(1, "choose a map\n", 13);
		return (0);
	}
	var.count_c = 0;
	var.mlx = mlx_init();
	var.map = read_map(argv[1]);
	if (!validate_map(&var))
	{
		free_map(var.map);
		return (1);
	}
	write(1, "Map is valid!\n", 14);
	count_wind(&var);
	var.win = mlx_new_window(var.mlx, var.width, var.height, "hueta");
	var.count_m = 0;
	load_img(&var);
	render_map(&var, var.map);
	mlx_hook(var.win, 2, 0, action, &var);
	mlx_loop(var.mlx);
}
