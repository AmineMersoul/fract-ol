/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hsv_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:09:52 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/06 17:31:42 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int   ft_hsv_hex(t_hsv hsv)
{
	double r = 0, g = 0, b = 0;

	if (hsv.s == 0)
	{
		r = hsv.v;
		g = hsv.v;
		b = hsv.v;
	}
	else
	{
		int i;
		double f, p, q, t;

		if (hsv.h == 360)
			hsv.h = 0;
		else
			hsv.h = hsv.h / 60;

		i = (int)trunc(hsv.h);
		f = hsv.h - i;

		p = hsv.v * (1.0 - hsv.s);
		q = hsv.v * (1.0 - (hsv.s * f));
		t = hsv.v * (1.0 - (hsv.s * (1.0 - f)));

		switch (i)
		{
            case 0:
                r = hsv.v;
                g = t;
                b = p;
                break;

            case 1:
                r = q;
                g = hsv.v;
                b = p;
                break;

            case 2:
                r = p;
                g = hsv.v;
                b = t;
                break;

            case 3:
                r = p;
                g = q;
                b = hsv.v;
                break;

            case 4:
                r = t;
                g = p;
                b = hsv.v;
                break;

            default:
                r = hsv.v;
                g = p;
                b = q;
                break;
		}
	}

	t_rgb rgb;
	rgb.r = fabs(r * 255);
	rgb.g = fabs(g * 255);
	rgb.b = fabs(b * 255);

	return ft_rgb_hex(rgb);
}