#include "rectangle.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	Rectangle rectangle;
	double area;
	if (argc > 1) {
		double x, y, width, height;
		sscanf(argv[1],"%lf", &x);
		sscanf(argv[2],"%lf", &y);
		sscanf(argv[3],"%lf", &width);
        sscanf(argv[4],"%lf", &height);
		set_rectangle_data(&rectangle, x, y, width, height);
	} else {
		set_rectangle_data(&rectangle, 5, 10, 8, 9);
	}
	area = calc_rectangle_area(&rectangle);
	
	printf("Rectangle area: %lf\n", area);
	
	return 0;
}
