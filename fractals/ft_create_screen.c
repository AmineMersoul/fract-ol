/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:06:52 by amersoul          #+#    #+#             */
/*   Updated: 2018/12/10 15:08:03 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractals.h"

t_screen	ft_create_screen(int h, int w)
{
	t_screen screen;

	screen.h = h;
	screen.w = w;
	return (screen);
}
