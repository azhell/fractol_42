/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:05:11 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/02/21 15:06:33 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_two_win(void *str)
{
	system((char*)str);
}

int		ft_valid_param(int ac, char **av)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	if (ac < 2 || ac > 3)
		ft_error(0);
	while (++i < ac)
		if (ft_strcmp(av[i], "Julia") == 0 ||
		ft_strcmp(av[i], "Mandelbrot") == 0 ||
		ft_strcmp(av[i], "Burningship") == 0)
			sum++;
	if (sum == ac - 1)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	int			i;
	char		*str;
	pthread_t	theread[2];

	i = 1;
	if (ft_valid_param(ac, av))
		ft_error(1);
	if (ac > 2)
	{
		str = ft_strjoin("./fractol ", av[2]);
		pthread_create(&theread[i - 1], NULL, (void*)ft_two_win, str);
		i++;
	}
	ft_start(av[1]);
	i = 1;
	while (i < ac)
		pthread_join(theread[i++], NULL);
	return (0);
}
