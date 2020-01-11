/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalytvyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:42:19 by yalytvyn          #+#    #+#             */
/*   Updated: 2019/02/21 15:07:06 by yalytvyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_fractol(t_mx *mx)
{
	void	(*fractol)	(void*);

	if (ft_strcmp(mx->str, "Mandelbrot") == 0)
		fractol = ft_mandelbrot;
	else if (ft_strcmp(mx->str, "Burningship") == 0)
		fractol = ft_burning;
	else
		fractol = ft_julia;
	return (fractol);
}

void	ft_malloc(t_mx *mx)
{
	if (!(mx->img = mlx_new_image(mx->mlx, WIDTH, HEIGHT)))
		ft_error(4);
	if (!(mx->data = mlx_get_data_addr(mx->img, &mx->bpp, &mx->size, &mx->en)))
		ft_error(4);
}

void	ft_theread(t_mx *mx)
{
	pthread_t	th[6];
	t_th		mxx[6];
	int			i;
	int			j;
	int			count;

	i = -1;
	count = -1;
	mx->fractol = ft_fractol(mx);
	ft_malloc(mx);
	while (++i < 3 && (j = -1))
		while (++j < 2)
		{
			mxx[++count].mx = mx;
			mxx[count].iter = count;
			mxx[count].i = i;
			mxx[count].j = j;
			pthread_create(&th[count], NULL, (void*)mx->fractol, &mxx[count]);
		}
	count = 0;
	while (count < THREAD)
		pthread_join(th[count++], NULL);
	mlx_put_image_to_window(mx->mlx, mx->win, mx->img, 0, 0);
	mlx_destroy_image(mx->mlx, mx->img);
	mx->flag = 1;
}

void	ft_init(t_mx *mx)
{
	int		i;

	i = 0;
	MAX_RE = 1.0;
	MIN_RE = -2.0;
	MAX_IM = 1.2;
	MIN_IM = -1.2;
	mx->flag_exit = 0;
	if (mx->str[0] == 'B')
	{
		MAX_RE = 2.0;
		MIN_RE = -2.0;
		MAX_IM = 2.0;
		MIN_IM = -2.0;
	}
	ZOOM = 1.0;
	mx->fract->re = -0.8;
	mx->fract->im = 0.156;
	mx->flag = 0;
	ITER = 256;
	RE_FACT = (MAX_RE - MIN_RE) / (WIDTH);
	IM_FACT = (MAX_IM - MIN_IM) / (HEIGHT);
}

int		ft_start(char *str)
{
	t_mx		*mx;
	t_fractol	*fractol;

	if (!(mx = (t_mx*)ft_memalloc(sizeof(t_mx))))
		ft_error(4);
	if (!(fractol = (t_fractol*)ft_memalloc(sizeof(t_fractol))))
		ft_error(4);
	mx->str = str;
	mx->mlx = mlx_init();
	mx->win = mlx_new_window(mx->mlx, WIDTH, HEIGHT, mx->str);
	mx->fract = fractol;
	ft_init(mx);
	ft_theread(mx);
	mlx_hook(mx->win, 2, 0, ft_key, mx);
	mlx_hook(mx->win, 4, 7, ft_mouse, mx);
	if (mx->str[0] == 'J')
		mlx_hook(mx->win, 6, 64, ft_mouse_upd, mx);
	mlx_loop(mx->mlx);
	return (3);
}
