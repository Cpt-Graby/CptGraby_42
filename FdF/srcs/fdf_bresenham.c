/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:16:03 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/21 16:00:48 by kino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_var(t_vec2 *e, t_vec2 *del, t_vec2 *d, t_vec2 *inc)
{
	d->x = 2 * e->x;
	d->y = 2 * e->y;
	del->x = e->x;
	del->y = e->y;
	inc->x = 1;
	inc->y = 1;
}

void	case_dx_dy(t_vec2 e, t_vec3 p1, t_vec3 p2, t_img_dt *data)
{
	int		i;
	t_vec2	del;
	t_vec2	d;
	t_vec2	inc;

	i = 0;
	set_var(&e, &del, &d, &inc);
	if (p1.x > p2.x)
		inc.x = -1;
	if (p1.y > p2.y)
		inc.y = -1;
	while (i <= del.x)
	{
		pixel_2img(data, p1.x, p1.y, 0x00FF0000);
		i++;
		p1.x += inc.x;
		e.x -= d.y;
		if (e.x < 0)
		{
			p1.y += inc.y;
			e.x += d.x;
		}
	}
}

void	case_dy_dx(t_vec2 e, t_vec3 p1, t_vec3 p2, t_img_dt *data)
{
	int		i;
	t_vec2	del;
	t_vec2	d;
	t_vec2	inc;

	i = 0;
	set_var(&e, &del, &d, &inc);
	if (p1.x > p2.x)
		inc.x = -1;
	if (p1.y > p2.y)
		inc.y = -1;
	while (i <= del.y)
	{
		pixel_2img(data, p1.x, p1.y, 0x00FF0000);
		i++;
		p1.y += inc.y;
		e.y -= d.x;
		if (e.y < 0)
		{
			p1.x += inc.x;
			e.y += d.y;
		}
	}
}

void	draw_line(t_vec3 p1, t_vec3 p2, t_img_dt *data)
{
//	t_vec3 p1p;
//	t_vec3 p2p;
	t_vec2	e;

	
	e.x = abs((int) p2.x - (int) p1.x);
	e.y = abs((int) p2.y - (int) p1.y);
	if (e.x > e.y)
		case_dx_dy(e, p1, p2, data);
	else
		case_dy_dx(e, p1, p2, data);
}
