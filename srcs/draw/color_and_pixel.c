/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:06:18 by naali             #+#    #+#             */
/*   Updated: 2019/04/15 14:40:59 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "fractol.h"

unsigned int	find_color(int i, t_frac *f, int div)
{
	int			max;

	max = f->itmax;
	if (i > max / div && i < max)
		return ((int)abs(0xFC4400 - (0xFC4400 * i)));
	return (0);
}

void			color_to_pix(t_img *i, int x, int y, int color)
{
	if (((y * WINX) + x > 0) &&\
		(((y * WINX) + x < WINX * WINY) &&\
		((y * WINX + x) / WINX == y)))
		i->data[(y * WINX) + x] = color;
}
