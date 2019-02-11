/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:16:13 by naali             #+#    #+#             */
/*   Updated: 2019/02/11 14:40:43 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define ZPIX 4
# define WINX 1600
# define WINY 1200
# include "t_struct.h"

typedef struct		s_sgmt
{
	t_vect			start;
	t_vect			end;
	float			xt;
	float			yt;
	int				c_start;
	int				c_end;
	int				z_start;
	int				z_end;
	int				cstep;
	double			dx;
	double			dy;
	double			error;
	int				ystep;
	int				x;
	int				y;
	int				maxx;
}					t_sgmt;

typedef struct		s_map
{
	int			fd;
	int			xmax;
	int			ymax;
	int			zmax;
	int			nbl;
	char		*line;
	char		**tbline;
	t_vertex	**tab;
	t_matrice	mat;
}					t_map;

typedef struct		s_img
{
	void		*imgp;
	int			*data;
	int			s_l;
	int			bpp;
	int			endian;
}					t_img;

typedef struct		s_win
{
	void		*mlxp;
	void		*winp;
	t_img		simg;
	t_map		m;
	t_obj		obj;
	t_sgmt		seg;
}					t_win;

void				init_map(t_win *w);
int					file_to_tab(char *path, t_map *m);
int					tablen(const char **tab);
void				free_useless(char ***tab, char **s1, int tmax);
char				**ft_pushback_str_to_tab(char ***tab, char **s1);
int					color_choice(int z);
void				print_line1(t_win *w, t_vect start, t_vect end);
void				put_color_to_pix(t_win *w, t_vertex vtx);
int					color_choice(int z);
int					deal_with_keyboard(int key, void *ptr);
void				refresh_screen(t_win *win);

#endif
