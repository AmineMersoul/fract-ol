/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:32:47 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/08 14:45:32 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_draw_mandelbrot(void *param)
{
	t_draw_params *params = (t_draw_params*)param;
    int height = WIN_HEIGHT * params->scale;
	int width = WIN_WIDTH * params->scale;

	int x = 0;
	int y = 0;

	double ca = ft_map(params->m_x, 0, WIN_WIDTH, -1, 1);
	double cb = ft_map(params->m_y, 0, WIN_HEIGHT, -1, 1);

	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			double a = ft_map(x, 0, height, params->view_port.h.p1, params->view_port.h.p2);
			double b = ft_map(y, 0, width, params->view_port.v.p1, params->view_port.v.p2);

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
				double bb = 2 * a * b;

				a = aa + ca;
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
				color = fabs(ft_map(n * params->color_shift, 0, params->precision, 0, 360));
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
}
