/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:35:34 by aalhamel          #+#    #+#             */
/*   Updated: 2022/08/23 15:24:41 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "fract-ol.h"

int	fractal(t_mix *mix)
{
	if (mix->fractal == 1)
		return (mand(mix));
	else if (mix->fractal == 2)
		return (jul(mix));
	return (0);
}

void	draw_image(t_mix *mix)
{
	int	iteration;

	mix->cor.i = 1;
	iteration = 0;
	while (mix->cor.i < W)
	{
		mix->cor.j = 0;
		while (mix->cor.j < H)
		{
			iteration = fractal(mix);
			if (iteration == mix->max_iteration)
				alhai_mlx_pixel_put(&mix->data,mix->cor.i,mix->cor.j,0);
			else
				alhai_mlx_pixel_put(&mix->data,mix->cor.i,mix->cor.j, mix->color_change * iteration / 100);
		    mix->cor.j++;
		}
		mix->cor.i++;
	}
}

int loop_hook(t_mix *mix)
{
	draw_image(mix);
	mlx_put_image_to_window(mix->vars.mlx, mix->vars.win, mix->data.img, 0, 0);
	return (0);
}

int main(int ac, char **av)
{
	t_mix 	mix;

	if (ac < 2 || ac > 4)
	{
		//error messeage for minitalk
		exit(1);
	}
	if (!ft_strncmp(av[1],"mandelbrot",ft_strlen(av[1])))
	{
		mix.fractal = 1;
	}
	else if (!ft_strncmp(av[1],"julie",ft_strlen(av[1])))
	{
		mix.fractal = 2;
		if (ac != 4)
		{	
			exit(1);
		}
		mix.jul_x = ft_atod(av[2]);
		mix.jul_y = ft_atod(av[3]);
	}
	else
		exit(1);
	mix.vars.mlx = mlx_init();
	mix.vars.win = mlx_new_window(mix.vars.mlx, W, H, "Hello world!");
	mix.data.img = mlx_new_image(mix.vars.mlx, W, H);
	mix.data.addr = mlx_get_data_addr(mix.data.img, &mix.data.bits_per_pixel, &mix.data.line_length,
			&mix.data.endian);
	var_init(&mix);
	mlx_hook(mix.vars.win, 2, 1L<<0, close, &mix);
	mlx_mouse_hook(mix.vars.win, mouse, &mix);
	mlx_loop_hook(mix.vars.mlx, loop_hook, &mix);
	mlx_loop(mix.vars.mlx);
}
