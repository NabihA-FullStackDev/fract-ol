/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 00:28:45 by naali             #+#    #+#             */
/*   Updated: 2019/05/03 14:59:34 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "t_struct.h"
#include "fractol.h"

static void		init_var_julia(t_vertex *tmp, t_vertex *tmpc, t_frac *f)
{
	tmp->x = (f->x1 * f->zoom);
	tmpc->x = (f->x1 * f->zoom);
	init_xymax(f);
}

void			julia(t_obj *o, t_frac *f)
{
	t_vertex		tmp;
	t_vertex		tmpc;
	unsigned int	i;

	init_var_julia(&tmp, &tmpc, f);
	while (tmpc.x < WINX)
	{
		tmp.y = (f->y1 * f->zoom);
		tmpc = mult_vtex_by_mat(o->allmat, tmp);
		while (tmpc.y < WINY)
		{
			i = 0;
			calc_crcizrzi((tmp.x - (WINX / 2)), (tmp.y - (WINY / 2)), f);
			while (check_exist(f) && i < f->itmax)
			{
				calc_iteration(f);
				i++;
			}
			tmpc = mult_vtex_by_mat(o->allmat, tmp);
			tmpc = mult_vtex_by_mat(o->center_mat, tmpc);
			color_to_pix(&(o->img), tmpc.x, tmpc.y, find_color(i, f, 4));
			tmp.y++;
		}
		tmp.x++;
	}
}
