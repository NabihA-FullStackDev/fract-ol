/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:08:32 by naali             #+#    #+#             */
/*   Updated: 2019/02/28 05:06:13 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "includes/fractol.h"
#include "includes/t_struct.h"
#include "libft/libft.h"

void	refresh_screen(t_win *w, t_obj *o)
{
	mlx_destroy_image(w->mlxp, o->img.imgp);
	init_struct_img(w, &(o->img));
	init_mat_position(o);
//	Fonction de tracer BEGIN
	o->f_draw(o, &(o->fra));
//	Fonction de tracer END
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
}

int				mouse_move(int x, int y, void *tmp)
{
	t_win	*w;

	w = (t_win*)tmp;
	if (x >= 0 && x < WINX && y >= 0 && y < WINY)
	{
		w->obj->fra.itmax = 50 + abs(x - y);
		refresh_screen(w, w->obj);
	}
	print_info(w, w->obj);
	return (0);
}

int				get_move(void *tmp)
{
	t_win	*w;

	w = (t_win*)tmp;
	mlx_hook(w->winp, 6, 1L<<6, mouse_move, w);
	return (0);
}

/*
** MOUSE KEY
** 1 = clic gauche  |  4 = molette out
** 2 = clic droit   |  5 = molette in
** 3 = clic molette |
*/
int				deal_with_mouse(int key, int x, int y, void *ptr)
{
	t_win		*w;
	t_frac		*f;

	(void)x;
	(void)y;
	w = (t_win*)ptr;
	f = &(w->obj->fra);
	if (key == 4)
		f->zoom -= 50;
	else if (key == 5)
		f->zoom += 50;
	refresh_screen(w, w->obj);
	print_info(w, w->obj);
	return (0);
}

int				deal_with_keyboard(int key, void *ptr)
{
	t_win		*w;

	w = (t_win*)ptr;
	if (key == 53)
	{
		mlx_destroy_image(w->mlxp, w->obj->img.imgp);
		mlx_destroy_window(w->mlxp, w->winp);
		exit(0);
	}
	if (key == 123)
		w->obj->trans.tx += 20;
	if (key == 124)
		w->obj->trans.tx -= 20;
	if (key == 125)
		w->obj->trans.ty -= 20;
	if (key == 126)
		w->obj->trans.ty += 20;
	if (key == 69)
		w->obj->mult += 1;
	if (key == 78)
		w->obj->mult -= (w->obj->mult > 3) ? 1 : 0;
	refresh_screen(w, w->obj);
	print_info(w, w->obj);
	return (0);
}

/*
** initialisation complete d'un obj
*/
void			init_init(t_win *w, t_obj *o, int fractal)
{
	o->mult = 3;
	init_struct_win(w);
	o->f_init(&(o->fra));
	init_struct_img(w, &(o->img));
	init_angle_n_trans(&(o->angle), &(o->trans));
	init_mat_position(o);
	o->f_draw(o, &(o->fra));
	mlx_put_image_to_window(w->mlxp, w->winp, o->img.imgp, 0, 0);
	w->obj = o;
	if (fractal == 2)
	{
		mlx_mouse_hook(w->winp, deal_with_mouse, w);
		mlx_loop_hook(w->mlxp, get_move, w);
	}
	mlx_hook(w->winp, 2, 1L<<0, deal_with_keyboard, w);
	mlx_loop(w->mlxp);
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
	else if (fractal == 2 && ac == 2)
	{
		obj.f_init = &init_julia;
		obj.f_draw = &julia;
	}
	else if (fractal == 3 && ac == 2)
	{
		obj.f_init = &init_mandel;
		obj.f_draw = &multibrot;
	}
	else if (ac != 2 || (fractal != 1 && fractal != 2 && fractal != 3))
	{
		ft_putstr("./fractol [1=mandel], [2=Julia], [3=multi]\n");
		return (0);
	}
	init_init(&w, &obj, fractal);
	return (EXIT_ON_SUCCESS);
}
