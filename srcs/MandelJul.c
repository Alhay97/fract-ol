/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MandelJul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:35:36 by aalhamel          #+#    #+#             */
/*   Updated: 2022/08/23 15:07:17 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int jul(t_mix *mix)
{
	t_cor coor;
	t_cor coor2;

	coor.x = (1.70 * (mix->cor.i - W / 2) / (0.365 * W * mix->cor.a_zoom) + mix->cor.mo_x);
	coor.y = (mix->cor.j - H / 2) / (0.25 * H * mix->cor.a_zoom) + mix->cor.mo_y;
	coor2.x = mix->jul_x;
	coor2.y = mix->jul_y;
	int iteration = 0;

	while (coor.x * coor.x + coor.y * coor.y <= 2*2 && iteration < mix->max_iteration)
	{
		double xtemp = coor.x * coor.x - coor.y * coor.y + coor2.x;
		coor.y = 2 * coor.x * coor.y - coor2.y;
		coor.x = xtemp;
		iteration = iteration + 1;
	}
	return (iteration);
}

int mand(t_mix *mix)
{
	t_cor coor;
	t_cor coor2;

	coor2.x = (1.70 * (mix->cor.i - W / 2) / (0.365 * W * mix->cor.a_zoom) + mix->cor.mo_x);
	coor2.y = (mix->cor.j - H / 2) / (0.25 * H * mix->cor.a_zoom) + mix->cor.mo_y;
	coor.x = 0.0;
	coor.y = 0.0;
	int iteration = 0;

	while (coor.x * coor.x + coor.y * coor.y <= 2*2 && iteration < mix->max_iteration)
	{
		double xtemp = coor.x *coor.x - coor.y * coor.y + coor2.x;
		coor.y = 2 * coor.x *coor.y + coor2.y;
		coor.x = xtemp;
		iteration = iteration + 1;
	}
	return (iteration);
}
