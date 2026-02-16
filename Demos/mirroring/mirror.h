#ifndef MIRROR_H
#define MIRROR_H

typedef struct {
    Point point;
    bool dimension;
    double d_value;
} Mirror;

void set_mirror_data(Mirror* mirror, double point_x, double point_y, double dimension, double d_value);

Point calculate_mirrored_point(const Mirror* mirror, Point point);

#endif 