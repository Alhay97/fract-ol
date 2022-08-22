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
	mix->cor.i = 1;
	int iteration = 0;
	int max_iteration = 70;
	while (mix->cor.i < W)
	{
		mix->cor.j = 0;
		while (mix->cor.j < H)
		{
			iteration = fractal(mix);
			if (iteration == max_iteration)
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

	if (!ft_strncmp(av[1],"mandelbrot",ft_strlen(av[1])))
	{
		mix.fractal = 1;
	}
	else if (!ft_strncmp(av[1],"julie",ft_strlen(av[1])))
	{
		mix.fractal = 2;
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
	mlx_loop_hook(mix.vars.mlx, loop_hook, &mix);
	mlx_loop(mix.vars.mlx);
}
