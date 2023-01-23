/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kino </var/spool/mail/kino>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:18:35 by kino              #+#    #+#             */
/*   Updated: 2023/01/09 12:07:39 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_extension(char *path)
{
	char	**tab;
	int		i;
	int		c;

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
	if (i != 2)
		c = 0;
	else if (ft_strncmp("fdf", tab[1], fmax(3, ft_strlen(tab[1]))))
		c = 0;
	else
		c = 1;
	ft_free_tab((void **)tab, i);
	return (c);
}

int	check_line(char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (str[i] && flag)
	{
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

void	free_t_line(t_line *line, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(line->tab_pts);
		i++;
	}
	free(line);
}

int	vec3_in_screen(t_vec3 vec, int max_L, int max_H)
{
	int	y;
	int	x;

	x = (int)(vec.x);
	y = (int)(vec.y);
	if (((int) vec.x <= 0 || x >= max_L) || ((int) vec.y <= 0 || y >= max_H))
		return (0);
	else
		return (1);
}
