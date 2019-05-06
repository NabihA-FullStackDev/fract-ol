/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:57:15 by naali             #+#    #+#             */
/*   Updated: 2019/05/03 15:09:16 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "mlx.h"
#include "t_struct.h"
#include "fractol.h"

static void		init_var_mandel(t_vertex *tmp, t_vertex *tmpc, t_frac *f)
{
	f->xmax = fabs(((f->x2 - f->x1) * f->zoom));
	f->ymax = fabs(((f->y2 - f->y1) * f->zoom));
	tmp->x = f->x1 * f->zoom;
	tmpc->x = f->x1 * f->zoom;
}

void			mandelbrot(t_obj *o, t_frac *f)
{
	t_vertex		tmp;
	t_vertex		tmpc;
	unsigned int	i;

	init_var_mandel(&tmp, &tmpc, f);
	while (tmpc.x < WINX)
	{
		tmp.y = f->y1 * f->zoom;
		tmpc = mult_vtex_by_mat(o->allmat, tmp);
		f->cr = calc_cr(tmp.x - (double)(WINX / 2), f);
		while (tmpc.y < WINY)
		{
			i = 0;
			f->ci = calc_ci(tmp.y - (double)(WINY / 2), f);
			calc_iteration_mandel(f, &i);
			tmpc = mult_vtex_by_mat(o->allmat, tmp);
			tmpc = mult_vtex_by_mat(o->center_mat, tmpc);
			color_to_pix(&(o->img), tmpc.x, tmpc.y, find_color(i, f, 12));
			tmp.y++;
		}
		tmp.x++;
	}
}
