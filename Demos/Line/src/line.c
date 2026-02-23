#include "line.h"
#include "color.h"

#include <stdio.h>

void set_line_data(Line* line, double st_x,double st_y, double end_x, double end_y, Color color)
{
    line->st_x=st_x;
    line->st_y=st_y;
    line->end_x=end_x;
    line->end_y=end_y;
}