/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:32:47 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/11 18:59:02 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

static int		check_infinity(t_draw_params *params,
t_screen screen, t_screen itr, t_point cons)
{
	t_point f;
	t_point cal;
	int		n;

	f = ft_get_zoom(params, screen, itr);
	if (params->set)
		cons = ft_create_point(f.p1, f.p2);
	n = 0;
	while (n < params->details)
	{
		if (fabs(f.p1 * f.p1 + f.p2 * f.p2) > 16)
			break ;
		cal.p1 = f.p1 * f.p1 - f.p2 * f.p2;
		if (params->set == 2)
			cal.p2 = -2 * f.p1 * f.p2;
		else
			cal.p2 = 2 * f.p1 * f.p2;
		f.p1 = cal.p1 + cons.p1;
		if (params->set == 3)
			f.p2 = fabs(cal.p2) + cons.p2;
		else
			f.p2 = cal.p2 + cons.p2;
		n++;
	}
	return (n);
}

static int		get_color(t_draw_params *params, int n)
{
	int		color;
	t_hsv	hsv;

	color = 60;
	if (params->gradient == 0)
	{
		if (n == params->details)
			color = 255;
	}
	else
	{
		color = fabs(ft_map(n * params->color_shift,
		ft_create_minmax(0, params->details), ft_create_minmax(0, 360)));
	}
	if (params->colorize)
		hsv = ft_create_hsv(color, 80, 80);
	else
		hsv = ft_create_hsv(0, 0, color);
	return (ft_hsv_hex(hsv));
}

static void		loop(t_draw_params *params,
t_screen itr, t_screen screen, t_point cons)
{
	int		color;

	itr.h = 0;
	while (itr.h < WIN_HEIGHT)
	{
		color = get_color(params, check_infinity(params, screen, itr, cons));
		if (params->density == 1)
			params->mlx.img.data[itr.h * WIN_WIDTH + itr.w] = color;
		else
		{
			params->mlx.img.data[itr.h * WIN_WIDTH + itr.w] = color;
			params->mlx.img.data[(itr.h + 2) * WIN_WIDTH + (itr.w + 2)] = color;
		}
		itr.h += params->density;
	}
}

void			*draw_f(void *param)
{
	t_draw_params	*params;
	t_screen		screen;
	t_screen		itr;
	t_point			cons;

	params = (t_draw_params*)param;
	screen.h = WIN_HEIGHT * params->scale;
	screen.w = WIN_WIDTH * params->scale;
	itr.h = 0;
	itr.w = 0;
	cons.p1 = ft_map(params->m_x,
	ft_create_minmax(0, WIN_WIDTH), ft_create_minmax(-1, 1));
	cons.p2 = ft_map(params->m_y,
	ft_create_minmax(0, WIN_HEIGHT), ft_create_minmax(-1, 1));
	while (itr.w < WIN_WIDTH)
	{
		loop(params, itr, screen, cons);
		itr.w += params->density;
	}
	mlx_put_image_to_window(params->mlx.mlx_ptr,
	params->mlx.win_ptr, params->mlx.img.img_ptr, 0, 0);
	pthread_exit(0);
}

void			ft_draw_fractals(void *param)
{
	pthread_t tids;

	pthread_create(&tids, NULL, draw_f, param);
	pthread_join(tids, NULL);
}
