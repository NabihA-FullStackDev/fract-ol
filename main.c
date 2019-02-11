/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:08:32 by naali             #+#    #+#             */
/*   Updated: 2019/02/11 18:25:30 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "includes/fractol.h"
#include "libft/libft.h"

void		mandelbrot(t_win *w);

static void		init_struct_win(t_win *w)
{
	w->m.nbl = 0;
	w->mlxp = mlx_init();
	w->winp = mlx_new_window(w->mlxp, WINX, WINY, "Fractol");
//	w->m.mat = init_matrice();
}

int				main(int ac, char **av)
{
	t_win		w;

	if (ac != 1)
	{
		ft_putstr("Usage: ./fractol\n");
		return (0);
	}
	init_struct_win(&w);
	w.simg.imgp = mlx_new_image(w.mlxp, WINX, WINY);
	w.simg.data = (int*)mlx_get_data_addr(w.simg.imgp,\
					 &(w.simg.bpp), &(w.simg.s_l), &(w.simg.endian));
	mandelbrot(&w);
//	init_map(&w);
	mlx_put_image_to_window(w.mlxp, w.winp, w.simg.imgp, 0, 0);
//	mlx_hook(w.winp, 2, 1L<<0, deal_with_keyboard, &w);
	mlx_loop(w.mlxp);
	return (0);
}
