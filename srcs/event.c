/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:00:51 by naali             #+#    #+#             */
/*   Updated: 2019/04/22 14:43:24 by naali            ###   ########.fr       */
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
	if (x < 0)
		x = 0;
	else if (x > WINX)
		x = WINX;
	if (y < 0)
		y = 0;
	else if (y > WINY)
		y = WINY;
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
		w->obj->trans.cx = -(w->obj->fra.xmax) / 2;
		w->obj->trans.cy = -(w->obj->fra.ymax) / 2;
		f->zoom += 20;
	}
	else if (key == 5)
	{
		w->obj->trans.cx = -(w->obj->fra.xmax) / 2;
		w->obj->trans.cy = -(w->obj->fra.ymax) / 2;
		f->zoom -= 20;
	}
	if (key != 4 && key != 5)
		mouse_move(x, y, ptr);//tmp line have to be removed
	refresh_screen(w, w->obj);
	print_info(w, w->obj);
	return (0);
}

static void		reset_transpos(t_trans *t)
{
	t->tx = 0;
	t->ty = 0;
	t->tz = 0;
	t->zoom = 1;
}

int				deal_with_keyboard(int key, void *ptr)
{
	t_win		*w;

	w = (t_win*)ptr;
	if (key == 53 || key == 65307)
	{
		mlx_destroy_image(w->mlxp, w->obj->img.imgp);
		mlx_destroy_window(w->mlxp, w->winp);
		exit(0);
	}
	if (key == 123 || key == 65361)
		w->obj->trans.tx -= 20;
	if (key == 124 || key == 65363)
		w->obj->trans.tx += 20;
	if (key == 125 || key == 65364)
		w->obj->trans.ty += 20;
	if (key == 126 || key == 65362)
		w->obj->trans.ty -= 20;
	if (key == 69 || key == 65451)
		w->obj->mult += (w->obj->mult < 11) ? 1 : 0;
	if (key == 78 || key == 65453)
		w->obj->mult -= (w->obj->mult > 3) ? 1 : 0;
	if (key == 65289)
		reset_transpos(&(w->obj->trans));
	refresh_screen(w, w->obj);
	print_info(w, w->obj);
	return (0);
}
