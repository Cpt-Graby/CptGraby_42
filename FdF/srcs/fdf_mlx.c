/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:04:55 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/17 14:45:52 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_2img(t_img_dt *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lth + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	vec2_in_scr(t_vec2 p, int max_h, int max_l)
{
	if ((ft_val_in_r(p.x, 0, max_l) && ft_val_in_r(p.y, 0, max_h))
		&& (ft_val_in_r(p.x, 0, max_l) && ft_val_in_r(p.y, 0, max_h)))
		return (1);
	else
		return (0);
}
	/*if (!vec2_in_scr(p1, WIN_H, WIN_W) && !vec2_in_scr(p2, WIN_H, WIN_W))
		ft_putstr_fd("Erreur coordonnee", 1); */

void	case_dx_dy(t_vec2 *e, t_vec3 *p1, t_vec3 *p2, t_img_dt *data)
{

}
void	draw_line(t_vec3 p1, t_vec3 p2, t_img_dt *data)
{
	int		i;
	t_vec2	e;
	t_vec2	del;
	t_vec2	d;
	t_vec2	inc;

	e.x = abs(p2.x - p1.x);
	e.y = abs(p2.y - p1.y);
	d.x = 2 * e.x;
	d.y = 2 * e.y;
	del.x = e.x;
	del.y = e.y;
	inc.x = 1;
	inc.y = 1;
	i = 0;
	if (p1.x > p2.x)
		inc.x = -1;
	if (p1.y > p2.y)
		inc.y = -1;
	if (del.x > del.y)
	{
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
	else
	{
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
}

