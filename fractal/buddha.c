/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:55:42 by naali             #+#    #+#             */
/*   Updated: 2019/02/21 02:57:33 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "../includes/t_struct.h"
#include "../includes/fractol.h"

void		calc_iteration_test(t_frac *f);
int			check_exist_test(t_frac *f);

void			buddhabrot(t_obj *o, t_frac *f)
{
	t_vertex		tmp;
	t_vertex		tmpc;
	unsigned int	i;

	tmp.x = 0;
	tmpc.x = 0;
	while (tmpc.x < WINX)
	{
		tmp.y = 0;
		tmpc = mult_vtex_by_mat(o->allmat, tmp);
		while (tmpc.y < WINY)
		{
			i = 0;
			calc_crcizrzi_bud(tmp.x, tmp.y, f);
			while (check_exist_test(f) == 1 && i < f->itmax)
			{
				calc_iteration_test(f);
				i++;
			}
			tmpc = mult_vtex_by_mat(o->allmat, tmp);
			color_to_pix(&(o->img), tmpc.x, tmpc.y, find_color(i , f->itmax, tmpc.x, tmpc.y));
/* 			color_to_pix(&(o->img), tmpc.x + (f->zr - f->x1) * f->zoom, tmpc.y + (f->zi - f->y1) * f->zoom, find_color_bud(i)); */
			tmp.y++;
		}
		tmp.x++;
	}
}
