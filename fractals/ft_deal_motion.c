/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_motion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:58:48 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/06 15:47:04 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int ft_deal_motion(int x, int y, void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;
	if (params->stop)
	{
        if (x >= 0 && x <= 800 && y >= 0 && y <= 800)
        {
            mlx_clear_window(params->mlx_ptr, params->win_ptr);
            params->m_x = x;
            params->m_y = y;
            ft_draw_mandelbrot(params);
        }
	}
	return (0);
}