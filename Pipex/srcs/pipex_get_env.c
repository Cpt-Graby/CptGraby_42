/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_get_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:05:09 by agonelle          #+#    #+#             */
/*   Updated: 2022/12/06 16:29:04 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path(char *envp[])
{
	int		i;
	char	*path;
	char	**tab;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	path = ft_strdup((envp[i] + 5));
	tab = ft_split(path, ':');
	free(path);
	return (tab);
}
