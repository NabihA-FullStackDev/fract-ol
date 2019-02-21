/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buddha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 00:46:56 by naali             #+#    #+#             */
/*   Updated: 2019/02/21 03:12:50 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/fractol.h"

/*
** BUDDHABROT
** x1 = -2.1, y1 = -1.2
** x2 =  0.6, y2 =  1.2
*/

void		calc_crcizrzi_bud(double x, double y, t_frac *f)
{
	f->cr = (double)(x / f->zoom + f->x1);
	f->ci = (double)(y / f->zoom + f->x1);
	f->zr = 0;
	f->zi = 0;
}

void		init_buddha(t_frac *f)
{
	f->x1 = -2.1;
	f->y1 = -1.2;
	f->x2 = 0.6;
	f->y2 = 1.2;
/* 	f->cr = f->x1; */
/* 	f->ci = f->y1; */
	f->zoom = 150;
	f->itmax = 250;
	f->xmax = fabs(((f->x2 - f->x1) * f->zoom));
	f->ymax = fabs(((f->y2 - f->y1) * f->zoom));
}
