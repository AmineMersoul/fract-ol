/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 10:59:41 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/01 12:48:14 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals/fractals.h"

void	create_window(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 360, 360, "mlx fractol");
	mlx_key_hook(win_ptr, ft_deal_key, 0);
	//mlx_mouse_hook(win_ptr, ft_deal_mouse, params);
	ft_draw_mandelbrot(mlx_ptr, win_ptr);
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
