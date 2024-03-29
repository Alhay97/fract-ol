/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:35:21 by aalhamel          #+#    #+#             */
/*   Updated: 2022/08/24 18:47:43 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W 720
# define H 720

# include "minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_cor
{
	double		x;
	double		y;
	int			i;
	int			j;
	double		a_zoom;
	double		mo_x;
	double		mo_y;
}				t_cor;

typedef struct s_mix
{
	t_data		data;
	t_vars		vars;
	t_cor		cor;
	double		jul_x;
	double		jul_y;
	int			fractal;
	int			frac_color;
	int			max_iteration;
	int			color_change;
}			t_mix;

int		hue_to_rgb(int h);

void	ft_error(char *error);

size_t	ft_strlen(const char *str);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	alhai_mlx_pixel_put(t_data *data, int x, int y, int color);

void	hook(int keycode, t_mix *mix);

int		ft_hook(int keycode, t_mix *mix);

void	var_init(t_mix *mix);

int		clox(t_mix *mix);

int		shifter(int color, int mod);

int		zoom(int keycode, int x, int y, t_mix *mix);

int		jul(t_mix *mix);

int		mand(t_mix *mix);

int		mouse(int keycode, int x, int y, t_mix *mix);

int		is_invalid(char *n);

int		ft_intlen(char *number);

int		ft_power(int nb, int power);

int		ft_atoi(const char *str);

char	*ft_strchr(const char *s, int c);

double	ft_atod(char *str);

#endif
