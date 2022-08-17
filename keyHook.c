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
    else if (keycode == 18) 
    {
		mix->color_change = 15;
		
     
    }
	else if (keycode == 19) //move down
    {
		if (mix->color_change - 50 < 0)
        	mix->color_change -= 40;
		else
			mix->color_change = 360 ;
    }
	else if (keycode == 124) //move right
    {
		
        
    }
	else if (keycode == 123) // move left
    {
        
    }

	return (0);
}