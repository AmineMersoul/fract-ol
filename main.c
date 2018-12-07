/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 10:59:41 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/07 18:22:30 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals/fractals.h"

void	create_window(int set)
{
	t_mlx	mlx;
	t_draw_params *params = malloc(sizeof(t_draw_params));

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx fractol");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	params->mlx = mlx;
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
	mlx_key_hook(mlx.win_ptr, ft_deal_key, params);
	mlx_mouse_hook(mlx.win_ptr, ft_deal_mouse, params);
	ft_redraw(params);
	mlx_hook(mlx.win_ptr, 6, 1L<<8, ft_deal_motion, params);
	mlx_loop(mlx.mlx_ptr);
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
