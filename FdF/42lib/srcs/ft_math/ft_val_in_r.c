/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_in_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:10:09 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/10 15:12:14 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_val_in_r(int v, int min, int max)
{
	if (v >= min && v <= max)
		return (1);
	else
		return (0);
}
