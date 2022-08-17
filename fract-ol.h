#ifndef FRACT_OL
# define FRACT_OL

#define W 720
#define H 720


#include "minilibx/mlx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_mix
{
	t_data data;
	t_vars vars;
	int 	max_iteration;
	int		color_change;
}			t_mix;

typedef struct s_cor
{
	double		x;
	double		y;
}				t_cor;

int	hue_to_rgb(int h);

size_t	ft_strlen(const char *str);

int	ft_strncmp(const char *s1, const char *s2, size_t n);

void	alhai_mlx_pixel_put(t_data *data, int x, int y, int color);

int jul(int i, int j);

int mand(int i, int j);

int	close(int keycode, t_mix *mix);

void var_init(t_mix *mix);

int shifter(int color, int mod);

#endif
