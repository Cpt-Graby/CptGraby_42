/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:55:41 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/17 13:38:19 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	def_4_point(t_vec2 *p1, t_vec2 *p2, t_vec2 *p3, t_vec2 *p4)
{
	p1->x = -50;
	p1->y = -50;
	p2->x = -50;
	p2->y = 50;
	p3->x = 50;
	p3->y = -50;
	p4->x = 50;
	p4->y = 50;
}

void	mid_2_screen(t_vec2 *p1, t_vec2 *p1p)
{
	int	midx;
	int	midy;

	midx = WIN_W / 2;
	midy = WIN_H / 2;
	p1p->x = p1->x + midx;
	p1p->y = p1->y + midy;
}

void	draw_cub(t_vec2 p1, t_vec2 p2, t_vec2 p3, t_vec2 p4, t_img_dt *img)
{
	t_vec2	p1p;
	t_vec2	p2p;
	t_vec2	p3p;
	t_vec2	p4p;

	mid_2_screen(&p1, &p1p);
	mid_2_screen(&p2, &p2p);
	mid_2_screen(&p3, &p3p);
	mid_2_screen(&p4, &p4p);
	draw_line(p1p, p2p, img);
	draw_line(p1p, p3p, img);
	draw_line(p4p, p3p, img);
	draw_line(p4p, p2p, img);
}

int	fdf_main(char *path)
{
	t_map		map;
	t_vars		vars;
	t_img_dt	img;
	t_vec2		p1;
	t_vec2		p2;
	t_vec2		p3;
	t_vec2		p4;

	if (!check_extension(path))
	{
		errno = EINVAL;
		perror("main.c - fdf_main ");
		exit(-1);
	}
	if (!main_parser(path, &map))
		exit(-1);
	def_4_point(&p1, &p2, &p3, &p4);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "My first window!");
	img.img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lth,
			&img.endian);
	draw_cub(p1, p2, p3, p4, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_key_hook(vars.win, print_key, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	int	err;

	err = 0;
	if (argc == 1)
	{
		errno = EINVAL;
		perror("main.c - main");
	}
	else if (argc == 2)
		err = fdf_main(argv[1]);
	else
	{
		errno = E2BIG;
		perror("main.c - main");
	}
	return (err);
}

//	draw_line(p4, p2, &img);
