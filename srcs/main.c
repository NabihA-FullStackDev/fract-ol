/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:08:32 by naali             #+#    #+#             */
/*   Updated: 2019/04/15 11:44:55 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "fractol.h"
#include "t_struct.h"
#include "libft.h"

void			refresh_screen(t_win *w, t_obj *o)
{
	mlx_destroy_image(w->mlxp, o->img.imgp);
	init_struct_img(w, &(o->img));
	init_mat_position(o);
	o->f_draw(o, &(o->fra));
	mlx_clear_window(w->mlxp, w->winp);
	mlx_put_image_to_window(w->mlxp, w->winp, o->img.imgp, 0, 0);
}

void			print_info(t_win *w, t_obj *o)
{
	w->info = ft_strjoin("iteration = ", ft_itoa(o->fra.itmax));
	mlx_string_put(w->mlxp, w->winp, 5, 575, 0xFF0000, w->info);
	free(w->info);
	w->info = ft_strjoin("zoom = ", ft_itoa(o->fra.zoom));
	mlx_string_put(w->mlxp, w->winp, 170, 575, 0xFF0000, w->info);
	free(w->info);
	if (w->flgf == 2)
	{
		w->info = ft_strjoin("x mouse = ", ft_itoa(w->xmouse));
		mlx_string_put(w->mlxp, w->winp, 340, 575, 0xFF0000, w->info);
		free(w->info);
		w->info = ft_strjoin("y mouse = ", ft_itoa(w->ymouse));
		mlx_string_put(w->mlxp, w->winp, 500, 575, 0xFF0000, w->info);
		free(w->info);
	}
}

static void		init_init(t_win *w, t_obj *o, int fractal)
{
	if (fractal == 1 || fractal == 2 || fractal == 3)
	{
		o->mult = 3;
		w->flgf = fractal;
		init_struct_win(w);
		o->fra.xcor = 0;
		o->fra.ycor = 0;
		o->f_init(&(o->fra));
		init_struct_img(w, &(o->img));
		init_angle_n_trans(&(o->angle), &(o->trans));
		init_mat_position(o);
		o->f_draw(o, &(o->fra));
		mlx_put_image_to_window(w->mlxp, w->winp, o->img.imgp, 0, 0);
		w->obj = o;
		print_info(w, w->obj);
		mlx_mouse_hook(w->winp, deal_with_mouse, w);
		if (fractal == 2)
		{
			mlx_loop_hook(w->mlxp, get_move, w);
		}
		mlx_hook(w->winp, 2, 1L << 0, deal_with_keyboard, w);
		mlx_loop(w->mlxp);
	}
}

int				main(int ac, char **av)
{
	t_win		w;
	t_obj		obj;
	static int	fractal = 0;

	if (ac == 2 && (fractal = ft_atoi(av[1])) == 1)
	{
		obj.f_init = &init_mandel;
		obj.f_draw = &mandelbrot;
	}
	else if (ac == 2 && fractal == 2)
	{
		obj.f_init = &init_julia;
		obj.f_draw = &julia;
	}
	else if (ac == 2 && fractal == 3)
	{
		obj.f_init = &init_mandel;
		obj.f_draw = &multibrot;
	}
	else if (ac != 2 || (fractal != 1 && fractal != 2 && fractal != 3))
		ft_putstr("./fractol [1=mandel], [2=Julia], [3=multi]\n");
	init_init(&w, &obj, fractal);
	return (EXIT_ON_SUCCESS);
}
