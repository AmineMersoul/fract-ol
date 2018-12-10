/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_minmax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:04:40 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 14:12:10 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

t_minmax	ft_create_minmax(double min, double max)
{
	t_minmax minmax;

	minmax.min = min;
	minmax.max = max;
	return (minmax);
}
