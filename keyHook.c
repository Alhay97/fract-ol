#include "minilibx/mlx.h"
#include "fract-ol.h"

int	close(int keycode, t_mix *mix)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mix->vars.mlx, mix->vars.win);
		mlx_destroy_image(mix->vars.mlx, mix->data.img);
		exit(0);
	}
	if (keycode == 124)
		mix->cor.mo_x += 0.05 / mix->cor.a_zoom;
	else if (keycode == 123)
		mix->cor.mo_x -= 0.05 / mix->cor.a_zoom;
	else if (keycode == 126)
		mix->cor.mo_y -= 0.05 / mix->cor.a_zoom;
	else if (keycode == 125)
		mix->cor.mo_y += 0.05 / mix->cor.a_zoom;
	if (keycode == 24)
		mix->cor.a_zoom *= 2;
	if (keycode == 27)
		mix->cor.a_zoom /= 2;
	if (keycode == 34)
		mix->max_iteration += 5;
	if (keycode == 31)
		mix->max_iteration -= 5;
	return (0);
}

int mouse(int keycode, t_mix *mix)
{

}
