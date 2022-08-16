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
    else if (keycode == 126)
    {
        
    }
	return (0);
}