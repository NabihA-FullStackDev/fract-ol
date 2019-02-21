/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:06:18 by naali             #+#    #+#             */
/*   Updated: 2019/02/21 02:18:45 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../includes/fractol.h"

unsigned int	find_color(int i, int max, int x, int y)
{
	(void)y;//a voir pour modification
	if (i >= max / 84 && i < max / 42)
		return (/* 0xB3FFFF */0x0);
	else if (i >= max / 42 && i < max / 21)
		return (/* 0x1AFFFF */0x0);
	else if (i >= max / 21 && i < max / 13)
		return (0x00B3B3);
	else if (i >= max / 13 && i < max)
		return (0x0093C5);
	else if (i == max && x > 0)
		return (0xFFFFFF);
	return (0);
}

unsigned int	find_color_bud(int i)
{
/* 	if (i > 10 && i < 100) */
/* 		return (0xFFe6b3); */
/* 	else if (i >= 100 && i < 500) */
/* 		return (0xFF66FF); */
/* 	else  */if (i >= 9999 && i < 249999)
		return (0xE600E6);
	else if (i >= 249999 && i < 499999)
		return (0x0066FF);
	else if (i >= 499999)
		return (0xFFFFFF);
	return (0);
}

void		color_to_pix(t_img *i, int x, int y, int color)
{
	if (((y * WINX) + x > 0) &&\
		(((y * WINX) + x < WINX * WINY) &&\
		((y * WINX + x) / WINX == y)))
		i->data[(y * WINX) + x] = color;
}
