/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:06:18 by naali             #+#    #+#             */
/*   Updated: 2019/02/28 02:24:21 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../includes/fractol.h"

unsigned int	find_color(int i, int max)
{
	if (i == max)
		return (0x042);
	else if (i % 11 == 0 && i > max / 50)
		return (0x80FFFF);
	else if (i % 7 == 0 && i > max / 50)
		return (0x1AFFFF);
	else if (i % 5 == 0 && i > max / 50)
		return (0x00B3B3);
	else if (i % 3 == 0 && i > max / 50)
		return (0x0093C5);
	return (0);
}

void		color_to_pix(t_img *i, int x, int y, int color)
{
	if (((y * WINX) + x > 0) &&\
		(((y * WINX) + x < WINX * WINY) &&\
		((y * WINX + x) / WINX == y)))
		i->data[(y * WINX) + x] = color;
}
