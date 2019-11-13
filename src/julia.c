/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:57:16 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/22 14:57:47 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia(t_complex c, int maxiter, t_complex crds, t_getcol get_col)
{
	double		iter;
	t_complex	z;
	double		lz;
	double		nu;
	t_complex	sqz;

	z = init_complex(c.re, c.im);
	iter = -1;
	nu = 0;
	sqz = init_complex(z.re * z.re, z.im * z.im);
	while (++iter < maxiter && (sqz.re + sqz.im) <= 15)
	{
		z = init_complex(
		sqz.re - sqz.im + crds.re,
		2.0 * z.re * z.im + crds.im);
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
