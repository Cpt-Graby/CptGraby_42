/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:55:41 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/22 08:21:07 by mura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_main(char *path)
{
	t_map		map;
	t_vars		vars;
	t_img_dt	img;

	if (!check_extension(path))
	{
		errno = EINVAL;
		perror("main.c - fdf_main ");
		exit(-1);
	}
	if (!main_parser(path, &map))
		exit(-1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "My first window!");
	img.img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lth,
			&img.endian);
	map_2_img(&map, &img);
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
