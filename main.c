#include "minilibx/mlx.h"

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
	void *alhai_win;
	t_data	img;

	alhai = mlx_init();
	alhai_win = mlx_new_window(alhai, 1920,1080, "Hello alhai"); //open a window
	img.img = mlx_new_image(alhai, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	alhai_mlx_pixel_put(&img, 100000, 1000000, 0x00FF01200);
	mlx_put_image_to_window(alhai,alhai_win, img.img ,0,0);
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
