#include "minilibx/mlx.h"
#include "fract-ol.h"

int	close(int keycode, t_vars *vars)
{
	if (keycode == 53)
        mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int main(int ac, char **av)
{
	int		i;
	int		j;
	int w = 1080;
	int h = 1080;
	t_data	img;
	int iteration = 0;
	int max_iteration = 70;
	t_vars	vars;

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
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, w, h, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	img.img = mlx_new_image(vars.mlx, w, h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = 1;
	while (i < w)
	{
		j = 0;
		while (j < h)
		{
			if (!ft_strncmp(av[1],"mandelbrot",ft_strlen(av[1])))
				iteration = mand(i,j);
			else if (!ft_strncmp(av[1],"julie",ft_strlen(av[1])))
				iteration = jul(i,j);
			if (iteration == max_iteration)
				alhai_mlx_pixel_put(&img,i,j++,0);
			else
				alhai_mlx_pixel_put(&img,i,j++,hue_to_rgb(((double)iteration/max_iteration)*360));
		    j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
