/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:23:44 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/08 15:34:52 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static void	mouse_down(t_draw_params *params)
{
	params->scale *= 0.9;
	params->move *= 1.1;
	if (params->scale < 1)
	{
		params->scale = 1;
		params->move = 1;
	}
}

static void	mouse_up(t_draw_params *params)
{
	params->scale *= 1.1;
	params->move *= 0.9;
}

int			ft_deal_mouse(int button, int x, int y, void *param)
{
	t_draw_params *params;
	params = (t_draw_params*)param;
	if (button == 5)
	{
		params->view_port.h.p1 -= ft_map(x, 0, WIN_WIDTH, 0, 0.45) * params->move;
		params->view_port.h.p2 -= ft_map(x, 0, WIN_WIDTH, 0, 0.45) * params->move;
		params->view_port.v.p1 -= ft_map(y, 0, WIN_HEIGHT, 0, 0.45) * params->move;
		params->view_port.v.p2 -= ft_map(y, 0, WIN_HEIGHT, 0, 0.45) * params->move;
		mouse_down(params);
	}
	if (button == 4)
	{
		params->view_port.h.p1 += ft_map(x, 0, WIN_WIDTH, 0, 0.45) * params->move;
		params->view_port.h.p2 += ft_map(x, 0, WIN_WIDTH, 0, 0.45) * params->move;
		params->view_port.v.p1 += ft_map(y, 0, WIN_HEIGHT, 0, 0.45) * params->move;
		params->view_port.v.p2 += ft_map(y, 0, WIN_HEIGHT, 0, 0.45) * params->move;
		mouse_up(params);
	}
	ft_redraw(params);
	return (0);
}
