#include "fract-ol.h"

// void	alhai_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel/8));
	// *(unsigned int*)dst = color;
// }

// int main(int ac, char **av)
// {
// 	void	*alhai;
// 	int		i;
// 	int		j;
// 	void	*alhai_win;
// 	int w = 1080;
// 	int h = 1080;
// 	t_data	img;
// 	int iteration = 0;
// 	int max_iteration = 70;

// 	if (!ft_strncmp(av[1],"mandelbrot",ft_strlen(av[1])))
// 	{
// 		mand(0,0);
// 	}
// 	else if (!ft_strncmp(av[1],"julie",ft_strlen(av[1])))
// 	{
// 		jul(0,0);
// 	}

// 	else
// 		exit(1);

// 	alhai = mlx_init(); // same as mlx in document
// 	i = 1;
// 	alhai_win = mlx_new_window(alhai, w,h, "Hello alhai"); // same as win in document
// 	mlx_hook(alhai_win,2,1L<<0,close,NULL);

// 	img.img = mlx_new_image(alhai, w, h);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 			&img.endian);

// 	while (i  < w)
// 	{
// 		j = 0;
// 		while (j < h)
// 		{
// 			if (!ft_strncmp(av[1],"mandelbrot",ft_strlen(av[1])))
// 				iteration = mand(i,j);
// 			else if (!ft_strncmp(av[1],"julie",ft_strlen(av[1])))
// 				iteration = jul(i,j);
// 			if (iteration == max_iteration)
// 				alhai_mlx_pixel_put(&img,i,j++,0);
// 			else
// 				alhai_mlx_pixel_put(&img,i,j++,hue_to_rgb(((double)iteration/max_iteration)*360));
// 		    j++;
// 		}
// 		i++;
// 	}

// 	mlx_put_image_to_window(alhai, alhai_win, img.img, 0, 0);
// 	mlx_loop(alhai);
// }
