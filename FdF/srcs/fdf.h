/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:18:50 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/10 14:29:56 by mura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_W 600
# define WIN_H 300

# include <math.h>
# include "../42lib/libft.h"
# include "../mlx.h"

typedef struct s_vars_w{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_img_dt {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lth;
	int		endian;
}	t_img_dt;

typedef struct s_vec2 {
	int		x;
	int		y;
}	t_vec2;

//Keyevent
int	close_win(int keycode, t_vars *vars);
int	print_key(int keycode, t_vars *vars);
int	vec2_in_scr(t_vec2 p, int max_h, int max_l);
void	draw_line(t_vec2 p1, t_vec2 p2, t_img_dt *data);
//main.c
int	val_in_r(int v, int min, int max);
void	pixel_2img(t_img_dt *data, int x, int y, int color);

#endif
