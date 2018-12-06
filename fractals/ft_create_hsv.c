/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_hsv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:31:49 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/06 17:32:38 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

t_hsv	ft_create_hsv(double h, double s, double v)
{
	t_hsv hsv;

	hsv.h = h;
	hsv.s = s;
	hsv.v = v;
	return (hsv);
}
