#ifndef POINT_H
#define POINT_H

typedef struct {
    double x;
    double y;
    double weight;
} Point;

void set_point_data(Point* point, double x, double y);

#endif 