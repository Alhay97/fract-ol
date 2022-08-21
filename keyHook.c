#include "minilibx/mlx.h"
#include "fract-ol.h"


int	zoom(int keycode , int x, int y, t_mix *mix)
{
	if (keycode == 24)
	{
		mix->cor.a_zoom *= 2;
		mix->cor.mo_x += (x / (W * 1.0))* (4.0) - mix->cor.mo_x;
		mix->cor.mo_y += (y / (H * 1.0))* (4.0) - mix->cor.mo_y;
		printf("here");
	}
	return (0);
}

int	close(int keycode,t_mix *mix)
{
	if (keycode == 53)
	{
        mlx_destroy_window(mix->vars.mlx, mix->vars.win);
		mlx_destroy_image(mix->vars.mlx, mix->data.img);
		exit(0);
	}
	return (0);
}