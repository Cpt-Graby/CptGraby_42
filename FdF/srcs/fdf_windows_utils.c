/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_windows_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:07:07 by agonelle          #+#    #+#             */
/*   Updated: 2023/01/09 12:07:12 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_window_size(t_map *map)
{
	if (map->column >= 0 && map->column < 99)
		map->win_w = 400;
	else if (map->column >= 100 && map->column < 500)
		map->win_w = 800;
	else
		map->win_w = 1200;
	if (map->line >= 0 && map->line < 99)
		map->win_h = 400;
	else if (map->line >= 100 && map->line < 500)
		map->win_h = 800;
	else
		map->win_h = 1200;
}

float	set_zoom(t_map *map)
{
	float	zoom1;
	float	zoom2;

	if (map->column >= 0 && map->column < 99)
		zoom1 = 10.0;
	else if (map->column >= 100 && map->column < 500)
		zoom1 = 5.0;
	else
		zoom1 = 1.5;
	if (map->line >= 0 && map->line < 99)
		zoom2 = 10.0;
	else if (map->line >= 100 && map->line < 500)
		zoom2 = 5.0;
	else
		zoom2 = 1.5;
	if (zoom1 > zoom2)
		return (zoom2);
	else
		return (zoom1);
}
