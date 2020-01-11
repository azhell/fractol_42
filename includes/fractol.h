/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:04:57 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/01/21 17:04:58 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include <sys/wait.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 1200
# define HEIGHT 800
# define WIDTH_IMG 400
# define HEIGTH_IMG 400
# define THREAD 6

# define MAX_RE	mx->fract->max_re
# define MIN_RE	mx->fract->min_re
# define MAX_IM	mx->fract->max_im
# define MIN_IM	mx->fract->min_im
# define ITER mx->fract->iter
# define ZOOM mx->fract->zoom
# define KEY mx->fract->key
# define ZOOM_X mx->fract->zoom_x
# define ZOOM_Y mx->fract->zoom_y
# define NTR mx->fract->nthread
# define RE_FACT mx->fract->re_fact
# define IM_FACT mx->fract->im_fact
# define RE mx->fract->zoom_re
# define IM mx->fract->zoom_im
# define MOVE_X mx->fract->move_x
# define MOVE_Y mx->fract->move_y

typedef struct	s_rgb
{
	int r;
	int g;
	int b;
}				t_rgb;

typedef	struct	s_iter
{
	t_rgb		rgb[17];
	int			h;
	int			w;
	int			iter;
	int			x;
	int			y;
	int			size;
	int			nthread;
	double		zoom;
	double		re;
	double		im;
	double		zre;
	double		zre2;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		zim;
	double		zim2;
}				t_iter;

typedef	struct	s_fractol
{
	double		re;
	double		im;
	double		zoom_re;
	double		zoom_im;
	double		max_re;
	double		min_re;
	double		move_x;
	double		move_y;
	double		max_im;
	double		min_im;
	double		re_fact;
	double		im_fact;
	double		zoom;
	double		zoom_f;
	double		mx;
	double		my;
	int			nthread;
	int			i;
	int			j;
	int			iter;
	int			zoom_x;
	int			zoom_y;
	int			key;
}				t_fractol;

typedef	struct	s_mx
{
	t_fractol	*fract;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	char		*str;
	int			bpp;
	int			flag;
	int			en;
	int			size;
	int			flag_exit;
	void		(*fractol)	(void*);
}				t_mx;

typedef	struct	s_th
{
	t_mx		*mx;
	int			iter;
	int			i;
	int			j;
}				t_th;

void			ft_error(int i);
void			ft_mand_zoom(t_mx *mx);
int				ft_put_pixel(t_mx *mx, t_iter iter, int it);
int				ft_mouse_upd(int x, int y, t_mx *mx);
void			ft_mandelbrot(void *mx);
void			ft_julia(void *mx);
void			ft_set_color(t_iter *iter);
int				ft_start(char *data);
void			*ft_fractol(t_mx *mx);
void			ft_move(int key, t_mx *mx);
int				ft_key(int key, t_mx *mx);
void			ft_mandelbrot_init(t_mx *mx);
int				ft_mouse(int but, int x, int y, t_mx *mx);
double			interpolate(double st, double end, double interp);
void			ft_theread(t_mx *mx);
void			ft_burning(void *mxx);

#endif
