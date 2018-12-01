/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:23:44 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/01 17:29:33 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static void	mouse_down(t_draw_params *params)
{
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	params->scale *= 0.9;
	params->move *= 1.1;
	ft_draw_mandelbrot(params);
}

static void	mouse_up(t_draw_params *params)
{
    mlx_clear_window(params->mlx_ptr, params->win_ptr);
	params->scale *= 1.1;
	params->move *= 0.9;
	ft_draw_mandelbrot(params);
}

static void	mouse_shift_down(t_draw_params *params)
{
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	params->scale *= 0.5;
	params->move *= 1.5;
	ft_draw_mandelbrot(params);
}

static void	mouse_shift_up(t_draw_params *params)
{
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	params->scale *= 1.5;
	params->move *= 0.5;
	ft_draw_mandelbrot(params);
}

int			ft_deal_mouse(int button, int x, int y, void *param)
{
	t_draw_params *params;

    x = 0;
    y = 0;

	params = (t_draw_params*)param;
	if (button == 5)
		mouse_down(params);
	if (button == 4)
		mouse_up(params);
	if (button == 7)
		mouse_shift_down(params);
	if (button == 6)
		mouse_shift_up(params);
	return (0);
}
