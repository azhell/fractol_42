/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:52:02 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/02/21 15:06:38 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse(int button, int x, int y, t_mx *mx)
{
	if ((button == 4 || button == 5) && mx->flag == 1)
	{
		ZOOM_X = x;
		ZOOM_Y = y;
		KEY = button;
		if (button == 4)
			ZOOM += 0.01;
		if (button == 5 && ZOOM > 1.05)
			ZOOM -= 0.01;
		mx->fract->zoom_f = ZOOM;
		mx->flag = 0;
		ft_mand_zoom(mx);
		ft_theread(mx);
	}
	return (0);
}

int		ft_mouse_upd(int x, int y, t_mx *mx)
{
	static int	x1 = 0;
	static int	y1 = 0;
	int			x2;
	int			y2;

	if ((x == x1 && y1 == y) || mx->flag == 0 || x < 0 || x > WIDTH ||
	y < 0 || y > HEIGHT)
		return (0);
	mx->flag = 0;
	x2 = x1 < x ? 1 : -1;
	y2 = y1 < y ? 1 : -1;
	x2 = x1 == x ? 0 : x2;
	y2 = y1 == y ? 0 : y2;
	mx->fract->re += x2 * (x - WIDTH / 2.5) / (WIDTH / 0.011) * 1.6;
	mx->fract->im += y2 * (y - HEIGHT / 2.5) / (HEIGHT / 0.011) * 1.6;
	x1 = x;
	y1 = y;
	ft_theread(mx);
	return (0);
}
