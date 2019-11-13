/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:30:41 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/22 14:56:46 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		swap(double *a, double *b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}

t_complex	get_sizes(t_cplane plane)
{
	t_complex	sizes;

	sizes.re = fabs(plane.max.re - plane.min.re);
	sizes.im = fabs(plane.max.im - plane.min.im);
	return (sizes);
}
