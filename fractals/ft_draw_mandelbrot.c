/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:32:47 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/01 12:41:16 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_draw_mandelbrot(void *mlx_ptr, void *win_ptr)
{
    int height = 360;
	int width = 360;

	int x = 0;
	int y = 0;

	int maxiterations = 100;

	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			double a = ft_map(x, 0, width, -2, 2);
			double b = ft_map(y, 0, width, -2, 2);

			double ca = a;
			double cb = b;

			int n = 0;
			while (n < maxiterations)
			{
				double aa = a * a - b * b;
				double bb = 2 * a * b;

				a = aa + ca;
				b = bb + cb;

				if (fabs(a + b) > 16)
					break;
				n++;
			}

			int color = 200;
			if (n == maxiterations)
				color = 255;

			mlx_pixel_put(mlx_ptr, win_ptr, x, y, ft_create_rgb(color, color, color));
			y++;
		}
		x++;
	}
}
