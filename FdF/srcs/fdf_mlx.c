/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:04:55 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/17 18:54:26 by mura             ###   ########.fr       */
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
