/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:00:04 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/02/21 15:06:47 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb	ft_setrgb(int r, int g, int b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

void	ft_set_color(t_iter *iter)
{
	iter->rgb[0] = ft_setrgb(66, 30, 15);
	iter->rgb[1] = ft_setrgb(25, 7, 26);
	iter->rgb[2] = ft_setrgb(9, 1, 47);
	iter->rgb[3] = ft_setrgb(4, 4, 73);
	iter->rgb[4] = ft_setrgb(0, 7, 100);
	iter->rgb[5] = ft_setrgb(12, 44, 138);
	iter->rgb[6] = ft_setrgb(24, 82, 177);
	iter->rgb[7] = ft_setrgb(57, 125, 209);
	iter->rgb[8] = ft_setrgb(134, 181, 229);
	iter->rgb[9] = ft_setrgb(211, 236, 248);
	iter->rgb[10] = ft_setrgb(241, 233, 191);
	iter->rgb[11] = ft_setrgb(248, 201, 95);
	iter->rgb[12] = ft_setrgb(255, 170, 0);
	iter->rgb[13] = ft_setrgb(204, 128, 0);
	iter->rgb[14] = ft_setrgb(153, 87, 0);
	iter->rgb[15] = ft_setrgb(106, 52, 3);
	iter->rgb[16] = ft_setrgb(0, 0, 0);
}
