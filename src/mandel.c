/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:51:30 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/22 15:01:32 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_color(t_frac *frc, int color, int x, int y)
{
	int	o;

	o = (x * frc->bpp / 8 + y * frc->size_line);
	frc->img_data[o] = color & 0xff;
	frc->img_data[++o] = color >> 8 & 0xff;
	frc->img_data[++o] = color >> 16 & 0xff;
	frc->img_data[++o] = 0;
}

static void	*draw(void *dat)
{
	int			x;
	int			y;
	int			n;
	t_frac		m;

	m = *((t_frac *)dat);
	y = m.id * HEIGHT / PNUM - 1;
	while (++y < HEIGHT / PNUM * (m.id + 1))
	{
		x = -1;
		while (++x < WIDTH)
		{
			m.c = init_complex((double)x, (double)y);
			m.c = init_complex(
				(m.c.re / (double)WIDTH * (m.cp.max.re
				- m.cp.min.re) + m.cp.min.re),
				(m.c.im / (double)HEIGHT * (m.cp.max.im
				- m.cp.min.im) + m.cp.min.im));
			n = m.frcfunc(m.c, m.maxi, m.crds, m.get_col);
			set_color(((t_frac *)dat), n, x, y);
		}
	}
	return (NULL);
}

void		calc_all(t_ptrs *ptrs)
{
	t_frac		*f_data;
	int			i;
	pthread_t	*threads;

	if (!ptrs->img_ptr)
		create_pic(ptrs);
	i = -1;
	f_data = (t_frac *)malloc(sizeof(t_frac) * PNUM);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * PNUM);
	while (++i < PNUM)
	{
		f_data[i] = ptrs->frc;
		f_data[i].id = i;
		pthread_create(&threads[i], NULL, draw, &f_data[i]);
	}
	i = -1;
	while (++i < PNUM)
		pthread_join(threads[i], NULL);
	free(threads);
	free(f_data);
	mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, ptrs->img_ptr, 0, 0);
}
