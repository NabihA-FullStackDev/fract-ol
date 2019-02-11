/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:55:42 by naali             #+#    #+#             */
/*   Updated: 2019/02/11 18:27:42 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "includes/fractol.h"

unsigned int	find_color(int i, int max, int x, int y)
{
	if (i > max / 84 && i < max / 42)
			return (0xB3FFFF);
	else if (i > max / 42 && i < max / 21)
			return (0x1AFFFF);
	else if (i > max / 21 && i < max / 13)
			return (0x00B3B3);
	return (0);
}

void		color_to_pix(t_win *w, int x, int y, int color)
{
	if (((y * WINX) + x > 0) &&\
		(((y * WINX) + x < WINX * WINY) &&\
		((y * WINX + x) / WINX == y)))
		w->simg.data[(y * WINX) + x] = color;
}

void		mandelbrot(t_win *w)
{
// Creation des variables.
	double			x1, x2, y1, y2;
	double			zoom = 500;
	unsigned int	max = 500;
	unsigned int	img_x;
	unsigned int	img_y;

// variables des boucles
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
	int				i;

	unsigned int	color1 = 2;
	unsigned int	color2 = 1;
	unsigned int	modc;

// Initialisation des variables
	x1 = -2.1;//-2.1
	x2 = 0.6;//0.6
	y1 = -1.2;//-1.2
	y2 = 1.2;//1.2
	img_x = (unsigned int)((x2 - x1) * zoom);
	img_y = (unsigned int)((y2 - y1) * zoom);

	for (int x = 0 ; x < WINX; x++)
	{
		c_r = (double)((x / zoom) + x1);
		for (int y = 0; y < WINY; y++)
		{
			c_i = (double)((y / zoom) + y1);
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < max)
			{
				tmp = z_r;
				z_r = (z_r * z_r) - (z_i * z_i) + c_r;
				z_i = (2 * tmp * z_i) + c_i;
				i++;
			}
			if (i < max)
				color_to_pix(w, x, y, find_color(i, max, x, y));
			else if (i == max && x > 0)
				color_to_pix(w, x, y, 0xFFFFFF);
		}
	}
}
