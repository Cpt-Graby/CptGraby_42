/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file2data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:04:09 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/17 17:08:28 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void	print_tabl(t_map *map)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < map->line)
	{
		i = 0;
		while (i < map->column)
		{
			ft_printf("(%d-", map->tab_line[y].tab_pts[i].x);
			ft_printf("%d-", map->tab_line[y].tab_pts[i].y);
			ft_printf("%d) ", map->tab_line[y].tab_pts[i].z);
			i++;
		}
		ft_printf("\n");
		y++;
	}
}
*/
t_line	*get_next_pts_line(t_map *map, char **tab)
{
	int		i;
	t_vec3	*dt_pts;
	t_line	*new_tab;

	new_tab = malloc(sizeof(*new_tab) * (map->line + 1));
	dt_pts = malloc(sizeof(*dt_pts) * map->column);
	i = 0;
	if (map->line)
	{
		while (i < map->line)
		{
			new_tab[i] = map->tab_line[i];
			i++;
		}
		free(map->tab_line);
	}
	i = -1;
	while (++i < map->column)
	{
		dt_pts[i].x = i;
		dt_pts[i].y = map->line;
		dt_pts[i].z = ft_atoi(tab[i]);
	}
	new_tab[map->line].tab_pts = dt_pts;
	return (new_tab);
}

void	get_first_info_parser(char *line, t_map *map)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(line, ' ');
	while (tab[i])
		i++;
	map->column = i;
	map->line = 0;
	map->max_h = 0;
	map->tab_line = get_next_pts_line(map, tab);
	map->line++;
	ft_free_tab((void **)tab, i);
	free(line);
}

int	line_2_tab(char *line, t_map *map)
{
	char	**tab;
	int		i;

	if (!check_line(line))
	{
		perror("fdf_file2data.c - checkline");
		free(line);
		return (0);
	}
	tab = ft_split(line, ' ');
	i = 0;
	while (tab[i])
		i++;
	if (i != map->column)
	{
		ft_free_tab((void **)tab, i);
		perror("fdf_file2data.c - line_2_tab");
		return (0);
	}
	map->tab_line = get_next_pts_line(map, tab);
	free(line);
	ft_free_tab((void **)tab, i);
	return (1);
}

int	map_parser(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!check_line(line))
	{
		perror("fdf_file2data.c - checkline");
		free(line);
		return (0);
	}	
	get_first_info_parser(line, map);
	line = get_next_line(fd);
	while (line)
	{
		if (!line_2_tab(line, map))
			return (0);
		line = get_next_line(fd);
		map->line++;
	}
	return (1);
}

int	main_parser(char *path, t_map *map)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("fdf_file2data.c - main_parser (fd):");
		return (0);
	}
	if (!map_parser(fd, map))
	{
		perror("fdf_file2data.c - map_parser (fd):");
		return (0);
	}
	close (fd);
	return (1);
}
//	print_tabl(map);
