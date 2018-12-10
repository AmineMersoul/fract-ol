/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hsv_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:09:52 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 14:57:35 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static void	p1(t_hsv hsv, double *r, double *g, double *b)
{
	int		i;
	double	f;
	double	p;
	double	q;
	double	t;

	i = (int)trunc(hsv.h);
	f = hsv.h - i;
	p = hsv.v * (1.0 - hsv.s);
	q = hsv.v * (1.0 - (hsv.s * f));
	t = hsv.v * (1.0 - (hsv.s * (1.0 - f)));
	if (i == 0)
	{
		*r = hsv.v;
		*g = t;
		*b = p;
	}
	if (i == 1)
	{
		*r = q;
		*g = hsv.v;
		*b = p;
	}
}

static void	p2(t_hsv hsv, double *r, double *g, double *b)
{
	int		i;
	double	f;
	double	p;
	double	q;
	double	t;

	i = (int)trunc(hsv.h);
	f = hsv.h - i;
	p = hsv.v * (1.0 - hsv.s);
	q = hsv.v * (1.0 - (hsv.s * f));
	t = hsv.v * (1.0 - (hsv.s * (1.0 - f)));
	if (i == 2)
	{
		*r = p;
		*g = hsv.v;
		*b = t;
	}
	if (i == 3)
	{
		*r = p;
		*g = q;
		*b = hsv.v;
	}
}

static void	p3(t_hsv hsv, double *r, double *g, double *b)
{
	int		i;
	double	f;
	double	p;
	double	q;
	double	t;

	i = (int)trunc(hsv.h);
	f = hsv.h - i;
	p = hsv.v * (1.0 - hsv.s);
	q = hsv.v * (1.0 - (hsv.s * f));
	t = hsv.v * (1.0 - (hsv.s * (1.0 - f)));
	if (i == 4)
	{
		*r = t;
		*g = p;
		*b = hsv.v;
	}
	if (i < 0 || i > 4)
	{
		*r = hsv.v;
		*g = p;
		*b = q;
	}
}

int			ft_hsv_hex(t_hsv hsv)
{
	t_rgb	rgb;
	t_rgb_d	rgb_d;

	rgb_d = ft_create_rgb_d(0, 0, 0);
	if (hsv.s == 0)
		rgb_d = ft_create_rgb_d(hsv.v, hsv.v, hsv.v);
	else
	{
		if (hsv.h == 360)
			hsv.h = 0;
		else
			hsv.h = hsv.h / 60;
		p1(hsv, &rgb_d.r, &rgb_d.g, &rgb_d.b);
		p2(hsv, &rgb_d.r, &rgb_d.g, &rgb_d.b);
		p3(hsv, &rgb_d.r, &rgb_d.g, &rgb_d.b);
	}
	rgb.r = fabs(rgb_d.r * 255);
	rgb.g = fabs(rgb_d.g * 255);
	rgb.b = fabs(rgb_d.b * 255);
	return (ft_rgb_hex(rgb));
}
