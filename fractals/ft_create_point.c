/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:23:47 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 19:57:50 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

t_point	ft_create_point(double p1, double p2)
{
	t_point point;

	point.p1 = p1;
	point.p2 = p2;
	return (point);
}
