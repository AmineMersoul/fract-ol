/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redraw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:04:43 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/06 16:29:03 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_redraw(void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	ft_draw_mandelbrot(param);
	ft_draw_help(param);
}
