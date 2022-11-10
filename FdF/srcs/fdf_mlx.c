/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:04:55 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/10 14:24:22 by mura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
