#include "minilibx/mlx.h"
#include <math.h>


typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


void	alhai_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel/8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void *alhai;
	int i;
	int j;
	int k;
	int a;
	void *alhai_win;
	t_data	img;

	alhai = mlx_init();
	i = 1;
	j = 1;
	alhai_win = mlx_new_window(alhai, 1920,1080, "Hello alhai"); //open a window
	img.img = mlx_new_image(alhai, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);


	int b = 0;
	int w = 0;
	while(b < 1000)
	{
		w = 0;
		while(w < 1000)
			alhai_mlx_pixel_put(&img, b, w++, 0x00FFFF66);
		b++;
	} 
	i = 1;
	j = 1;
	while(i < 1000 && j< 1000)
		alhai_mlx_pixel_put(&img, i++, j++, 0x0066FF99);
	k = 1;
	b = 1000;
	while (k > 0 && b > 0)
		alhai_mlx_pixel_put(&img, k++,b--, 0x003366FF);
	a = 0;
	while (a < 1000)
		alhai_mlx_pixel_put(&img,a++,1000,0x00FFFFFF);

	i = 1000;
	while (i > 0)
		alhai_mlx_pixel_put(&img, 1000, i--,0x00999900);
	j = 1000;
	while (j > 0)
		alhai_mlx_pixel_put(&img, j--, 1,0x0066FF99);
	a = 1000;		

	double x = 0;
	double y = 0;
	while (x < 100)
	{
		y = sqrt(pow(100, 2) -pow(x, 2));
		alhai_mlx_pixel_put(&img, 500 + x, 500 + y, 0x00FFCC00);
		alhai_mlx_pixel_put(&img, 500 - x, 500 - y, 0x0099FFFF);
		alhai_mlx_pixel_put(&img, 500 - x, 500 + y, 0x006666FF);
		alhai_mlx_pixel_put(&img, 500 + x, 500 - y, 0x00999900);
		x++;
	}


	mlx_put_image_to_window(alhai, alhai_win, img.img, 0, 0);
	mlx_loop(alhai);
}
// int main(void)
// {
// 	void *alhai;
// 	void *alhai_win;
// void *alhai_image;

// 	alhai = mlx_init();
// 	alhai_image = mlx_new_image(alhai,1920, 1080); //creates an image
// 	alhai_win = mlx_new_window(alhai, 1920,1080, "Hello alhai"); //open a window
// 	mlx_loop(alhai);
// }
