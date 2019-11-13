/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:45:57 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/22 15:03:57 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1024
# define HEIGHT 1024
# define PNUM 32
# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_cplane
{
	t_complex	min;
	t_complex	max;
}				t_cplane;

typedef	int		(*t_getcol)(double n, int maxi);
typedef	int		(*t_func)(t_complex c, int maxiter,
				t_complex crds, t_getcol get_col);

typedef struct	s_frac
{
	t_complex	z;
	t_complex	c;
	t_cplane	cp;
	int			maxi;
	char		*img_data;
	int			id;
	int			bpp;
	int			size_line;
	t_func		frcfunc;
	t_getcol	get_col;
	int			fid;
	t_complex	crds;
}				t_frac;

typedef struct	s_ptrs
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_complex	min;
	t_complex	max;
	t_frac		frc;
	pthread_t	*threads;
	int			m_rsps;
	t_complex	ixy;
}				t_ptrs;

int				key_press(int keycode, void *param);
int				close_w(void *param);
int				check_args(char **arg);
void			calc_all(t_ptrs *ptrs);
t_complex		init_complex(double re, double im);
void			init_plane(t_cplane *cp, t_complex maxs, t_complex mins);
void			create_pic(t_ptrs *ptrs);
int				mouse_press(int button, int x, int y, void *param);
t_complex		get_sizes(t_cplane plane);
int				stupid_al(t_complex c, int maxiter,
				t_complex crds, t_getcol get_col);
int				julia(t_complex c, int maxiter,
				t_complex crds, t_getcol get_col);
int				mouse_move(int x, int y, void *param);
void			init_mandel(t_frac *frc);
void			init_julia(t_frac *frc);
void			init_tricorn(t_frac *frc);
int				tricorn(t_complex c, int maxiter,
				t_complex crds, t_getcol get_col);
void			init_bs(t_frac *frc);
int				bs(t_complex c, int maxiter, t_complex crds, t_getcol get_col);
int				mouse_release(int button, int x, int y, void *param);
int				get_color(double n, int maxiter);
int				get_color1(double n, int maxiter);
int				get_color2(double n, int maxiter);
int				get_color3(double n, int maxiter);
void			init_frc(t_frac *frc, int i);
int				check_input(int ac, char **arg);
void			swap(double *a, double *b);

#endif
