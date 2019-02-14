/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:55:42 by naali             #+#    #+#             */
/*   Updated: 2019/02/14 21:12:27 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../includes/t_struct.h"
#include "../includes/fractol.h"

void			mandelbrot(t_obj *o, t_frac *f)
{
	int				x;
	int				y;
	unsigned int	i;

	x = 0;
	while (x < WINX)
	{
		y = 0;
		f->cr = calc_cr(x, f);
		while (y < WINY)
		{
			i = 0;
			f->ci = calc_ci(y, f);
			while (check_exist(f) && i < f->itmax)
			{
				calc_iteration(f);
				i++;
			}
			fill_map(o, x, y, find_color(i, f->itmax, x, y));
			y++;
		}
		x++;
	}
}
