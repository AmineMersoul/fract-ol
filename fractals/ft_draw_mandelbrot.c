/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:32:47 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/04 16:15:10 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_draw_mandelbrot(void *param)
{
	t_draw_params *params = (t_draw_params*)param;
    int height = 360 * params->scale;
	int width = 360 * params->scale;

	int x = 0;
	int y = 0;

	int maxiterations = 50;

	while (x < width)
	{
		if (x > 360)
			break;
		y = 0;
		while (y < height)
		{
			if (y > 360)
				break;
			double a = ft_map(x, 0, height, params->view_port.h.p1, params->view_port.h.p2);
			double b = ft_map(y, 0, width, params->view_port.v.p1, params->view_port.v.p2);

			double ca = a;
			double cb = b;

			int n = 0;
			while (n < maxiterations)
			{
				double aa = a * a - b * b;
				double bb = 2 * a * b;

				a = aa + ca;
				b = bb + cb;

				if (fabs(a + b) > 2)
					break;
				n++;
			}

			int color = 0;
			if (params->gradient == 0)
			{
				if (n == maxiterations)
					color = 255;
			}
			else
				color = fabs(ft_map(n, 0, maxiterations, 0, 255));

			if (x > 0 && x < 359 && y > 0 && y < 359)
				mlx_pixel_put(params->mlx_ptr, params->win_ptr, x, y, ft_create_rgb(color, color, color));
			y++;
		}
		x++;
	}
}
