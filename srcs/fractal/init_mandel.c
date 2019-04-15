/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:11:49 by naali             #+#    #+#             */
/*   Updated: 2019/04/15 11:32:09 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "fractol.h"

/*
** MANDELBROT
** x1 = -2.1, y1 = -1.2
** x2 =  0.6, y2 =  1.2
*/

double		calc_cr(int x, t_frac *f)
{
	return ((double)((x / f->zoom) + f->x1));
}

double		calc_ci(int y, t_frac *f)
{
	f->zr = 0;
	f->zi = 0;
	return ((double)((y / f->zoom) + f->y1));
}

void		init_mandel(t_frac *f)
{
	f->x1 = -2.1;
	f->y1 = -1.2;
	f->x2 = 1.0;
	f->y2 = 1.2;
	f->cr = f->x1;
	f->ci = f->y1;
	f->zoom = 250;
	f->itmax = 100;
	f->xmax = fabs(((f->x2 - f->x1) * f->zoom));
	f->ymax = fabs(((f->y2 - f->y1) * f->zoom));
}
