/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:30:07 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 14:18:27 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static void	p1(int key, t_draw_params *params)
{
	if (key == 53)
		exit(0);
	if (key == 123)
	{
		params->view_port.h.p1 += params->move;
		params->view_port.h.p2 += params->move;
	}
	if (key == 124)
	{
		params->view_port.h.p1 -= params->move;
		params->view_port.h.p2 -= params->move;
	}
	if (key == 125)
	{
		params->view_port.v.p1 -= params->move;
		params->view_port.v.p2 -= params->move;
	}
	if (key == 126)
	{
		params->view_port.v.p1 += params->move;
		params->view_port.v.p2 += params->move;
	}
}

static void	p2(int key, t_draw_params *params)
{
	if (key == 69)
		params->precision += 10;
	if (key == 78)
		params->precision -= 10;
	if (key == 5)
		params->gradient = !params->gradient;
	if (key == 2)
	{
		if (params->density == 1)
			params->density = 4;
		else
			params->density = 1;
	}
	if (key == 1)
		params->stop = !params->stop;
	if (key == 0)
	{
		params->set++;
		if (params->set > 3)
			params->set = 0;
	}
	if (key == 122)
		params->help = !params->help;
	if (key == 8)
		params->colorize = !params->colorize;
}

static void	p3(int key, t_draw_params *params)
{
	if (key == 116)
	{
		params->color_shift += 0.3;
	}
	if (key == 121)
	{
		params->color_shift -= 0.3;
	}
	if (key == 15)
	{
		params->view_port.h.p1 = -2;
		params->view_port.h.p2 = 2;
		params->view_port.v.p1 = -2;
		params->view_port.v.p2 = 2;
		params->scale = 1;
		params->move = 1;
		params->m_x = 400;
		params->m_y = 600;
	}
}

int			ft_deal_key(int key, void *param)
{
	t_draw_params *params;

	params = (t_draw_params*)param;
	p1(key, params);
	p2(key, params);
	p3(key, params);
	ft_redraw(param);
	return (0);
}
