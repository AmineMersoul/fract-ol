/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:31:28 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 14:03:15 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

double	ft_map(double x, t_minmax in, t_minmax out)
{
	return (x - in.min) * (out.max - out.min) / (in.max - in.min) + out.min;
}
