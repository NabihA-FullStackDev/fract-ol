/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:00:51 by naali             #+#    #+#             */
/*   Updated: 2019/04/15 14:55:37 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "fractol.h"
#include "t_struct.h"
#include "libft.h"

int				mouse_move(int x, int y, void *tmp)
{
	t_win	*w;

	w = (t_win*)tmp;
	if (x == 0)
		x = 1;
	else if (x < -350)
		x = -350;
	else if (x > 600)
		x = 600;
	if (y == 0)
		y = 1;
	else if (y < -800)
		y = -800;
	else if (y > 800)
		y = 800;
	w->xmouse = x - (WINX / 2);
	w->ymouse = y - (WINY / 2);
	w->obj->fra.cr = (double)((x - (WINX / 2)) / w->obj->fra.zoom);
	w->obj->fra.ci = (double)((y - (WINY / 2)) / w->obj->fra.zoom);
	refresh_screen(w, w->obj);
	print_info(w, w->obj);
	return (0);
}

int				get_move(void *tmp)
{
	t_win	*w;

	w = (t_win*)tmp;
	mlx_hook(w->winp, 6, 1L << 6, mouse_move, w);
	return (0);
}

int				deal_with_mouse(int key, int x, int y, void *ptr)
{
	t_win		*w;
	t_frac		*f;

	(void)x;
	(void)y;
	w = (t_win*)ptr;
	f = &(w->obj->fra);
	if (key == 4)
	{
/* 		f->x1 = f->cr - fabs(f->x1); */
/* 		f->y1 = f->ci - fabs(f->y1); */
/* 		f->x2 = f->cr + fabs(f->x2); */
/* 		f->y2 = f->ci + fabs(f->y2); */
/* 		w->obj->trans.cx = -abs(WINX - (w->xmouse + (WINX / 2))); */
/* 		w->obj->trans.cy = -abs(WINY - (w->ymouse + (WINY / 2)));; */
		f->zoom -= 20;
	}
	else if (key == 5)
	{
/* 		f->x1 = f->cr - fabs(f->x1); */
/* 		f->y1 = f->ci - fabs(f->y1); */
/* 		f->x2 = f->cr + fabs(f->x2); */
/* 		f->y2 = f->ci + fabs(f->y2); */
/* 		w->obj->trans.cx = -abs(WINX - (w->xmouse + (WINX / 2))); */
/* 		w->obj->trans.cy = -abs(WINY - (w->ymouse + (WINY / 2)));; */
		f->zoom -= 20;
	}
//		f->zoom += 20;
	refresh_screen(w, w->obj);
	print_info(w, w->obj);
	return (0);
}

int				deal_with_keyboard(int key, void *ptr)
{
	t_win		*w;

	w = (t_win*)ptr;
	if (key == 53)
	{
		mlx_destroy_image(w->mlxp, w->obj->img.imgp);
		mlx_destroy_window(w->mlxp, w->winp);
		exit(0);
	}
	if (key == 123)
		w->obj->trans.tx -= 20;
	if (key == 124)
		w->obj->trans.tx += 20;
	if (key == 125)
		w->obj->trans.ty += 20;
	if (key == 126)
		w->obj->trans.ty -= 20;
	if (key == 69)
		w->obj->mult += (w->obj->mult < 11) ? 1 : 0;
	if (key == 78)
		w->obj->mult -= (w->obj->mult > 3) ? 1 : 0;
	refresh_screen(w, w->obj);
	print_info(w, w->obj);
	return (0);
}
