/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 10:59:41 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 13:55:03 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals/fractals.h"

t_draw_params	*set_params(t_mlx *mlx, int set)
{
	t_draw_params *params;

	params = malloc(sizeof(t_draw_params));
	params->mlx = *(mlx);
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
	return (params);
}

void			create_window(t_mlx *mlx, int set)
{
	t_draw_params *params;

	if (mlx->init == 1)
	{
		mlx->next = malloc(sizeof(t_mlx));
		mlx->next->mlx_ptr = mlx->mlx_ptr;
		mlx = mlx->next;
	}
	mlx->init = 1;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
	WIN_WIDTH, WIN_HEIGHT, "mlx fractol");
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr,
	&mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
	params = set_params(mlx, set);
	mlx_key_hook(mlx->win_ptr, ft_deal_key, params);
	mlx_mouse_hook(mlx->win_ptr, ft_deal_mouse, params);
	ft_redraw(params);
	mlx_hook(mlx->win_ptr, 6, 1L << 8, ft_deal_motion, params);
}

void			show_usage(void)
{
	ft_putstr("usage : ./fractol [fractals]\n");
	ft_putstr("fractals :\n");
	ft_putstr("--> Mandelbrot\n");
	ft_putstr("--> Julia\n");
	ft_putstr("--> Tricorn\n");
	ft_putstr("--> BurningShip\n");
}

void			check_set(t_mlx *mlx, char *name)
{
	if (ft_strequ(name, "Mandelbrot"))
		create_window(mlx, 1);
	else if (ft_strequ(name, "Julia"))
		create_window(mlx, 0);
	else if (ft_strequ(name, "Tricorn"))
		create_window(mlx, 2);
	else if (ft_strequ(name, "BurningShip"))
		create_window(mlx, 3);
	else
		show_usage();
}

int				main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		i;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->init = 0;
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			check_set(mlx, argv[i]);
			i++;
		}
		mlx_loop(mlx->mlx_ptr);
	}
	else
		show_usage();
	return (0);
}
