/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:04:55 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/21 16:17:03 by kino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_2img(t_img_dt *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lth + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	vec2_in_scr(t_vec3 p, int max_h, int max_l)
{
	if ((ft_val_in_r(p.x, 0, max_l) && ft_val_in_r(p.y, 0, max_h))
		&& (ft_val_in_r(p.x, 0, max_l) && ft_val_in_r(p.y, 0, max_h)))
		return (1);
	else
		return (0);
}

void	projection_ecran(t_vec3 point, t_vec3 *screen, float zoom)
{
	screen->x = (WIN_W / 2) + (point.x / point.z) * zoom;
	screen->y = (WIN_H / 2) + (point.y / point.z) * zoom;
	screen->z = point.z;
}

void	iso_transf(t_vec3 point, t_vec3 *screen, float d)
{
	screen->x = WIN_W / 2 +((point.x - point.y) * cos(0.523599) * d);
	screen->y = WIN_H / 2 +((-1) *point.z + (point.x + point.y) * sin(0.523599)) * d;
	screen->z = point.z;
}

void	map_2_img(t_map *map, t_img_dt *data)
{
	int		x;
	float	zoom;

	x = 0;
	zoom = 5.5;
	while (x < map->line)
	{
		line_2_img(map, data, x, zoom);
		x++;
	}
	x = 0;
	while (x < map->column)
	{
		column_2_img(map, data, x, zoom);
		x++;
	}
}

void	line_2_img(t_map *map, t_img_dt *data, int x, float zoom)
{
	int	i;

	t_vec3	pt1_sc;
	t_vec3	pt2_sc;

	i = 1;
	while (i < map->column)
	{
		iso_transf(map->tab_line[x].tab_pts[i - 1], &pt1_sc, zoom);
		iso_transf(map->tab_line[x].tab_pts[i], &pt2_sc, zoom);
		draw_line(pt1_sc, pt2_sc, data);
		i++;
	}
}

void	column_2_img(t_map *map, t_img_dt *data, int x, float zoom)
{
	int	i;

	t_vec3	pt1_sc;
	t_vec3	pt2_sc;

	i = 1;
	while (i < map->line)
	{
		iso_transf(map->tab_line[i - 1].tab_pts[x], &pt1_sc, zoom);
		iso_transf(map->tab_line[i].tab_pts[x], &pt2_sc, zoom);
		draw_line(pt1_sc, pt2_sc, data);
		i++;
	}
}
