/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:55:41 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/09 14:42:49 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42lib/libft.h"
#include "../mlx.h"
#include "fdf.h"


int	close_win(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

void pixel_2img(t_img_dt *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lth + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw
int fdf_main()
{
	t_vars		vars;
	t_img_dt	img;
	t_vec2		p1;
	t_vec2		p2;
	
	p1.x = 10;
	p1.y = 10;

	p2.x = 100;
	p2.y = 100;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "My first window!");
	img.img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lth,
								&img.endian);
	d
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_loop(vars.mlx);

	return (0);
}

int main (int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	int	err;
	
	err = fdf_main();
	return (err);
}
