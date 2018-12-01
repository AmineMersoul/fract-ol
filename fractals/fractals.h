/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:20:25 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/01 17:26:52 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTALS_H
# define __FRACTALS_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

typedef struct
{
	float		x;
	float		y;
}				t_point;

typedef struct
{
	t_point		p1;
	t_point		p2;
}				t_line;

typedef struct
{
	// int			colorize;
	// int			view;
	// int			help;
	float		scale;
	float		move;
	void		*mlx_ptr;
	void		*win_ptr;
	t_line	line;
}				t_draw_params;

int		ft_deal_key(int key, void *param);
int		ft_deal_mouse(int button, int x, int y, void *param);
int	    ft_create_rgb(int r, int g, int b);
double  ft_map(double x, double in_min, double in_max, double out_min, double out_max);
void	ft_draw_mandelbrot(void *param);

#endif
