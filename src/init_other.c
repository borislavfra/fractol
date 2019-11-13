/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:54:55 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/22 14:56:38 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void		create_pic(t_ptrs *ptrs)
{
	int		endian;

	ptrs->img_ptr = mlx_new_image(ptrs->mlx_ptr, WIDTH, HEIGHT);
	ptrs->frc.img_data = mlx_get_data_addr(ptrs->img_ptr, &(ptrs->frc.bpp),
	&(ptrs->frc.size_line), &endian);
}

void		init_plane(t_cplane *cp, t_complex maxs, t_complex mins)
{
	cp->min = mins;
	cp->max.re = maxs.re;
	cp->max.im = cp->min.im + (cp->max.re - cp->min.re) * HEIGHT / WIDTH;
}
