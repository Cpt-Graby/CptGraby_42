/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file2data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:04:09 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/14 08:06:34 by kino             ###   ########.fr       */
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

