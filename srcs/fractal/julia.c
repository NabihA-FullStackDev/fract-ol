/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 00:28:45 by naali             #+#    #+#             */
/*   Updated: 2019/04/13 16:23:27 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "../includes/t_struct.h"
#include "../includes/fractol.h"

void			julia(t_obj *o, t_frac *f)
{
	t_vertex		tmp;
	t_vertex		tmpc;
	unsigned int	i;

	tmp.x = -WINX;
	tmpc.x = 0;
	while (tmpc.x < WINX)
	{
		tmp.y = -WINY;
		tmpc = mult_vtex_by_mat(o->allmat, tmp);
		while (tmpc.y < WINY)
		{
			i = 0;
			calc_crcizrzi(tmp.x, tmp.y, f);
			while (check_exist(f) && i < f->itmax)
			{
				calc_iteration(f);
				i++;
			}
			tmpc = mult_vtex_by_mat(o->allmat, tmp);
			color_to_pix(&(o->img), tmpc.x, tmpc.y, find_color(i, f->itmax));
			tmp.y++;
		}
		tmp.x++;
	}
}
