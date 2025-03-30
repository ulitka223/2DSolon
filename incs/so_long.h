/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekravts <moonriver7609@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:59:16 by dekravts          #+#    #+#             */
/*   Updated: 2024/11/19 07:22:04 by dekravts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define RED 0x00FF0000
# define WHITE 0x00FFFFFF
# define YELLOW 0x00FFFF00
# define TILE 32
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

typedef struct s_img
{
	void		*img;
	char		*path;
	int			w;
	int			h;
}				t_img;

typedef struct s_textures
{
	void		*wall;
	void		*player_up;
	void		*player_d;
	void		*player_l;
	void		*player_r;
	void		*collec;
	void		*back;
	void		*exit;
}				t_textures;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	char		**map;
	int			direction;
	int			count_c;
	int			count_m;
	int			width;
	int			height;
	t_textures	txt;
	t_img		img;
}				t_vars;

void			load_img(t_vars *all);
size_t			counter(int fd);
void			helper(int *fd, const char *filename);
char			**read_map(const char *filename);
void			free_map(char **map);
void			render_map(t_vars *var, char **map);
void			*render_map_two(t_vars *var, char current_obj);
void			render_player(t_vars *var, int x, int y, void **img);
void			move_up(t_vars *var);
void			move_left(t_vars *var);
void			move_down(t_vars *var);
void			move_right(t_vars *var);
void			free_img(t_vars *all);
int				close_window(t_vars *var);
// map Check FUCK
int				count_characters(char **map, char c);
int				validate_required_elements(t_vars *var);
int				check_top_bottom_walls(char **map, int width);
int				check_side_walls(char **map, int width);
int				validate_wall_boundaries(char **map);
void			flood_fill(t_vars *vars, int x, int y, char **map);
int				find_player(t_vars *vars);
int				validate_path(t_vars *vars);
int				count_rows(char **map);
char			**duplicate_map(char **map);
int				validate_map(t_vars *var);
// utils:
void			ft_putnbr(int n);
char			*ft_strdup(char *src);

#endif