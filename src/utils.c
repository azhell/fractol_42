/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:59:41 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/02/21 15:06:43 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double st, double end, double interp)
{
	return (st + ((end - st) * interp));
}

void	ft_mand_zoom(t_mx *mx)
{
	double it;

	if (KEY == 4)
	{
		ZOOM_Y = HEIGHT - ZOOM_Y;
		it = 1.0 / ZOOM;
		RE = ZOOM_X / (WIDTH / (MAX_RE - MIN_RE)) + MIN_RE;
		IM = ZOOM_Y / (HEIGHT / (MAX_IM - MIN_IM)) + MIN_IM;
		MIN_RE = interpolate(RE, MIN_RE, it);
		MAX_RE = interpolate(RE, MAX_RE, it);
		MIN_IM = interpolate(IM, MIN_IM, it);
		MAX_IM = interpolate(IM, MAX_IM, it);
	}
	else if (ZOOM > 1.0)
	{
		it = 1.0 * ZOOM;
		RE = ((double)ZOOM_X / (WIDTH / (MAX_RE - MIN_RE)) + MIN_RE);
		IM = ((double)ZOOM_Y / (HEIGHT / (MAX_IM - MIN_IM)) + MIN_IM);
		MIN_RE = interpolate(RE, MIN_RE, it);
		MAX_RE = interpolate(RE, MAX_RE, it);
		MIN_IM = interpolate(IM, MIN_IM, it);
		MAX_IM = interpolate(IM, MAX_IM, it);
	}
	RE_FACT = (MAX_RE - MIN_RE) / (WIDTH);
	IM_FACT = (MAX_IM - MIN_IM) / (HEIGHT);
}
