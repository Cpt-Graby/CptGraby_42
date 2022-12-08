/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:29:23 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/08 11:02:01 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_int(char *strnum)
{
	int	i;

	i = 0;
	while (strnum[i] != '\0')
	{
		if (!ft_isdigit(strnum[i]) && strnum[i] != '-')
			return (0);
		i++;
	}
	if (!check_flow(strnum, i))
		return (0);
	return (1);
}

int	check_flow(char *num, int len)
{
	int	res;

	if (len > 11)
		return (0);
	else if (len > 10 && num[0] != '-')
		return (0);
	else if (num[0] == '-' && len == 11)
	{
		res = ft_strncmp(num, "-2147483648", 12);
		if (res > 0)
			return (0);
		else
			return (1);
	}
	else if (num[0] != '-' && len == 10)
	{
		res = ft_strncmp(num, "2147483647", 10);
		if (res > 0)
			return (0);
		else
			return (1);
	}
	else
		return (1);
}
