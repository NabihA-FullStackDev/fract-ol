/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:55:42 by naali             #+#    #+#             */
/*   Updated: 2019/02/22 04:13:45 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "mlx.h"
#include "../includes/t_struct.h"
#include "../includes/fractol.h"

void			mandelbrot(t_obj *o, t_frac *f)
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
		f->cr = calc_cr(tmp.x, f);
		while (tmpc.y < WINY)
		{
			i = 0;
			f->ci = calc_ci(tmp.y, f);
			while (check_exist(f) && i < f->itmax)
			{
				calc_iteration(f);
				i++;
			}
			tmpc = mult_vtex_by_mat(o->allmat, tmp);
			color_to_pix(&(o->img), tmpc.x, tmpc.y, find_color(i, f->itmax, tmpc.x, tmpc.y));
			tmp.y++;
		}
		tmp.x++;
	}
}
