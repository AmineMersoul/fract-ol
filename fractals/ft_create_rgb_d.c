/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_rgb_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:30:49 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 14:55:13 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

t_rgb_d	ft_create_rgb_d(double r, double g, double b)
{
	t_rgb_d rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}
