/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:55:42 by naali             #+#    #+#             */
/*   Updated: 2019/02/15 16:29:12 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../includes/t_struct.h"
#include "../includes/fractol.h"

/*
** Transformation des coordonnees en vertex
** Modification des conditions d'affichage.
*/

void			mandelbrot(t_obj *o, t_frac *f)
{
	t_vertex		tmp;
	t_vertex		tmpc;
//	int				x;
//	int				y;
	unsigned int	i;

	tmp.x = 0;
	while (tmp.x < WINX)// <-- retrait de x < f->xmax
	{
		tmp.y = 0;
		f->cr = calc_cr(tmp.x, f);
		while (tmp.y < WINY)// <-- retrait de y < f->ymax
		{
			i = 0;
			tmpc = mult_vtex_by_mat(o->allmat, tmp);// <--- application de matrice sur le vertex.
			tmpc.z = 0;
			f->ci = calc_ci(tmpc.y, f);
			while (check_exist(f) && i < f->itmax)
			{
				calc_iteration(f);
				i++;
			}
			if (tmpc.x < f->xmax && tmpc.x < WINX && \
				tmpc.y < f->ymax && tmpc.y < WINY)// <-- a modifier
				fill_map(o, tmpc.x, tmpc.y, find_color(i, f->itmax, tmpc.x, tmpc.y));
			tmp.y++;
		}
		tmp.x++;
	}
}
