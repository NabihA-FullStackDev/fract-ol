/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:18:59 by naali             #+#    #+#             */
/*   Updated: 2019/02/12 17:10:13 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "includes/fractol.h"

void		init_struct_win(t_win *w)
{
	w->m.nbl = 0;
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
	img->data = (int*)mlx_get_data_addr(img->imgp, &(img->bpp), &(img->s_l, &(img->endian)));
}

static t_matrice	init_mat_position(t_obj *o)
{
	t_matrice	mtmp;

	o->x_mat = set_x_matrice(o->angle.alpha);
	o->y_mat = set_y_matrice(o->angle.beta);
	o->z_mat = set_z_matrice(o->angle.ceta);
	o->t_mat = set_t_matrice(o->trans.tx, o->trans.ty, o->trans.tz);
	o->screen_mat = set_zoom_matrice(o->trans.zoom);
	o->center_mat = set_t_matrice(w->m.xmax / -2,\
								w->m.ymax / -2, 0);
	mtmp = init_matrice();
	mtmp = mult_matrice(w->x_mat, mtmp);
	mtmp = mult_matrice(w->y_mat, mtmp);
	mtmp = mult_matrice(w->z_mat, mtmp);
	mtmp = mult_matrice(w->screen_mat, mtmp);
	mtmp = mult_matrice(w->t_mat, mtmp);
	return (mtmp);
}

void		init_struct_obj(t_win *w, t_obj *o)
{
	int		i;

	i = 0;
	if ((o->map = malloc(sizeof(t_vertex*) * (WINX + 1))) == NULL)
		return (NULL);
	while (i < WINX)
	{
		j = 0;
		if ((o->map[i] = malloc(sizeof(t_vertex) * (WINY + 1))) == NULL)
			return (NULL);
		while (j < WINY)
		{
			o->map[i][j].x = i;
			o->map[i][j].y = j;
			o->map[i][j].z = 0;
			o->map[i][j].color = 0;
			j++;
		}
		o->map[i][WINY] = NULL;
		i++;
	}
	o->map[i] = NULL;
	init_struct_img(w, &(o->img));
//	init_struct_angle(&(o->angle));
//	init_struct_angle(&(o->trans));
//	init_all_mat(o);
	return (o);
}
