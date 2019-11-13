/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:22:00 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/22 14:24:14 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_mandel(t_frac *frc)
{
	t_complex mins;
	t_complex maxs;

	mins = init_complex(-2, -1.5);
	maxs.re = 1;
	frc->maxi = 100;
	init_plane(&frc->cp, maxs, mins);
	frc->frcfunc = stupid_al;
	frc->fid = 0;
}

void		init_julia(t_frac *frc)
{
	t_complex mins;
	t_complex maxs;

	mins = init_complex(-1.8, -1.8);
	maxs.re = 1.8;
	frc->maxi = 50;
	init_plane(&frc->cp, maxs, mins);
	frc->frcfunc = julia;
	frc->fid = 1;
}

void		init_tricorn(t_frac *frc)
{
	t_complex mins;
	t_complex maxs;

	mins = init_complex(-1.8, -1.8);
	maxs.re = 1.8;
	frc->maxi = 50;
	init_plane(&frc->cp, maxs, mins);
	frc->frcfunc = tricorn;
	frc->fid = 2;
}

void		init_bs(t_frac *frc)
{
	t_complex mins;
	t_complex maxs;

	mins = init_complex(-2.5, -1.9);
	maxs.re = 1;
	frc->maxi = 100;
	init_plane(&frc->cp, maxs, mins);
	frc->frcfunc = bs;
	frc->fid = 3;
}

void		init_frc(t_frac *frc, int i)
{
	frc->get_col = get_color;
	if (i == 0)
		init_mandel(frc);
	if (i == 1)
		init_julia(frc);
	if (i == 2)
		init_tricorn(frc);
	if (i == 3)
		init_bs(frc);
}
