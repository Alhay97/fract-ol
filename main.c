#include "minilibx/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
}
// int main(void)
// {
// 	void *alhai;
// 	void *alhai_win;
// 	// void *alhai_image;

// 	alhai = mlx_init();
// 	alhai_image = mlx_new_image(alhai,1920, 1080); //creates an image
// 	alhai_win = mlx_new_window(alhai, 1920,1080, "Hello alhai"); //open a window
// 	mlx_loop(alhai);
// }
