#ifndef COLOR_H
#define COLOR_H

#include "color.h"

typedef struct {
    int red;
    int green;
    int blue;
} Color;


void set_color_data(Color* color, int red, int green, int blue);

#endif 