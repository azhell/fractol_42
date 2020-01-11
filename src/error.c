/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:11:36 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/02/21 15:06:52 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int i)
{
	if (i == 0)
	{
		ft_putstr("usage: ./fractol [ 1 - 2 param ]\n");
		ft_putstr("1. Mandelbrot \n2. Julia \n3. Burningship\n");
		exit(0);
	}
	else if (i == 1)
	{
		ft_putstr("Error name param!\n");
		ft_error(0);
	}
	else if (i == 3)
	{
		ft_putstr("Not valid map\n");
		exit(3);
	}
	else if (i == 4)
	{
		ft_putstr("Error memory!\n");
		exit(3);
	}
}
