/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:18:50 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/10 13:13:34 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_W 600
# define WIN_H 300

# include <math.h>
# include "../42lib/libft.h"
# include "../mlx.h"

typedef struct s_vars_w{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_img_dt {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lth;
	int		endian;
}	t_img_dt;

typedef struct s_vec2 {
	int		x;
	int		y;
}	t_vec2;

//Keyevent
int	close_win(int keycode, t_vars *vars);
int	print_key(int keycode, t_vars *vars);

#endif
