/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 10:59:41 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/07 15:32:08 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals/fractals.h"

void	create_window(int set)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "mlx fractol");
	t_draw_params *params = malloc(sizeof(t_draw_params));
	params->mlx_ptr = mlx_ptr;
	params->win_ptr = win_ptr;
	params->view_port.h.p1 = -2;
	params->view_port.h.p2 = 2;
	params->view_port.v.p1 = -2;
	params->view_port.v.p2 = 2;
	params->scale = 1;
	params->move = 1;
	params->gradient = 1;
	params->precision = 50;
	params->density = 1;
	params->stop = 1;
	params->set = set;
	params->help = 0;
	params->colorize = 0;
	params->m_x = 400;
	params->m_y = 600;
	params->color_shift = 1;
	mlx_key_hook(win_ptr, ft_deal_key, params);
	mlx_mouse_hook(win_ptr, ft_deal_mouse, params);
	ft_redraw(params);
	mlx_hook(win_ptr, 6, 1L<<8, ft_deal_motion, params);
	mlx_loop(mlx_ptr);
}

void	show_usage()
{
	ft_putstr("usage : ./fractol [fractals]\n");
	ft_putstr("fractals :\n");
	ft_putstr("--> Mandelbrot\n");
	ft_putstr("--> Julia\n");
}

int		main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;

	if (argc == 2)
	{
		if (ft_strequ(argv[1], "Mandelbrot"))
			create_window(1);
		else if (ft_strequ(argv[1], "Julia"))
			create_window(0);
		else
			show_usage();
	}
	else
		show_usage();
	return (0);
}
