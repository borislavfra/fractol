/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 13:18:19 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/22 14:29:36 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_args(char **arg)
{
	if (!ft_strcmp(arg[1], "julia"))
		return (1);
	if (!ft_strcmp(arg[1], "tricorn"))
		return (2);
	if (!ft_strcmp(arg[1], "mandelbrot"))
		return (0);
	if (!ft_strcmp(arg[1], "burning ship"))
		return (3);
	return (-1);
}

int		check_input(int ac, char **arg)
{
	int		j;

	if (ac != 2 || (j = check_args(arg)) == -1)
	{
		ft_putendl("usage: ./fractol <type of fractal>");
		ft_putendl("Available types:");
		ft_putendl("julia");
		ft_putendl("mandelbrot");
		ft_putendl("tricorn");
		ft_putendl("burning ship");
		return (-1);
	}
	return (j);
}
