/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 13:14:42 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/22 15:04:43 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse_press1(int button, int x, int y, void *param)
{
	t_cplane	*cp;
	t_complex	xy;
	t_complex	sizes;

	if (button == 1)
		((t_ptrs *)param)->ixy = init_complex(x, y);
	if (button == 5)
	{
		cp = &(((t_ptrs *)param)->frc.cp);
		xy.re = ((double)x / (double)WIDTH *
		(cp->max.re - cp->min.re) + cp->min.re);
		xy.im = ((double)y / (double)HEIGHT *
		(cp->max.im - cp->min.im) + cp->min.im);
		sizes = get_sizes(*cp);
		cp->min = init_complex(xy.re - sizes.re
		* 0.25, xy.im - sizes.im * 0.25);
		cp->max.re = sizes.re * 0.25 + xy.re;
		cp->max.im = cp->min.im + (cp->max.re - cp->min.re) * HEIGHT / WIDTH;
		calc_all(param);
	}
	return (1);
}

int			mouse_press(int button, int x, int y, void *param)
{
	t_cplane	*cp;
	t_complex	sizes;

	mouse_press1(button, x, y, param);
	if (button == 4)
	{
		cp = &(((t_ptrs *)param)->frc.cp);
		sizes = get_sizes(*cp);
		if (sizes.re > 10 || sizes.im > 10)
			return (0);
		cp->min = init_complex(cp->min.re - 0.5 *
		sizes.re, cp->min.im - 0.5 * sizes.im);
		cp->max.re = cp->max.re + 0.5 * sizes.re;
		cp->max.im = cp->min.im + (cp->max.re - cp->min.re) * HEIGHT / WIDTH;
		calc_all(param);
	}
	return (0);
}

int			mouse_move(int x, int y, void *param)
{
	t_complex	xy;
	t_cplane	*cp;

	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT &&
	((t_ptrs *)param)->m_rsps && ((t_ptrs *)param)->frc.fid == 1)
	{
		cp = &(((t_ptrs *)param)->frc.cp);
		xy.re = ((double)x / (double)WIDTH *
		(cp->max.re - cp->min.re) + cp->min.re);
		xy.im = ((double)y / (double)HEIGHT *
		(cp->max.im - cp->min.im) + cp->min.im);
		((t_ptrs *)param)->frc.crds = init_complex(xy.re, xy.im);
		calc_all(param);
	}
	return (0);
}

int			mouse_release(int button, int x, int y, void *param)
{
	t_complex	xy;
	t_complex	fxy;
	t_cplane	*cp;

	if (button == 1)
	{
		cp = &(((t_ptrs *)param)->frc.cp);
		xy.re = ((double)x / (double)WIDTH *
		(cp->max.re - cp->min.re) + cp->min.re);
		xy.im = ((double)y / (double)HEIGHT *
		(cp->max.im - cp->min.im) + cp->min.im);
		fxy.re = (((t_ptrs *)param)->ixy.re /
		(double)WIDTH * (cp->max.re - cp->min.re) + cp->min.re);
		fxy.im = (((t_ptrs *)param)->ixy.im / (double)HEIGHT
		* (cp->max.im - cp->min.im) + cp->min.im);
		if (xy.re > fxy.re)
			swap(&xy.re, &fxy.re);
		if (xy.im > fxy.im)
			swap(&xy.im, &fxy.im);
		cp->max.re = fxy.re;
		cp->min = init_complex(xy.re, xy.im);
		cp->max.im = cp->min.im + (cp->max.re - cp->min.re) * HEIGHT / WIDTH;
		calc_all(param);
	}
	return (0);
}

int			close_w(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
