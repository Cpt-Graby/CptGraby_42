/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:55:41 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/12 00:34:32 by kino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_2img(t_img_dt *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lth + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
		ft_free_tab((void **)tab, 3);
		return (1);
	}
}

void def_4_point(t_vec2 *p1, t_vec2 *p2, t_vec2 *p3, t_vec2 *p4)
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

	midx= WIN_W / 2;
	midy= WIN_H / 2;
	p1p->x = p1->x + midx;
	p1p->y = p1->y + midy;
}

void draw_cub(t_vec2 p1, t_vec2 p2, t_vec2 p3, t_vec2 p4, t_img_dt *img)
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

int	**map_parser(char **path)
{
	char	*str;
	

	return (0);
}
int	fdf_main(char *path)
{
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
	def_4_point(&p1,&p2,&p3,&p4);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "My first window!");
	img.img = mlx_new_image(vars.mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lth,
			&img.endian);
//	draw_line(p1, p2, &img);
	draw_cub(p1, p2, p3, p4, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_key_hook(vars.win, print_key, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

int main(int argc, char **argv)
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

//	draw_line(p4, p2, &img);
