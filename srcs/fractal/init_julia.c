/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 00:36:35 by naali             #+#    #+#             */
/*   Updated: 2019/04/15 11:52:49 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

/*
** JULIA
** x1 = -1, y1 = -1.2
** x2 =  1, y2 =  1.2
*/

void		calc_crcizrzi(double x, double y, t_frac *f)
{
	f->zr = (double)(x / f->zoom + f->x1);
	f->zi = (double)(y / f->zoom + f->y1);
}

void		init_xymax(t_frac *f)
{
	f->xmax = fabs(((f->x2 - f->x1) * f->zoom));
	f->ymax = fabs(((f->y2 - f->y1) * f->zoom));
}

void		init_julia(t_frac *f)
{
	f->x1 = -1;
	f->y1 = -1.2;
	f->x2 = 1;
	f->y2 = 1.2;
	f->zoom = 350;
	f->itmax = 50;
	init_xymax(f);
}
