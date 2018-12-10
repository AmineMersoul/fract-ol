/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redraw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:04:43 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 13:43:38 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

void	ft_redraw(void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;
	mlx_destroy_image(params->mlx.mlx_ptr, params->mlx.img.img_ptr);
	params->mlx.img.img_ptr = mlx_new_image(params->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	params->mlx.img.data = (int *)mlx_get_data_addr(params->mlx.img.img_ptr, &params->mlx.img.bpp, &params->mlx.img.size_l, &params->mlx.img.endian);
	mlx_clear_window(params->mlx.mlx_ptr, params->mlx.win_ptr);
	ft_draw_fractals(param);
	ft_draw_help(param);
}
