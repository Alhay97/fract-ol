#include "minilibx/mlx.h"
#include "fract-ol.h"

int main(int ac, char **av)
{
	int		i;
	int		j;
	int iteration = 0;
	int max_iteration = 70;
	t_mix 	mix;

	if (!ft_strncmp(av[1],"mandelbrot",ft_strlen(av[1])))
	{
		mand(0,0);
	}
	else if (!ft_strncmp(av[1],"julie",ft_strlen(av[1])))
	{
		jul(0,0);
	}
	else
		exit(1);
	var_init(&mix);
	mix.vars.mlx = mlx_init();
	mix.vars.win = mlx_new_window(mix.vars.mlx, W, H, "Hello world!");
	mlx_hook(mix.vars.win, 2, 1L<<0, close, &mix);
	mix.data.img = mlx_new_image(mix.vars.mlx, W, H);
	mix.data.addr = mlx_get_data_addr(mix.data.img, &mix.data.bits_per_pixel, &mix.data.line_length,
			&mix.data.endian);
	i = 1;
	while (i < W)
	{
		j = 0;
		while (j < H)
		{
			if (!ft_strncmp(av[1],"mandelbrot",ft_strlen(av[1])))
				iteration = mand(i,j);
			else if (!ft_strncmp(av[1],"julie",ft_strlen(av[1])))
				iteration = jul(i,j);
			if (iteration == max_iteration)
				alhai_mlx_pixel_put(&mix.data,i,j,0);
			else
				alhai_mlx_pixel_put(&mix.data,i,j, mix.color_change * iteration / 100);
		    j++;
		}
		i++;
	}
	mlx_put_image_to_window(mix.vars.mlx, mix.vars.win, mix.data.img, 0, 0);
	printf("%d - color ", mix.color_change);
	mlx_loop(mix.vars.mlx);
}
