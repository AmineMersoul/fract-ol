/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:20:25 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/11 18:58:50 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTALS_H
# define __FRACTALS_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <pthread.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

typedef struct	s_point
{
	double		p1;
	double		p2;
}				t_point;

typedef struct	s_minmax
{
	double		min;
	double		max;
}				t_minmax;

typedef struct	s_view
{
	t_point		h;
	t_point		v;
}				t_view;

typedef struct	s_screen
{
	int		h;
	int		w;
}				t_screen;

typedef struct	s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct	s_rgb_d
{
	double	r;
	double	g;
	double	b;
}				t_rgb_d;

typedef struct	s_hsv
{
	double	h;
	double	s;
	double	v;
}				t_hsv;

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	int				init;
	struct s_mlx	*next;
}				t_mlx;

typedef struct	s_draw_params
{
	int		colorize;
	double	color_shift;
	int		help;
	int		density;
	int		gradient;
	int		details;
	double	scale;
	double	move;
	t_mlx	mlx;
	t_view	view_port;
	int		set;
	int		stop;
	int		m_x;
	int		m_y;
}				t_draw_params;

int				ft_deal_key(int key, void *param);
int				ft_deal_mouse(int button, int x, int y, void *param);
t_point			ft_create_point(double p1, double p2);
t_rgb			ft_create_rgb(int r, int g, int b);
t_rgb_d			ft_create_rgb_d(double r, double g, double b);
int				ft_rgb_hex(t_rgb rgb);
t_minmax		ft_create_minmax(double min, double max);
double			ft_map(double x, t_minmax in, t_minmax out);
void			ft_draw_fractals(void *param);
int				ft_deal_motion(int x, int y, void *param);
void			ft_redraw(void *param);
void			ft_draw_help(void *param);
t_hsv			ft_create_hsv(double h, double s, double v);
int				ft_hsv_hex(t_hsv hsv);
t_point			ft_get_zoom(t_draw_params *params,
t_screen screen, t_screen itr);

#endif
