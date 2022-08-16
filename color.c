#include "fract-ol.h"

int	hue_to_rgb(int h)
{
	double	r;
	double	g;
	double	b;

	r = 0.0;
	g = 0.0;
	b = 0.0;
	if (h <= 120)
	{
		if (h <= 60)
		{
			r = 1.0;
			g = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
		}
		else
		{
			r = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
			g = 1.0;
		}
	}
	else if (h <= 240)
	{
		if (h <= 180)
		{
			g = 1.0;
			b = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
		}
		else
		{
			g = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
			b = 1.0;
		}
	}
	else
	{
		if (h <= 300)
		{
			b = 1.0;
			r = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
		}
		else
		{
			b = 1.0 - fabs(fmod(h / 60.0, 2) - 1.0);
			r = 1.0;
		}
	}
	return (0 << 24 | (((int)(r * 255))) << 16
		| (((int)(g * 255))) << 8
		| ((int)(b * 255)));
}
