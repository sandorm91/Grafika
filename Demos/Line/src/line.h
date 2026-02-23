#ifndef LINE_H
#define LINE_H

#include "color.h"

typedef struct {
    double st_x;
    double st_y;
    double end_x;
    double end_y;
    Color color;
} Line;

void set_line_data(Line* line, double st_x,double st_y, double end_x, double end_y, Color color);

#endif 

