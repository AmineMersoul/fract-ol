/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:32:47 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 15:05:33 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	*draw_f(void *param)
{
	t_draw_params	*params;
    int				height;
	int				width;
	int				x;
	int				y;
	double			ca;
	double			cb;

	params = (t_draw_params*)param;
	height = WIN_HEIGHT * params->scale;
	width = WIN_WIDTH * params->scale;
	x = 0;
	y = 0;
	ca = ft_map(params->m_x, ft_create_minmax(0, WIN_WIDTH), ft_create_minmax(-1, 1));
	cb = ft_map(params->m_y, ft_create_minmax(0, WIN_HEIGHT), ft_create_minmax(-1, 1));
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			double a = ft_map(x, ft_create_minmax(0, height),ft_create_minmax(params->view_port.h.p1, params->view_port.h.p2));
			double b = ft_map(y, ft_create_minmax(0, width),ft_create_minmax(params->view_port.v.p1, params->view_port.v.p2));
			if (params->set)
			{
				ca = a;
				cb = b;
			}
			int n = 0;
			while (n < params->precision)
			{
				if (fabs(a*a + b*b) > 16)
					break;

				double aa = a * a - b * b;
				double bb;
				if (params->set == 2)
					bb = -2 * a * b;
				else
					bb = 2 * a * b;

				a = aa + ca;
				if (params->set == 3)
					b = fabs(bb) + cb;
				else
					b = bb + cb;

				n++;
			}
			int color = 60;
			if (params->gradient == 0)
			{
				if (n == params->precision)
					color = 255;
			}
			else
			{
				color = fabs(ft_map(n * params->color_shift, ft_create_minmax(0, params->precision), ft_create_minmax(0, 360)));
			}
			t_hsv hsv;
			if (params->colorize)
				hsv = ft_create_hsv(color, 80, 80);
			else
				hsv = ft_create_hsv(0, 0, color);
			if (params->density == 1)
				params->mlx.img.data[y * WIN_WIDTH + x] = ft_hsv_hex(hsv);
			else
			{
				params->mlx.img.data[y * WIN_WIDTH + x] = ft_hsv_hex(hsv);
				params->mlx.img.data[(y + 2) * WIN_WIDTH + (x + 2)] = ft_hsv_hex(hsv);
			}
			y += params->density;
		}
		x += params->density;
	}
	mlx_put_image_to_window(params->mlx.mlx_ptr, params->mlx.win_ptr, params->mlx.img.img_ptr, 0, 0);
	pthread_exit(0);
}

void	ft_draw_fractals(void *param)
{
	pthread_t tids;

	pthread_create(&tids, NULL, draw_f, param);
	pthread_join(tids, NULL);
}
