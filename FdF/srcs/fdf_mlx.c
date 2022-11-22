/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:04:55 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/22 13:05:43 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_2img(t_img_dt *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lth + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	iso_transf(t_vec3 point, t_vec3 *screen, t_map *map)
{
	float	d;
	float	xpy;
	float	xmy;
	float	trsx;
	float	trsy;

	d = 10.0;
	trsx = (float)(map->column / 2) * (-1);
	trsy = (float)(map->line / 2) * (-1);
	xmy = (point.x - point.y);
	xpy = (point.x + point.y);
	screen->x = WIN_W / 2 + (xmy * cos(0.523599) * d) + trsx;
	screen->y = WIN_H / 2 + ((-1) * point.z + xpy) * sin(0.523599) * d + trsy;
	screen->z = point.z;
}

void	map_2_img(t_map *map, t_img_dt *data)
{
	int		x;

	x = 0;
	while (x < map->line)
	{
		line_2_img(map, data, x);
		x++;
	}
	x = 0;
	while (x < map->column)
	{
		column_2_img(map, data, x);
		x++;
	}
}

void	line_2_img(t_map *map, t_img_dt *data, int x)
{
	int		i;
	t_vec3	pt1_sc;
	t_vec3	pt2_sc;

	i = 1;
	while (i < map->column)
	{
		iso_transf(map->tab_line[x].tab_pts[i - 1], &pt1_sc, map);
		iso_transf(map->tab_line[x].tab_pts[i], &pt2_sc, map);
		draw_line(pt1_sc, pt2_sc, data);
		i++;
	}
}

void	column_2_img(t_map *map, t_img_dt *data, int x)
{
	int		i;
	t_vec3	pt1_sc;
	t_vec3	pt2_sc;

	i = 1;
	while (i < map->line)
	{
		iso_transf(map->tab_line[i - 1].tab_pts[x], &pt1_sc, map);
		iso_transf(map->tab_line[i].tab_pts[x], &pt2_sc, map);
		draw_line(pt1_sc, pt2_sc, data);
		i++;
	}
}
