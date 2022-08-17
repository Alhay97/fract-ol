#include "fract-ol.h"

int jul(int i, int j)
{
	t_cor coor;
	t_cor coor2;
	coor.x =  (i / (W * 1.0))* (4.0) - 2.0;
	coor.y =  (j / (H * 1.0))* (4.0) - 2.0;
	coor2.x = 0.0;
	coor2.y = -1.0;
	int iteration = 0;
	int max_iteration = 70;

	while (coor.x * coor.x + coor.y * coor.y <= 2*2 && iteration < max_iteration)
	{
		double xtemp = coor.x * coor.x - coor.y * coor.y + coor2.x;
		coor.y = 2 * coor.x * coor.y + coor2.y;
		coor.x = xtemp;
		iteration = iteration + 1;
	}
	return (iteration);
}

int mand(int i, int j, double move_x, double move_y)
{
	t_cor coor;
	t_cor coor2;

	coor2.x =  (i / (W * 1.0))* (4.0) - move_x;
	coor2.y =  (j / (H * 1.0))* (4.0) - move_y;
	coor.x = 0.0;
	coor.y = 0.0;
	int iteration = 0;
	int max_iteration = 70;

	while (coor.x * coor.x + coor.y * coor.y <= 2*2 && iteration < max_iteration)
	{
		double xtemp = coor.x *coor.x - coor.y * coor.y + coor2.x;
		coor.y = 2 * coor.x *coor.y + coor2.y;
		coor.x = xtemp;
		iteration = iteration + 1;
	}
	return (iteration);
}
