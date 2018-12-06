/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:24:52 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/06 17:25:02 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

int	ft_rgb_hex(t_rgb rgb)
{
	return ((rgb.r & 0xff) << 16) +
	((rgb.g & 0xff) << 8) + (rgb.b & 0xff);
}
