/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:20:25 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/09 17:19:01 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTALS_H
# define __FRACTALS_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

typedef struct
{
	float		p1;
	float		p2;
}				t_point;

typedef struct
{
	t_point		h;
	t_point		v;
}				t_view;

typedef struct
{
	int	r;
	int	g;
	int	b;
}				t_rgb;


typedef struct
{
	double	h;
	double	s;
	double	v;
}				t_hsv;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	int				init;
	struct s_mlx	*next;
}				t_mlx;

typedef struct
{
	int		colorize;
	double	color_shift;
	int		help;
	int		density;
	int		gradient;
	int		precision;
	float	scale;
	float	move;
	t_mlx	mlx;
	t_view	view_port;
	int		set;
	int		stop;
	int		m_x;
	int		m_y;
}				t_draw_params;

int		ft_deal_key(int key, void *param);
int		ft_deal_mouse(int button, int x, int y, void *param);
t_rgb	ft_create_rgb(int r, int g, int b);
int		ft_rgb_hex(t_rgb rgb);
double  ft_map(double x, double in_min, double in_max, double out_min, double out_max);
void	ft_draw_mandelbrot(void *param);
int		ft_deal_motion(int x, int y, void *param);
void	ft_redraw(void *param);
void	ft_draw_help(void *param);
t_hsv	ft_create_hsv(double h, double s, double v);
int		ft_hsv_hex(t_hsv hsv);

#endif
