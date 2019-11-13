/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:52:45 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/22 15:11:16 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(double n, int maxiter)
{
	int		r;
	int		g;
	int		b;

	if (n == maxiter)
		return (0xffffff);
	r = sin(0.3 * n) * 50 + 200;
	g = sin(0.3 * n) * 50 + 200;
	b = sin(0.3 * n) * 50 + 200;
	return (((r << 16) & 0x00ff0000) | ((g << 8) & 0xff00) | (b & 0xff));
}

int		get_color1(double n, int maxiter)
{
	int		r;
	int		g;
	int		b;

	if (n == maxiter)
		return (0xffffff);
	r = sin(0.3 * n + 4) * 50 + 200;
	g = sin(0.3 * n + 2) * 50 + 200;
	b = sin(0.3 * n + 0) * 127 + 128;
	return (((r << 16) & 0x00ff0000) | ((g << 8) & 0xff00) | (b & 0xff));
}

int		get_color2(double n, int maxiter)
{
	int		r;
	int		g;
	int		b;

	if (n == maxiter)
		return (0xffffff);
	r = sin(0.1 * n + 4) * 25 + 100;
	g = sin(0.2 * n + 2) * 25 + 100;
	b = sin(0.3 * n + 0) * 30 + 150;
	return (((r << 16) & 0x00ff0000) | ((g << 8) & 0xff00) | (b & 0xff));
}

int		get_color3(double n, int maxiter)
{
	int		r;
	int		g;
	int		b;

	if (n == maxiter)
		return (0xffffff);
	r = sin(0.1 * n + 4) * 30 + 225;
	g = sin(0.1 * n + 0) * 80 + 170;
	b = sin(0.3 * n + 2) * 50 + 200;
	return (((r << 16) & 0x00ff0000) | ((g << 8) & 0xff00) | (b & 0xff));
}
