/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:15:18 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/02/21 15:06:56 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(int key, t_mx *mx)
{
	if (key == 126)
	{
		MAX_IM += (MAX_IM - MIN_IM) / 100;
		MIN_IM -= (MAX_IM - MIN_IM) / 100;
	}
	else if (key == 125)
	{
		MAX_IM -= (MAX_IM - MIN_IM) / 100;
		MIN_IM += (MAX_IM - MIN_IM) / 100;
	}
	else if (key == 123)
	{
		MAX_RE += (MAX_RE - MIN_RE) / 100;
		MIN_RE -= (MAX_RE - MIN_RE) / 100;
	}
	else if (key == 124)
	{
		MAX_RE -= (MAX_RE - MIN_RE) / 100;
		MIN_RE += (MAX_RE - MIN_RE) / 100;
	}
}

int		ft_key(int key, t_mx *mx)
{
	if (key == 126 || key == 125 || key == 123 || key == 124)
	{
		ft_move(key, mx);
		ft_theread(mx);
	}
	if (key == 53)
		exit(3);
	if (key == 78 || key == 69)
	{
		if (key == 69 && ITER < 1000)
			ITER += 10;
		else if (key == 78 && ITER > 10)
			ITER -= 10;
		ft_putstr("ITER: ");
		ft_putnbr(ITER);
		ft_putstr("\n");
		ft_theread(mx);
	}
	return (0);
}
