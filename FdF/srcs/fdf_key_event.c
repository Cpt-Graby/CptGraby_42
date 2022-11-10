/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:28:12 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/10 12:32:55 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
//		mlx_destroy_image(vars->mlx, img->img);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	exit (0);
	return (0);
}

int	print_key(int keycode, t_vars *vars)
{
	(void) vars;
	ft_printf("-%d-", keycode);
	if (keycode == 65307)
		close_win(keycode, vars);
	return (0);
}
