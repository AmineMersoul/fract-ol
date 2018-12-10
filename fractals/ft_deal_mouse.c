/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:23:44 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 14:24:25 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static void	mouse_down(t_draw_params *params, int x, int y)
{
	params->view_port.h.p1 -= ft_map(x, ft_create_minmax
(0, WIN_WIDTH), ft_create_minmax(0, 0.45)) * params->move;
	params->view_port.h.p2 -= ft_map(x, ft_create_minmax
(0, WIN_WIDTH), ft_create_minmax(0, 0.45)) * params->move;
	params->view_port.v.p1 -= ft_map(y, ft_create_minmax
(0, WIN_HEIGHT), ft_create_minmax(0, 0.45)) * params->move;
	params->view_port.v.p2 -= ft_map(y, ft_create_minmax
(0, WIN_HEIGHT), ft_create_minmax(0, 0.45)) * params->move;
	params->scale *= 0.9;
	params->move *= 1.1;
	if (params->scale < 1)
	{
		params->scale = 1;
		params->move = 1;
	}
}

static void	mouse_up(t_draw_params *params, int x, int y)
{
	params->view_port.h.p1 += ft_map(x, ft_create_minmax
(0, WIN_WIDTH), ft_create_minmax(0, 0.45)) * params->move;
	params->view_port.h.p2 += ft_map(x, ft_create_minmax
(0, WIN_WIDTH), ft_create_minmax(0, 0.45)) * params->move;
	params->view_port.v.p1 += ft_map(y, ft_create_minmax
(0, WIN_HEIGHT), ft_create_minmax(0, 0.45)) * params->move;
	params->view_port.v.p2 += ft_map(y, ft_create_minmax
(0, WIN_HEIGHT), ft_create_minmax(0, 0.45)) * params->move;
	params->scale *= 1.1;
	params->move *= 0.9;
}

int			ft_deal_mouse(int button, int x, int y, void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;
	if (button == 5)
		mouse_down(params, x, y);
	if (button == 4)
		mouse_up(params, x, y);
	ft_redraw(params);
	return (0);
}
