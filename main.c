#include "minilibx/mlx.h"
#include <stdio.h>
#include <math.h>


typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int	get_tr(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_red(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_green(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}
int	 get_blue(int trgb)
{
	return (trgb & 0xFF);
}


void	alhai_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel/8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void	*alhai;
	int		i;
	int		j;
	int		w = 1920;
	int		h = 1080;
	void	*alhai_win;
	t_data	img;

	alhai = mlx_init();
	i = 1;
	alhai_win = mlx_new_window(alhai, w,h, "Hello alhai");
	img.img = mlx_new_image(alhai, w, h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (i  < w)
	{
		j = 0;
		while (j < h)
		{
			double x0 =  (i / (w * 1.0))* (4.0) - 2.0;
			double y0 =  (j / (h * 1.0))* (4.0) - 2.0;
		    double x = 0.0;
		    double y = 0.0;
		    int iteration = 0;
		    int max_iteration = 1000;
		    
		    while (x*x + y*y <= 2*2 && iteration < max_iteration)
		    {
		        double xtemp = x*x - y*y + x0;
		        y = 2*x*y + y0;
		        x = xtemp;
		        iteration = iteration + 1;
		    }
			alhai_mlx_pixel_put(&img,i,j++,iteration);
		    // printf("%d %f %f %f %f %d %d \n", iteration, x0,y0,x,y, i, j);
		    j++;
		}
		i++;
	}
	mlx_put_image_to_window(alhai, alhai_win, img.img, 0, 0);
	mlx_loop(alhai);
}
