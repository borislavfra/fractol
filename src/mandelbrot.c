/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:58:06 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/22 14:58:34 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		stupid_al(t_complex c, int maxiter, t_complex crds, t_getcol get_col)
{
	double		iter;
	t_complex	z;
	double		lz;
	double		nu;
	t_complex	sqz;

	(void)crds;
	z = init_complex(c.re, c.im);
	iter = -1;
	nu = 0;
	sqz = init_complex(z.re * z.re, z.im * z.im);
	while (++iter < maxiter && (sqz.re + sqz.im) <= 15)
	{
		z = init_complex(
		sqz.re - sqz.im + c.re,
		2.0 * z.re * z.im + c.im);
		sqz = init_complex(z.re * z.re, z.im * z.im);
	}
	if (iter < maxiter)
	{
		lz = z.re * z.re + z.im * z.im;
		nu = log(log(lz)) / log(2.0);
		iter = iter + 1.0 - nu;
	}
	return (get_col(iter, maxiter));
}
