/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:08:34 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 14:29:04 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static void	p1(t_draw_params *params, t_rgb rgb)
{
	mlx_string_put(params->mlx.mlx_ptr, params->mlx.win_ptr,
	20, 10, ft_rgb_hex(rgb), "presse 'd' to change density");
	mlx_string_put(params->mlx.mlx_ptr, params->mlx.win_ptr,
	20, 30, ft_rgb_hex(rgb), "presse 'a' to change the set");
	mlx_string_put(params->mlx.mlx_ptr, params->mlx.win_ptr,
	20, 50, ft_rgb_hex(rgb), "presse 's' to stop shape change");
	mlx_string_put(params->mlx.mlx_ptr, params->mlx.win_ptr,
	20, 70, ft_rgb_hex(rgb), "presse 'g' to change gradient");
	mlx_string_put(params->mlx.mlx_ptr, params->mlx.win_ptr,
	20, 90, ft_rgb_hex(rgb), "presse 'c' to colorize");
}

static void	p2(t_draw_params *params, t_rgb rgb)
{
	mlx_string_put(params->mlx.mlx_ptr, params->mlx.win_ptr,
	380, 10, ft_rgb_hex(rgb), "move the mouse to change shape");
	mlx_string_put(params->mlx.mlx_ptr, params->mlx.win_ptr,
	380, 30, ft_rgb_hex(rgb), "scroll 'up or down' to zoom");
	mlx_string_put(params->mlx.mlx_ptr, params->mlx.win_ptr,
	380, 50, ft_rgb_hex(rgb), "presse 'arrows' to move");
	mlx_string_put(params->mlx.mlx_ptr, params->mlx.win_ptr,
	380, 70, ft_rgb_hex(rgb), "presse 'page up or down' change colors");
	mlx_string_put(params->mlx.mlx_ptr, params->mlx.win_ptr,
	380, 90, ft_rgb_hex(rgb), "presse 'r' to reset");
}

void		ft_draw_help(void *param)
{
	t_draw_params	*params;
	t_rgb			rgb;

	params = (t_draw_params*)param;
	if (params->help == 0)
		return ;
	if (params->colorize)
		rgb = ft_create_rgb(255, 255, 255);
	else
		rgb = ft_create_rgb(0, 0, 0);
	p1(params, rgb);
	p2(params, rgb);
}
