// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   color.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/08/22 20:35:18 by aalhamel          #+#    #+#             */
// /*   Updated: 2022/08/23 16:59:18 by aalhamel         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "fractol.h"

// void	rg(int h, double r, double g)
// {
// 	if (h <= 60)
// 	{
// 		r = 1.0;
// 		g = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
// 	}
// 	else
// 	{
// 		r = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
// 		g = 1.0;
// 	}
// }


// void	gb(int h, double g, double b)
// {
// 	if (h <= 180)
// 	{
// 		g = 1.0;
// 		b = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
// 	}
// 	else
// 	{
// 		g = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
// 		b = 1.0;
// 	}
// }

// void	br(int h, double b, double r)
// {
// 	if (h <= 300)
// 	{
// 		b = 1.0;
// 		r = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
// 	}
// 	else
// 	{
// 		b = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
// 		r = 1.0;
// 	}
// }

// int	hue_to_rgb(int h)
// {
// 	double	r;
// 	double	g;
// 	double	b;

// 	r = 0.0;
// 	g = 0.0;
// 	b = 0.0;
// 	if (h <= 120)
// 	{
// 		rg(h, r, g)
// 	}
// 	else if (h <= 240)
// 	{
// 		if (h <= 180)
// 		{
// 			g = 1.0;
// 			b = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
// 		}
// 		else
// 		{
// 			g = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
// 			b = 1.0;
// 		}
// 	}
// 	else
// 	{
// 		if (h <= 300)
// 		{
// 			b = 1.0;
// 			r = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
// 		}
// 		else
// 		{
// 			b = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
// 			r = 1.0;
// 		}
// 	}
// 	return (0 << 24 | (((int)(r * 255))) << 16
// 		| (((int)(g * 255))) << 8
// 		| ((int)(b * 255)));
// }

// int	shifter(int color, int mod)
// {
// 	int	re;
// 	int	gr;
// 	int	bl;

// 	re = color >> 16 & 0x00ff;
// 	re = re + mod ;
// 	gr = color >> 8 & 0x0000ff;
// 	gr = gr + mod;
// 	bl = color & 0x000000ff;
// 	bl = bl + mod;
// 	color = 0x00000000;
// 	return (re <<= 16| gr << 8 | bl);
// }