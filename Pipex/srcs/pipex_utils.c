/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:48:33 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/28 00:07:03 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_bonus(char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", ft_maxlstr(argv[1], "here_doc")))
		return (0);
	else
		return (1);
}
