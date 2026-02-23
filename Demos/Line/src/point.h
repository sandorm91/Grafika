#ifndef POINT_H
#define POINT_H

typedef struct {
    int x;
    int y;
} Point;

void set_point_data(Point* point, int x, int y);

#endif 