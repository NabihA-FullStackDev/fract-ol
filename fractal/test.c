/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:55:42 by naali             #+#    #+#             */
/*   Updated: 2019/02/14 16:37:40 by naali            ###   ########.fr       */
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
			(void)o;
			fill_map(o, x, y, find_color(i, f->itmax, x, y));
			y++;
		}
		x++;
	}
}

/* void		mandelbrot(t_win *w) */
/* { */
/* // Creation des variables. */
/* 	double			x1, x2, y1, y2; */
/* 	double			zoom = 500; */
/* 	unsigned int	max = 300; */

/* // variables des boucles */
/* 	double			c_r; */
/* 	double			c_i; */
/* 	double			z_r; */
/* 	double			z_i; */
/* 	double			tmp; */
/* 	unsigned int	i; */

/* // Initialisation des variables */
/* 	x1 = -2.1;//-2.1 */
/* 	x2 = 0.6;//0.6 */
/* 	y1 = -1.2;//-1.2 */
/* 	y2 = 1.2;//1.2 */

/* 	for (int x = 0 ; x < WINX; x++) */
/* 	{ */
/* 		c_r = (double)((x / zoom) + x1); */
/* 		for (int y = 0; y < WINY; y++) */
/* 		{ */
/* 			c_i = (double)((y / zoom) + y1); */
/* 			z_r = 0; */
/* 			z_i = 0; */
/* 			i = 0; */
/* 			while (z_r * z_r + z_i * z_i < 4 && i < max) */
/* 			{ */
/* 				tmp = z_r; */
/* 				z_r = (z_r * z_r) - (z_i * z_i) + c_r; */
/* 				z_i = (2 * tmp * z_i) + c_i; */
/* 				i++; */
/* 			} */
/* 			color_to_pix(w, x, y, find_color(i, max, x, y)); */
/* 		} */
/* 	} */
/* } */
