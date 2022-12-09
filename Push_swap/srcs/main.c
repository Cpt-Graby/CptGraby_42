/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:18:36 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/09 12:02:17 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../42lib/libft.h"
#include "push_swap.h"

int	ckeck_digit_flow(int arg, char **asci_num)
{
	int	i;

	i = 1;
	while (i < arg && ft_check_int(asci_num[i]))
		i++;
	if (i < arg && !ft_check_int(asci_num[i]))
	{
		ft_putstr_fd("Error \n", 2);
		return (0);
	}
	return (i);
}

int	check_double(int arg, char **asci_num)
{
	int		i;
	int		y;
	size_t	len_i;

	i = 1;
	while (i < arg)
	{
		y = i + 1;
		len_i = ft_strlen(asci_num[i]);
		while (y < arg)
		{
			if (!ft_strncmp(asci_num[i], asci_num[y], len_i))
			{
				ft_putstr_fd("Error \n", 2);
				return (0);
			}
			y++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*tab_a;

	if (argc == 1)
	{
		ft_putstr_fd("Error \n", 2);
		return (-1);
	}
	else
	{
		i = ckeck_digit_flow(argc, argv);
		if (!i)
			return (-1);
		if (!check_double(argc, argv))
			return (-1);
		tab_a = malloc(sizeof(*tab_a) * (argc - 1));
		if (!tab_a)
		{
			ft_putstr_fd("Error \n", 2);
			return (-1);
		}
		while (--i > 0)
			tab_a[i] = atoi(argv[i]);
		return (0);
	}
}
