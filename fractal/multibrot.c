/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddha.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 04:09:08 by naali             #+#    #+#             */
/*   Updated: 2019/02/22 04:14:01 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "../includes/t_struct.h"
#include "../includes/fractol.h"

void			multibrot(t_obj *o, t_frac *f)
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
				calc_iteration_multibrot(f, 10);
				i++;
			}
			tmpc = mult_vtex_by_mat(o->allmat, tmp);
			color_to_pix(&(o->img), tmpc.x, tmpc.y, find_color(i, f->itmax, tmpc.x, tmpc.y));
			tmp.y++;
		}
		tmp.x++;
	}
}
