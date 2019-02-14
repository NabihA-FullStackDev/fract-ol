/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:08:32 by naali             #+#    #+#             */
/*   Updated: 2019/02/14 17:08:03 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "includes/fractol.h"
#include "includes/t_struct.h"
#include "libft/libft.h"

int				deal_with_keyboard(int key, void *ptr)
{
	t_win		*tmp;

	tmp = (t_win*)ptr;
	if (key == 53)
	{
		mlx_destroy_window(tmp->mlxp, tmp->winp);
		exit(0);
	}
	return (0);
}

void			tabvrtx_to_img(t_vertex **vtab, t_img *img)
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
	tabvrtx_to_img(o->map, &(o->img));
}

int				main(/* int ac, char **av */)
{
	t_win		w;
	t_obj		man;

	init_struct_win(&w);
	init_init(&w, &man, &init_mandel);
/* Autre matrice a preparer. */
	mlx_put_image_to_window(w.mlxp, w.winp, man.img.imgp, 0, 0);
	mlx_hook(w.winp, 2, 1L<<0, deal_with_keyboard, &w);
	mlx_loop(w.mlxp);
	return (EXIT_ON_SUCCESS);
}
