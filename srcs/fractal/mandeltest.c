/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandeltest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:58:26 by naali             #+#    #+#             */
/*   Updated: 2019/04/14 14:58:49 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "fractol.h"

int			check_exist(t_frac *f)
{
	if (fabs(f->zr * f->zr + f->zi * f->zi) < 4)
		return (1);
	return (0);
}

int			check_exist_test(t_frac *f)
{
	if ((pow(f->zr, 3) + pow(f->zi, 3)) < 4)
		return (1);
	return (0);
}

void		calc_iteration(t_frac *f)
{
	f->tmp = f->zr;
	f->zr = (f->zr * f->zr) - (f->zi * f->zi) + f->cr;
	f->zi = (2 * f->tmp * f->zi) + f->ci;
}

void		calc_iteration_multibrot(t_frac *f, double p)
{
	f->tmp = f->zr;
	f->zr = pow((f->zr * f->zr + f->zi * f->zi), p / 2) * \
		cos(p * atan2(f->zi, f->zr)) + f->cr;
	f->zi = pow((f->tmp * f->tmp + f->zi * f->zi), p / 2) * \
		sin(p * atan2(f->zi, f->tmp)) + f->ci;
}
