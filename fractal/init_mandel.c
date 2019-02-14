/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:11:49 by naali             #+#    #+#             */
/*   Updated: 2019/02/14 18:17:53 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** MANDELBROT
*/
/*
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
	f->x2 = 0.6;
	f->y2 = 1.2;
	f->zoom = 500;
	f->itmax = 100;
}

int			check_exist(t_frac *f)
{
	if ((f->zr * f->zr + f->zi * f->zi) < 4)
		return (1);
	return (0);
}

void		calc_iteration(t_frac *f)
{
	f->tmp = f->zr;
	f->zr = (f->zr * f->zr) - (f->zi * f->zi) + f->cr;
	f->zi = (2 * f->tmp * f->zi) + f->ci;
}

#include <stdio.h>

void		fill_map(t_obj *o, int x, int y, int color)
{
	(o->map[x][y]).x = x;
	(o->map[x][y]).y = y;
	(o->map[x][y]).z = 0;
	(o->map[x][y]).color = color;
}
