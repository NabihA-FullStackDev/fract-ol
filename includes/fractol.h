/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naali <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:16:13 by naali             #+#    #+#             */
/*   Updated: 2019/04/13 16:17:44 by naali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "t_struct.h"
# define ERROR_INPUT -1
# define ERROR_LEAKS -2
# define EXIT_ON_SUCCESS 0
# define ZPIX 4
# define WINX 800
# define WINY 600

typedef struct		s_img
{
	void			*imgp;
	int				*data;
	int				s_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_frac
{
	int				xmax;
	int				ymax;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			zoom;
	unsigned int	itmin;
	unsigned int	itmax;
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	double			tmp;
}					t_frac;

typedef	struct		s_obj
{
	t_vertex		**map;
	t_img			img;
	t_frac			fra;
	t_angle			angle;
	t_trans			trans;
	t_matrice		allmat;
	t_matrice		x_mat;
	t_matrice		y_mat;
	t_matrice		z_mat;
	t_matrice		t_mat;
	t_matrice		screen_mat;
	t_matrice		center_mat;
	void			(*f_init)(t_frac*);
	void			(*f_draw)(struct s_obj*, t_frac*);
	int				mult;
	int				num;
}					t_obj;

typedef struct		s_win
{
	void			*mlxp;
	void			*winp;
	t_img			simg;
	t_obj			*obj;
	char			*info;
}					t_win;

unsigned int	find_color(int i, int max);
unsigned int	find_color_bud(int i);
void			color_to_pix(t_img *i, int x, int y, int color);
void			*init_struct_obj(t_obj *o);
void			init_struct_win(t_win *w);
void			init_struct_img(t_win *w, t_img *img);
void			free_mapping(t_vertex **map, int i, int flg);
void			init_angle_n_trans(t_angle *a, t_trans *t);
void			init_mat_position(t_obj *o);

void			calc_crcizrzi(double x, double y, t_frac *f);
void			calc_crcizrzi_bud(double x, double y, t_frac *f);
double			calc_cr(int x, t_frac *f);
double			calc_ci(int y, t_frac *f);
void			init_mandel(t_frac *f);
void			init_julia(t_frac *f);
void			init_buddha(t_frac *f);
int				check_exist(t_frac *f);
void			calc_iteration(t_frac *f);
void			calc_iteration_multibrot(t_frac *f1, double pow);
void			fill_map(t_obj *o, int x, int y, int color);

void			julia(t_obj *o, t_frac *f);
void			multibrot(t_obj *o, t_frac *f);
void			mandelbrot(t_obj *o, t_frac *f);

#endif
