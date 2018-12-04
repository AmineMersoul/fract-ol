/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 10:59:41 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/04 18:24:49 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals/fractals.h"

void	create_window(void)
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
	mlx_key_hook(win_ptr, ft_deal_key, params);
	mlx_mouse_hook(win_ptr, ft_deal_mouse, params);
	ft_draw_mandelbrot(params);
	mlx_loop(mlx_ptr);
}

int		main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;

	if (argc == 1)
	{
		create_window();
	}
	else
		ft_putstr("usage : ./fractol\n");
	return (0);
}
