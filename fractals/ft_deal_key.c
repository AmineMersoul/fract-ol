/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:30:07 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/04 14:56:42 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int		ft_deal_key(int key, void *param)
{
	t_draw_params *params = (t_draw_params*)param;

	if (key == 53)
		exit(0);
	if(key == 123)
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		params->view_port.h.p1 += params->move;
		params->view_port.h.p2 += params->move;
		ft_draw_mandelbrot(params);
	}
	if(key == 124)
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		params->view_port.h.p1 -= params->move;
		params->view_port.h.p2 -= params->move;
		ft_draw_mandelbrot(params);
	}
	if(key == 125)
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		params->view_port.v.p1 -= params->move;
		params->view_port.v.p2 -= params->move;
		ft_draw_mandelbrot(params);
	}
	if(key == 126)
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		params->view_port.v.p1 += params->move;
		params->view_port.v.p2 += params->move;
		ft_draw_mandelbrot(params);
	}
	if(key == 69)
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		params->scale *= 1.1;
		params->move *= 0.9;
		ft_draw_mandelbrot(params);
	}
	if(key == 78)
	{
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		params->scale *= 0.9;
		params->move *= 1.1;
		ft_draw_mandelbrot(params);
	}
	// ft_putnbr(key);
	// ft_putstr(", ");
	return (0);
}
