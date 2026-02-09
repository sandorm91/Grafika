#include "rectangle.h"

#include <stdio.h>

void set_rectangle_data(Rectangle* rectangle, double x, double y, double width, double height)
{
	rectangle->x = x;
	rectangle->y = y;
	rectangle->width = width;
	rectangle->height = height;
}

double calc_rectangle_area(const Rectangle* rectangle)
{
	double area = rectangle->width * rectangle->height;
	return area;
}