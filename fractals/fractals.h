/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:20:25 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/01 12:47:33 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTALS_H
# define __FRACTALS_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

int		ft_deal_key(int key, void *param);
int	    ft_create_rgb(int r, int g, int b);
double  ft_map(double x, double in_min, double in_max, double out_min, double out_max);
void	ft_draw_mandelbrot(void *mlx_ptr, void *win_ptr);

#endif
