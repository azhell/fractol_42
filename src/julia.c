/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:10:25 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/02/21 15:06:27 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia_iter(t_mx *mx, t_iter iter, int x, int y)
{
	int flag;
	int	i;

	i = 0;
	flag = 0;
	iter.x = x;
	iter.y = y;
	iter.newre = 1.5 * (x - iter.w / 2) / (0.5 * ZOOM * iter.w);
	iter.newim = (y - iter.h / 2) / (0.5 * ZOOM * iter.h);
	while (i < iter.iter)
	{
		iter.zre = iter.newre;
		iter.zim = iter.newim;
		iter.newre = iter.zre * iter.zre - iter.zim * iter.zim + iter.re;
		iter.newim = 2 * iter.zre * iter.zim + iter.im;
		if (iter.newre * iter.newre + iter.newim * iter.newim > 4)
		{
			flag = i;
			break ;
		}
		i++;
	}
	ft_put_pixel(mx, iter, flag);
}

void	ft_julia(void *mxx)
{
	int		x;
	int		y;
	int		yy;
	t_th	*mx;
	t_iter	iter;

	mx = (t_th*)mxx;
	iter.re = mx->mx->fract->re;
	iter.im = mx->mx->fract->im;
	iter.zoom = mx->ZOOM;
	iter.h = HEIGHT;
	iter.w = WIDTH;
	iter.iter = mx->ITER;
	iter.nthread = mx->iter;
	iter.size = mx->mx->size;
	yy = HEIGTH_IMG * mx->j;
	ft_set_color(&iter);
	x = -1 + WIDTH_IMG * mx->i;
	while (++x < WIDTH_IMG * (mx->i + 1))
	{
		y = -1 + yy;
		while (++y < HEIGTH_IMG * (mx->j + 1))
			ft_julia_iter(mx->mx, iter, x, y);
	}
	pthread_exit(0);
}
