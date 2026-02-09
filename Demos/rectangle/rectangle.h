#ifndef RECTANGLE_H
#define RECTANGLE_H

typedef struct {
	double x;
	double y;
	double width;
	double height;
} Rectangle;

void set_rectangle_data(Rectangle* rect, double x, double y, double width, double height);
double calc_rectangle_area(const Rectangle* rect);

#endif // RECTANGLE_H