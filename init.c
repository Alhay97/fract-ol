/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:35:25 by aalhamel          #+#    #+#             */
/*   Updated: 2022/08/24 18:24:52 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	var_init(t_mix *mix)
{
	mix->max_iteration = 10;
	mix->color_change = 0xf31717;
	mix->cor.a_zoom = 1;
	mix->cor.mo_x = 0.01;
	mix->cor.mo_y = 0.01;
}
