/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:04:55 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/10 18:32:27 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	vec2_in_scr(t_vec2 p, int max_h, int max_l)
{
	if ((ft_val_in_r(p.x, 0, max_l) && ft_val_in_r(p.y, 0, max_h))
		&& (ft_val_in_r(p.x, 0, max_l) && ft_val_in_r(p.y, 0, max_h)))
		return (1);
	else
		return (0);
}

void	vect2_transf(t_vec2 *p1, t_vec2 *p2)
{
	p2->x = p1->x;
	p2->y = p1->y;
}
	
void	draw_line(t_vec2 p1, t_vec2 p2, t_img_dt *data)
{
	int		e;
	t_vec2	ps;
	t_vec2	pe;
	t_vec2	d;

	if (!vec2_in_scr(p1, WIN_H, WIN_W) && !vec2_in_scr(p2, WIN_H, WIN_W))
		ft_putstr_fd("Erreur coordonnee", 1);
	if (p1.x > p2.x)
	{
		vect2_transf(&p1, &ps);
		vect2_transf(&p2, &pe);
	}
	else
	{
		vect2_transf(&p2, &ps);
		vect2_transf(&p1, &pe);
	}

	e = pe.x - ps.x;
	d.x = e * 2;
	d.y = (pe.y - ps.y) * 2;
	while (ps.x <= pe.x)
	{
		pixel_2img(data, ps.x, ps.y, color);
		ps.x++;
		e = e - d.y;
		if(e <= 0) 
		{
			ps.y++;
      e ← e + dx ;  // ajuste l’erreur commise dans cette nouvelle rangée
    fin si ;
  fin faire ;
  // Le pixel final (x2, y2) n’est pas tracé.
fin procédure ;
	}
}
