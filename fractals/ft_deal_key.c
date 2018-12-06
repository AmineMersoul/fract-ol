/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:30:07 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/06 17:52:07 by amersoul         ###   ########.fr       */
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
		params->view_port.h.p1 += params->move;
		params->view_port.h.p2 += params->move;
	}
	if(key == 124)
	{
		params->view_port.h.p1 -= params->move;
		params->view_port.h.p2 -= params->move;
	}
	if(key == 125)
	{
		params->view_port.v.p1 -= params->move;
		params->view_port.v.p2 -= params->move;
	}
	if(key == 126)
	{
		params->view_port.v.p1 += params->move;
		params->view_port.v.p2 += params->move;
	}
	if(key == 69)
		params->precision += 10;

	if(key == 78)
		params->precision -= 10;

	if(key == 5)
		params->gradient = !params->gradient;

	if(key == 2)
	{
		if (params->density == 1)
			params->density = 4;
		else
			params->density = 1;
	}
	if(key == 1)
		params->stop = !params->stop;

	if(key == 0)
		params->set = !params->set;

	if(key == 122)
		params->help = !params->help;

	if(key == 8)
		params->colorize = !params->colorize;

	ft_redraw(param);
	// ft_putnbr(key);
	// ft_putstr(", ");
	return (0);
}
