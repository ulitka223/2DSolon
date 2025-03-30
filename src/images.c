/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekravts <moonriver7609@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:00:57 by dekravts          #+#    #+#             */
/*   Updated: 2024/11/19 06:47:29 by dekravts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	load_img(t_vars *all)
{
	all->txt.wall = mlx_xpm_file_to_image(all->mlx, "texture/wall.xpm",
			&all->img.w, &all->img.h);
	all->txt.player_up = mlx_xpm_file_to_image(all->mlx, "texture/ship_up.xpm",
			&all->img.w, &all->img.h);
	all->txt.player_d = mlx_xpm_file_to_image(all->mlx, "texture/ship_down.xpm",
			&all->img.w, &all->img.h);
	all->txt.player_l = mlx_xpm_file_to_image(all->mlx, "texture/ship_left.xpm",
			&all->img.w, &all->img.h);
	all->txt.player_r = mlx_xpm_file_to_image(all->mlx,
			"texture/ship_right.xpm", &all->img.w, &all->img.h);
	all->txt.back = mlx_xpm_file_to_image(all->mlx, "texture/background.xpm",
			&all->img.w, &all->img.h);
	all->txt.collec = mlx_xpm_file_to_image(all->mlx, "texture/collectable.xpm",
			&all->img.w, &all->img.h);
	all->txt.exit = mlx_xpm_file_to_image(all->mlx, "texture/exit.xpm",
			&all->img.w, &all->img.h);
	if (!all->txt.player_up || !all->txt.player_d || !all->txt.player_r
		|| !all->txt.player_l)
	{
		fprintf(stderr, "Error: Failed to load player textures\n");
		exit(EXIT_FAILURE);
	}
}

void	free_img(t_vars *all)
{
	if (all->txt.wall)
		mlx_destroy_image(all->mlx, all->txt.wall);
	if (all->txt.player_up)
		mlx_destroy_image(all->mlx, all->txt.player_up);
	if (all->txt.player_d)
		mlx_destroy_image(all->mlx, all->txt.player_d);
	if (all->txt.back)
		mlx_destroy_image(all->mlx, all->txt.back);
	if (all->txt.collec)
		mlx_destroy_image(all->mlx, all->txt.collec);
}
