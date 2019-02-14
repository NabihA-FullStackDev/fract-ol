/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:08:32 by naali             #+#    #+#             */
/*   Updated: 2019/02/14 21:17:19 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "includes/fractol.h"
#include "includes/t_struct.h"
#include "libft/libft.h"

#include <stdio.h>

void	refresh_screen(t_win *w, t_obj *o, void(*f)(t_obj*, t_frac*))
{
	mlx_destroy_image(w->mlxp, o->img.imgp);
	init_struct_img(w, &(o->img));
//	init_map(win);
	init_mat_position(o);
	(*f)(o, &(o->fra));
	tabvrtx_to_img(o, o->map, &(o->img));
	mlx_clear_window(w->mlxp, w->winp);
//		Fonction de tracer
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
	if (key == 2)
		printf("%d = Clic droit coordonnes [%d, %d]\n", key, x, y);
	if (key == 3)
		printf("%d = Clic molette coordonnes [%d, %d]\n", key, x, y);
	if (key == 4)
		printf("%d = Out coordonnes [%d, %d]\n", key, x, y);
	if (key == 5)
		printf("%d = In coordonnes [%d, %d]\n", key, x, y);
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
		mlx_destroy_window(tmp->mlxp, tmp->winp);
		exit(0);
	}
	else if (key == 65451)
	{
		if ((tmp->obj->fra.zoom += 5) == 0)
			tmp->obj->fra.zoom += 1;
		refresh_screen(tmp, tmp->obj, tmp->obj->f);
	}
	else if (key == 65453)
	{
		if ((tmp->obj->fra.zoom -= 5) < 0)
			tmp->obj->fra.zoom = 0;
		refresh_screen(tmp, tmp->obj, tmp->obj->f);
	}
	else
		printf("key = %d\n", key);
	return (0);
}

void			tabvrtx_to_img(t_obj *o, t_vertex **vtab, t_img *img)
{
	int			i;
	int			j;
	t_vertex	tmp;

	i = 0;
	while (i < WINX)
	{
		j = 0;
		while (j < WINY)
		{
			tmp = vtab[i][j];
			/*application de matrice sur tmp*/
			tmp = mult_vtex_by_mat(o->allmat, tmp);
			tmp = mult_vtex_by_mat(o->center_mat, tmp);
			/*application de matrice sur tmp*/
			color_to_pix(img, tmp.x, tmp.y, tmp.color);
			j++;
		}
		i++;
	}
}

/*
** initialisation complete d'un obj
*/
void			init_init(t_win *w, t_obj *o, void(*init)(t_frac*))
{
	init_struct_img(w, &(o->img));
	init_struct_obj(o);
	init_angle_n_trans(&(o->angle), &(o->trans));
	init_mat_position(o);
	(*init)(&(o->fra));
	mandelbrot(o, &(o->fra));
	tabvrtx_to_img(o, o->map, &(o->img));
}

int				main(/* int ac, char **av */)
{
	t_win		w;
	t_obj		man;

	man.f = &mandelbrot;
	init_struct_win(&w);
	init_init(&w, &man, &init_mandel);
	mlx_put_image_to_window(w.mlxp, w.winp, man.img.imgp, 0, 0);
	w.obj = &man;
	mlx_hook(w.winp, 2, 1L<<0, deal_with_keyboard, &w);
	mlx_mouse_hook(w.winp, deal_with_mouse, &w);
	mlx_loop(w.mlxp);
	return (EXIT_ON_SUCCESS);
}
