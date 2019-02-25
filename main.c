/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:08:32 by naali             #+#    #+#             */
/*   Updated: 2019/02/25 18:42:30 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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

/*
** MOUSE KEY
** 1 = clic gauche  |  4 = molette out
** 2 = clic droit   |  5 = molette in
** 3 = clic molette |
*/
int				deal_with_mouse(int key, int x, int y, void *ptr)
{
	t_win		*tmp;

	tmp = (t_win*)ptr;
	if (key == 1)
		printf("%d = Clic gauche coordonnes [%d, %d]\n", key, x, y);
	else if (key == 2)
		printf("%d = Clic droit coordonnes [%d, %d]\n", key, x, y);
	else if (key == 3)
		printf("%d = Clic molette coordonnes [%d, %d]\n", key, x, y);
	else if (key == 4)
	{
		if ((tmp->obj->fra.zoom -= 5) <= 0)
			tmp->obj->fra.zoom = 1;
		tmp->obj->fra.x1 -= (x / tmp->obj->fra.zoom);
		tmp->obj->fra.y1 -= (y / tmp->obj->fra.zoom);
		tmp->obj->fra.x2 += (x / tmp->obj->fra.zoom);
		tmp->obj->fra.y2 += (y / tmp->obj->fra.zoom);
	refresh_screen(tmp, tmp->obj);
		printf("%d = Out coordonnes [%d, %d]\n", key, x, y);
	}
	else if (key == 5)
	{
		if ((tmp->obj->fra.zoom += 5) == 0)
			tmp->obj->fra.zoom += 1;
		tmp->obj->fra.x1 += (double)(x / WINX) + fabs(tmp->obj->fra.x1);
		tmp->obj->fra.y1 += (double)(y / WINY) + fabs(tmp->obj->fra.y1);
		tmp->obj->fra.x2 -= (double)(x / WINX) - fabs(tmp->obj->fra.x2);
		tmp->obj->fra.y2 -= (double)(y / WINY) - fabs(tmp->obj->fra.y2);
//		printf(tmp->obj->fra.x1);//modif
	refresh_screen(tmp, tmp->obj);
		printf("%d = In coordonnes [%d, %d]\n", key, x, y);
	}
	else
		printf("key = %d coordonnes [%d, %d]\n", key, x, y);
	return (0);
}

int				deal_with_keyboard(int key, void *ptr)
{
	t_win		*tmp;

	tmp = (t_win*)ptr;
	if (key == 53 || key == 65307)
	{
		mlx_destroy_image(tmp->mlxp, tmp->obj->img.imgp);
		mlx_destroy_window(tmp->mlxp, tmp->winp);
		exit(0);
	}
	else if (key == 69 || key == 65451)
	{
		if ((tmp->obj->fra.zoom += 5) == 0)
			tmp->obj->fra.zoom += 1;
//		refresh_screen(tmp, tmp->obj);
	}
	else if (key == 78 || key == 65453)
	{
		if ((tmp->obj->fra.zoom -= 5) < 0)
			tmp->obj->fra.zoom = 0;
//		refresh_screen(tmp, tmp->obj);
	}
	else if (key == 86 || key == 65432)
	{
		tmp->obj->angle.beta -= 5;
//		refresh_screen(tmp, tmp->obj);
	}
	else if (key == 88 || key == 65430)
	{
		tmp->obj->angle.beta += 5;
	}
	else
		printf("key = %d\n", key);
	refresh_screen(tmp, tmp->obj);
	return (0);
}

/*
** initialisation complete d'un obj
*/
void			init_init(t_win *w, t_obj *o)
{
	init_struct_win(w);
	o->f_init(&(o->fra));
	init_struct_img(w, &(o->img));
	init_angle_n_trans(&(o->angle), &(o->trans));
	init_mat_position(o);
	o->f_draw(o, &(o->fra));

	mlx_put_image_to_window(w->mlxp, w->winp, o->img.imgp, 0, 0);
	w->obj = o;
	mlx_hook(w->winp, 2, 1L<<0, deal_with_keyboard, w);
	mlx_mouse_hook(w->winp, deal_with_mouse, w);
	mlx_loop(w->mlxp);
}

int				main(int ac, char **av)
{
	t_win		w;
	t_obj		obj;

	if (ft_atoi(av[1]) == 1 && ac == 2)
	{
		obj.f_init = &init_mandel;
		obj.f_draw = &mandelbrot;
	}
	else if (ft_atoi(av[1]) == 2 && ac == 2)
	{
		obj.f_init = &init_julia;
		obj.f_draw = &julia;
	}
	else if (ft_atoi(av[1]) == 3 && ac == 2)
	{
		obj.f_init = &init_mandel;
		obj.f_draw = &multibrot;
	}
	else if (ac != 2)
	{
		ft_putstr("./fractol [1=mandel], [2=Julia], [3=multi]\n");
		return (0);
	}
	init_init(&w, &obj);
	return (EXIT_ON_SUCCESS);
}
