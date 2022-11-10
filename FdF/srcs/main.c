/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:55:41 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/10 13:14:40 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_2img(t_img_dt *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lth + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	val_in_r(int v, int min, int max)
{
	if (v >= min && v <= max)
		return (1);
	else
		return (0);
}

int	vec2_in_scr(t_vec2 p, int max_h, int max_l)
{
	if ((val_in_r(p.x, 0, max_l) && val_in_r(p.y, 0, max_h))
		&& (val_in_r(p.x, 0, max_l) && val_in_r(p.y, 0, max_h)))
		return (1);
	else
		return (0);
}

void	draw_line(t_vec2 p1, t_vec2 p2, t_img_dt *data)
{
	int		dx;
	int		dy;
	float	m;
	t_vec2	pi;

	if (!vec2_in_scr(p1, WIN_H, WIN_W) && !vec2_in_scr(p2, WIN_H, WIN_W))
		ft_putstr_fd("Erreur coordonnee", 1);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	m = dy / dx;
	pi.x = p1.x;
	while (pi.x <= p2.x)
	{
		pi.y = m * pi.x + p1.y;
		pixel_2img(data, pi.x, pi.y, 0x00FF0000);
		pi.x++;
	}
}

int	check_extension(char *path)
{
	char	**tab;
	int		i;

	tab = ft_split(path, '.');
	if (!tab)
	{
		errno = ENOMEM;
		perror("main.c - Check_extension");
		exit(-1);
	}
	i = 0;

	while (tab[i])
		i++;
	if  (i != 2)
		return (0);
	else if (ft_strncmp("fdf", tab[1], fmax(3, ft_strlen(tab[1]))))
		return (0);
	else
	{
		while (i <= 0)
			free(tab[i--]);
		free(tab);
		return (1);
	}
}
int	fdf_main(char *path)
{
	t_vars		vars;
	t_img_dt	img;
	t_vec2		p1;
	t_vec2		p2;

	if (!check_extension(path))
	{
		errno = EINVAL;
		perror("main.c - fdf_main ");
		exit(-1);
	}
	p1.x = 10;
	p1.y = 10;
	p2.x = 100;
	p2.y = 200;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "My first window!");
	img.img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lth,
			&img.endian);
	draw_line(p1, p2, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_key_hook(vars.win, print_key, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	int	err;

	if (argc == 1)
	{
		errno = EINVAL;
		perror("main.c - main: too few arguments");
	}
	else if (argc == 2)
		err = fdf_main(argv[1]);
	else
	{
		errno = E2BIG;
		perror("main.c - main:");
	}
	return (err);
	}
