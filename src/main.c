/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:45:34 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/08/22 14:56:19 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char **arg)
{
	t_ptrs	ptrs;
	int		j;

	if ((j = check_input(ac, arg)) == -1)
		return (0);
	ptrs.min = init_complex(0, 0);
	ptrs.max = init_complex(0, 0);
	ptrs.m_rsps = 1;
	ptrs.img_ptr = NULL;
	ptrs.mlx_ptr = mlx_init();
	ptrs.win_ptr = mlx_new_window(ptrs.mlx_ptr, WIDTH, HEIGHT, "<3");
	init_frc(&ptrs.frc, j);
	calc_all(&ptrs);
	mlx_hook(ptrs.win_ptr, 2, 0, key_press, &ptrs);
	mlx_hook(ptrs.win_ptr, 4, 0, mouse_press, &ptrs);
	mlx_hook(ptrs.win_ptr, 5, 0, mouse_release, &ptrs);
	mlx_hook(ptrs.win_ptr, 6, 0, mouse_move, &ptrs);
	mlx_hook(ptrs.win_ptr, 17, 0, close_w, &ptrs);
	mlx_loop(ptrs.mlx_ptr);
	return (1);
}
