/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:56:40 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 20:06:36 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

t_point	ft_get_zoom(t_draw_params *params,
t_screen screen, t_screen itr)
{
	t_point f;

	f.p1 = ft_map(itr.w, ft_create_minmax(0, screen.h),
	ft_create_minmax(params->view_port.h.p1, params->view_port.h.p2));
	f.p2 = ft_map(itr.h, ft_create_minmax(0, screen.w),
	ft_create_minmax(params->view_port.v.p1, params->view_port.v.p2));
	return (f);
}
