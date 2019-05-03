/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:56:46 by naali             #+#    #+#             */
/*   Updated: 2019/04/22 15:03:52 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include "mlx.h"
#include "t_struct.h"
#include "fractol.h"

static void		init_var_multi(t_vertex *tmp, t_vertex *tmpc, t_frac *f)
{
	f->x1 = -1.6;
	f->xmax = fabs(((f->x2 - f->x1) * f->zoom));
	f->ymax = fabs(((f->y2 - f->y1) * f->zoom));
	tmp->x = f->x1 * f->zoom;
	tmpc->x = f->x1 * f->zoom;
}

void			multibrot(t_obj *o, t_frac *f)
{
	t_vertex		tmp;
	t_vertex		tmpc;
	unsigned int	i;

	init_var_multi(&tmp, &tmpc, f);
	while (tmpc.x < WINX)
	{
		tmp.y = f->y1 * f->zoom;
		tmpc = mult_vtex_by_mat(o->allmat, tmp);
		f->cr = calc_cr(tmp.x - (WINX / 2), f);
		while (tmpc.y < WINY)
		{
			i = 0;
			f->ci = calc_ci(tmp.y - (WINY / 2), f);
			while (check_exist(f) && i < f->itmax)
			{
				calc_iteration_multibrot(f, o->mult);
				i++;
			}
			tmpc = mult_vtex_by_mat(o->allmat, tmp);
			tmpc = mult_vtex_by_mat(o->center_mat, tmpc);
			color_to_pix(&(o->img), tmpc.x, tmpc.y, find_color(i, f, 12));
			tmp.y++;
		}
		tmp.x++;
	}
}
