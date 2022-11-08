/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonelle <agonelle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:56:31 by agonelle          #+#    #+#             */
/*   Updated: 2022/11/07 16:08:40 by agonelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	int err;

	err = 0;
	if (argc > 2)
	{
		perror("Too many arguments");
	}
	else if (argc < 2)
	{
		perror("No argument");
	}
	else
		perror("test");
//err = start_fdf(argv[1]);
	return (err);
}
