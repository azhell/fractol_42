/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:25:40 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/02/21 15:06:22 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		ft_put_pixel(t_mx *mx, t_iter iter, int it)
{
	int	i;
	int	color;

	if (iter.x < 0 || iter.x >= WIDTH || iter.y < 0 || iter.y >= HEIGHT)
		return (0);
	i = iter.x * (mx->bpp / 8) + iter.y * iter.size;
	if (it > 0)
		color = it % 16;
	else
		color = 16;
	mx->data[i] = iter.rgb[color].b;
	mx->data[++i] = iter.rgb[color].g;
	mx->data[++i] = iter.rgb[color].r;
	return (0);
}
