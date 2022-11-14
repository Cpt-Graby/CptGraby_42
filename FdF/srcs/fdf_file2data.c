/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file2data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:04:09 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/14 08:40:10 by kino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_extension(char *path)
{
	char	**tab;
	int		i;

	tab = ft_split(path, '.');
	if (!tab)
	{
		errno = ENOMEM;
		perror("main.c - Check_extension");
		exit(-1);
	}
	i = 0;

	while (tab[i])
		i++;
	if  (i != 2)
		return (0);
	else if (ft_strncmp("fdf", tab[1], fmax(3, ft_strlen(tab[1]))))
		return (0);
	else
	{
		ft_free_tab((void **)tab, 3);
		return (1);
	}
}

int	check_line(char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (str[i] && flag)
	{
		if (ft_isalpha(str[i]))
			flag = 0;
		if (!ft_isprint(str[i]) && str[i] != '\n')
			flag = 0;
		i++;
	}
	if (flag == 0)
	{
		errno = EIO;
		return (0);
	}
	return (1);
}

