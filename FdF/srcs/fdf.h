/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:18:50 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/14 08:11:07 by kino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_W 600
# define WIN_H 300

# include <math.h>
# include "../42lib/libft.h"
# include "../mlx.h"

typedef struct s_img_dt {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lth;
	int		endian;
}	t_img_dt;

typedef struct s_map {
	char	*path;
	int		line;
	int		column;
	t_vec3	**data;
}	t_map;

typedef struct s_vars_w{
	void		*mlx;
	void		*win;
	t_img_dt	*pic;
}	t_vars;

//File 2 data
int		check_extension(char *path);
int		map_parser(int fd, t_map *map);
//Keyevent
int		close_win(int keycode, t_vars *vars);
int		print_key(int keycode, t_vars *vars);
//int	update_image()
int		vec2_in_scr(t_vec2 p, int max_h, int max_l);
void	draw_line(t_vec2 p1, t_vec2 p2, t_img_dt *data);
void	mid_2_screen(t_vec2 *p1, t_vec2 *p1p);
//main.c
int		val_in_r(int v, int min, int max);
void	pixel_2img(t_img_dt *data, int x, int y, int color);

#endif
