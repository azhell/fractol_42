/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:10:19 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/02/21 15:07:00 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mand_check(int x, int y)
{
	double	a;
	double	p;
	double	c;

	a = atan2l(y, x - 0.25);
	p = sqrt((pow(x - 0.25, 2) + pow(y, 2)));
	c = 0.5 - 0.5 * cos(a);
	if (p > c)
		return (1);
	else
		return (0);
}

void	ft_mandel_iter(t_mx *mx, t_iter iter, int x, int y)
{
	int		flag;
	int		i;

	i = -1;
	flag = 0;
	iter.re = MIN_RE + x * RE_FACT;
	iter.im = MAX_IM - y * IM_FACT;
	iter.zre = iter.re;
	iter.zim = iter.im;
	iter.x = x;
	iter.y = y;
	if (ft_mand_check(x, y))
		while (++i < iter.iter)
		{
			iter.zre2 = iter.zre * iter.zre;
			iter.zim2 = iter.zim * iter.zim;
			if (iter.zre2 + iter.zim2 > 4)
			{
				flag = i;
				break ;
			}
			iter.zim = (iter.zre + iter.zre) * iter.zim + iter.im;
			iter.zre = iter.zre2 - iter.zim2 + iter.re;
		}
	ft_put_pixel(mx, iter, flag);
}

void	ft_mandelbrot(void *mxx)
{
	int		x;
	int		y;
	int		yy;
	t_th	*mx;
	t_iter	iter;

	mx = (t_th*)mxx;
	iter.nthread = mx->iter;
	iter.zoom = mx->ZOOM;
	iter.iter = mx->ITER;
	iter.size = mx->mx->size;
	yy = HEIGTH_IMG * mx->j;
	ft_set_color(&iter);
	x = -1 + WIDTH_IMG * mx->i;
	while (++x < WIDTH_IMG * (mx->i + 1))
	{
		y = -1 + yy;
		while (++y < HEIGTH_IMG * (mx->j + 1))
			ft_mandel_iter(mx->mx, iter, x, y);
	}
	pthread_exit(0);
}
