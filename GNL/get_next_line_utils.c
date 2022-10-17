/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:07:18 by agonelle          #+#    #+#             */
/*   Updated: 2022/10/17 16:26:38 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_c(char *s, int start, char c)
{
	int	i;

	i = 0;
	while (s[start + i] != '\0' && s[start + i] != c)
		i++;
	if (s[start + i] == c)
		return (start + i);
	else
		return (0);
}	

char	*get_join(char *s1, char *s2, int start, int end)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (end == 0)
		end = get_strlen(s2 + start) - 1;
	res = malloc(sizeof(char) * (get_strlen(s1) + (end - start + 1) + 1));
	while (s1[i])
		res[i] = s1[i];
	if (i != 0)
		i--;
	while (j < (end - start + 1))
	{
		res[i + j] = s2[start + j];
		j++;
	}
	res[i + j] = '\0';
	return (res);	
}

void	get_bzero(void	*s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = '\0';
		i++;
	}
}

int	get_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
