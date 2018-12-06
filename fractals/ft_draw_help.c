/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:08:34 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/06 16:33:03 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_draw_help(void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;
	if (params->help == 0)
		return ;
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	20, 10, 0xFFFFFF, "presse 'd' to change density");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	20, 30, 0xFFFFFF, "presse 'a' to change set");
    mlx_string_put(params->mlx_ptr, params->win_ptr,
	20, 50, 0xFFFFFF, "presse 's' to stop shape change");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	420, 10, 0xFFFFFF, "move the mouse to change shape");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	420, 30, 0xFFFFFF, "scroll 'up or down' to zoom");
    mlx_string_put(params->mlx_ptr, params->win_ptr,
	420, 50, 0xFFFFFF, "presse 'arrows' to move");
}