#include "fract-ol.h"

int jul(int i, int j)
{
	int w = 1080;
	int h = 1080;
	double x =  (i / (w * 1.0))* (4.0) - 2.0;
	double y =  (j / (h * 1.0))* (4.0) - 2.0;
	double x0 = 0.0;
	double y0 = -1.0;
	int iteration = 0;
	int max_iteration = 70;

	while (x*x + y*y <= 2*2 && iteration < max_iteration)
	{
		double xtemp = x*x - y*y + x0;
		y = 2*x*y + y0;
		x = xtemp;
		iteration = iteration + 1;
	}
	return (iteration);
}

int mand(int i, int j)
{
	int w = 1080;
	int h = 1080;
	double x0 =  (i / (w * 1.0))* (4.0) - 2.0;
	double y0 =  (j / (h * 1.0))* (4.0) - 2.0;
	double x = 0.0;
	double y = 0.0;
	int iteration = 0;
	int max_iteration = 70;

	while (x*x + y*y <= 2*2 && iteration < max_iteration)
	{
		double xtemp = x*x - y*y + x0;
		y = 2*x*y + y0;
		x = xtemp;
		iteration = iteration + 1;
	}
	return (iteration);
}
