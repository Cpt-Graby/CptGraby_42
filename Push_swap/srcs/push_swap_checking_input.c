/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checking_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:31:01 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/22 11:10:28 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main_checking_input(char **ascii_num_tab)
{
	if (!check_digit_flow(ascii_num_tab))
		return (0);
	if (!check_double(ascii_num_tab))
		return (0);
	return (1);
}

int	check_digit_flow(char **asci_num)
{
	int	i;

	i = 0;
	while (asci_num[i] && ft_check_int(asci_num[i]))
		i++;
	if (asci_num[i] && !ft_check_int(asci_num[i]))
		return (0);
	return (i);
}

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

int	check_double(char **asci_num)
{
	int		i;
	int		y;
	size_t	len_i;

	i = 0;
	while (asci_num[i])
	{
		y = i + 1;
		len_i = ft_strlen(asci_num[i]);
		while (asci_num[y])
		{
			if (!ft_strncmp(asci_num[i], asci_num[y], len_i))
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}
