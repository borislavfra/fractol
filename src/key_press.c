/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:42:12 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/22 14:43:51 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	key_press1(int keycode, void *param)
{
	if (keycode == 27)
	{
		((t_ptrs *)param)->frc.maxi *= 0.5;
		if (((t_ptrs *)param)->frc.maxi < 2)
			((t_ptrs *)param)->frc.maxi = 2;
	}
	if (keycode == 24)
	{
		((t_ptrs *)param)->frc.maxi *= 2;
		if (((t_ptrs *)param)->frc.maxi > 15000)
			((t_ptrs *)param)->frc.maxi = 15000;
	}
	if (keycode == 49)
	{
		if (((t_ptrs *)param)->frc.fid == 0)
			init_mandel(&((t_ptrs *)param)->frc);
		if (((t_ptrs *)param)->frc.fid == 1)
			init_julia(&((t_ptrs *)param)->frc);
		if (((t_ptrs *)param)->frc.fid == 2)
			init_tricorn(&((t_ptrs *)param)->frc);
		if (((t_ptrs *)param)->frc.fid == 3)
			init_bs(&((t_ptrs *)param)->frc);
	}
	return (1);
}

static int	key_press2(int keycode, void *param, int *i)
{
	t_complex	sizes;

	if (keycode == 82)
		((t_ptrs *)param)->m_rsps = !((t_ptrs *)param)->m_rsps;
	if (keycode == 124)
	{
		if (++*i > 3)
			*i = 0;
		if (*i == 0)
			((t_ptrs *)param)->frc.get_col = get_color;
		if (*i == 1)
			((t_ptrs *)param)->frc.get_col = get_color1;
		if (*i == 2)
			((t_ptrs *)param)->frc.get_col = get_color2;
		if (*i == 3)
			((t_ptrs *)param)->frc.get_col = get_color3;
	}
	if (keycode == 0)
	{
		sizes = get_sizes(((t_ptrs *)param)->frc.cp);
		((t_ptrs *)param)->frc.cp.max.re += 0.1 * sizes.re;
		((t_ptrs *)param)->frc.cp.min.re += 0.1 * sizes.re;
	}
	return (1);
}

static int	key_press3(int keycode, void *param, int *i)
{
	t_complex	sizes;

	if (keycode == 123)
	{
		if (--*i < 0)
			*i = 3;
		if (*i == 0)
			((t_ptrs *)param)->frc.get_col = get_color;
		if (*i == 1)
			((t_ptrs *)param)->frc.get_col = get_color1;
		if (*i == 2)
			((t_ptrs *)param)->frc.get_col = get_color2;
		if (*i == 3)
			((t_ptrs *)param)->frc.get_col = get_color3;
	}
	if (keycode == 2)
	{
		sizes = get_sizes(((t_ptrs *)param)->frc.cp);
		((t_ptrs *)param)->frc.cp.max.re -= 0.1 * sizes.re;
		((t_ptrs *)param)->frc.cp.min.re -= 0.1 * sizes.re;
	}
	if (keycode == 53)
		exit(0);
	return (1);
}

int			key_press(int keycode, void *param)
{
	t_complex	sizes;
	static int	i;

	key_press1(keycode, param);
	key_press2(keycode, param, &i);
	key_press3(keycode, param, &i);
	if (keycode == 1)
	{
		sizes = get_sizes(((t_ptrs *)param)->frc.cp);
		((t_ptrs *)param)->frc.cp.max.im -= 0.1 * sizes.im;
		((t_ptrs *)param)->frc.cp.min.im -= 0.1 * sizes.im;
	}
	if (keycode == 13)
	{
		sizes = get_sizes(((t_ptrs *)param)->frc.cp);
		((t_ptrs *)param)->frc.cp.max.im += 0.1 * sizes.im;
		((t_ptrs *)param)->frc.cp.min.im += 0.1 * sizes.im;
	}
	calc_all(param);
	return (0);
}
