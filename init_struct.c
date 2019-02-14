/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:18:59 by naali             #+#    #+#             */
/*   Updated: 2019/02/14 18:37:31 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "includes/t_struct.h"
#include "includes/fractol.h"

void		init_struct_win(t_win *w)
{
//	w->m.nbl = 0;
	w->mlxp = mlx_init();
	w->winp = mlx_new_window(w->mlxp, WINX, WINY, "Fractol");
}

void		free_mapping(t_vertex **map, int i, int flg)
{
	if (map != NULL)
	{
		while (i >= 0)
		{
			if (map[i] != NULL)
			{
				free(map[i]);
				map[i] = NULL;
			}
			i--;
		}
		free(map);
		map = NULL;
	}
	if (flg == -1)
		exit(ERROR_LEAKS);
}

void		init_struct_img(t_win *w, t_img *img)
{
	img->imgp = mlx_new_image(w->mlxp, WINX, WINY);
	img->data = (int*)mlx_get_data_addr(img->imgp, &(img->bpp), &(img->s_l), &(img->endian));
}

void		init_angle_n_trans(t_angle *a, t_trans *t)
{
	a->alpha = 0;
	a->beta = 0;
	a->ceta = 0;
	t->tx = 0;
	t->ty = 0;
	t->tz = 0;
	t->zoom = 1;
}

void		init_mat_position(t_obj *o)
{
	o->x_mat = set_x_matrice(o->angle.alpha);
	o->y_mat = set_y_matrice(o->angle.beta);
	o->z_mat = set_z_matrice(o->angle.ceta);
	o->t_mat = set_t_matrice(o->trans.tx, o->trans.ty, o->trans.tz);
	o->screen_mat = set_zoom_matrice(o->trans.zoom);
	o->center_mat = set_t_matrice(0, 0, 0);
	o->allmat = init_matrice();
	o->allmat = mult_matrice(o->screen_mat, o->allmat);
	o->allmat = mult_matrice(o->x_mat, o->allmat);
	o->allmat = mult_matrice(o->y_mat, o->allmat);
	o->allmat = mult_matrice(o->z_mat, o->allmat);
	o->allmat = mult_matrice(o->t_mat, o->allmat);
}

void		*init_struct_obj(t_obj *o)
{
	int		i;

	i = 0;
	if ((o->map = malloc(sizeof(t_vertex*) * (WINX + 1))) == NULL)
		return (NULL);
	while (i < WINX)
	{
		if ((o->map[i] = malloc(sizeof(t_vertex) * (WINY + 1))) == NULL)
			return (NULL);
		i++;
	}
	o->map[i] = NULL;
	return (o);
}
