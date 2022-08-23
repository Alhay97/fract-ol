/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyHook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:35:28 by aalhamel          #+#    #+#             */
/*   Updated: 2022/08/23 16:38:25 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "fractol.h"

int	ft_hook(int keycode, t_mix *mix)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mix->vars.mlx, mix->vars.win);
		mlx_destroy_image(mix->vars.mlx, mix->data.img);
		exit(0);
	}
	if (keycode == 124)
		mix->cor.mo_x += 0.05 / mix->cor.a_zoom;
	else if (keycode == 123)
		mix->cor.mo_x -= 0.05 / mix->cor.a_zoom;
	else if (keycode == 126)
		mix->cor.mo_y -= 0.05 / mix->cor.a_zoom;
	else if (keycode == 125)
		mix->cor.mo_y += 0.05 / mix->cor.a_zoom;
	if (keycode == 24)
		mix->cor.a_zoom *= 2;
	if (keycode == 27)
		mix->cor.a_zoom /= 2;
	if (keycode == 34)
		mix->max_iteration += 5;
	if (keycode == 31)
		mix->max_iteration -= 5;
	return (0);
}

int	mouse(int keycode, int x, int y, t_mix *mix)
{
	printf("mouse x - %d\n", x);
	printf("mouse y - %d\n", y);
	if (keycode == 5)
	{
		mix->cor.a_zoom *= 2;
		mix->cor.mo_x += 1.70 * (mix->cor.i - W / 2)
			/ (0.365 * W * mix->cor.a_zoom);
		mix->cor.mo_y += (mix->cor.j - H / 2) / (0.25 * H * mix->cor.a_zoom);
	}
	else if (keycode == 5)
		mix->cor.a_zoom /= 2;
	return (0);
}
