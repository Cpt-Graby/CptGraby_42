/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:16:03 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/21 23:28:22 by agonelle         ###   ########.fr       */
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

void	check_in_screen(t_vec3 p1, t_vec3 p2, t_vec3 *cp1, t_vec3 *cp2)
{
	if (p1.x > WIN_W)
		cp1->x = WIN_W;
	else if (p1.x < 0)
		cp1->x = 0;
	if (p1.y > WIN_H)
		cp1->y = WIN_H;
	else if (p1.y < 0)
		cp1->y = 0;
	if (p2.x > WIN_W)
		cp2->x = WIN_W;
	else if (p2.x < 0)
		cp2->x = 0;
	if (p2.y > WIN_H)
		cp2->y = WIN_H;
	else if (p2.y < 0)
		cp2->y = 0;
}

void	draw_line(t_vec3 p1, t_vec3 p2, t_img_dt *data)
{
	t_vec3	p1p;
	t_vec3	p2p;
	t_vec2	e;

	ft_cp_vec3(p1, &p1p);
	ft_cp_vec3(p2, &p2p);
	check_in_screen(p1, p2, &p1p, &p2p);
	e.x = abs((int) p2p.x - (int) p1p.x);
	e.y = abs((int) p2p.y - (int) p1p.y);
	if (e.x > e.y)
	{
		case_dx_dy(e, p1p, p2p, data);
	}
	else
	{
		case_dy_dx(e, p1p, p2p, data);
	}
}
