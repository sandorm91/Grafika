#include "mirror.h"
#include "point.h"

#include <stdio.h>

void set_mirror_data(Mirror* mirror, double point_x, double point_y, double dimension, double d_value)
{
    set_point_data(&mirror->point, point_x, point_y);
    mirror->dimension = dimension;
    mirror->d_value = d_value;
}

Point calculate_mirrored_point(const Mirror* mirror, Point point)
{
    double m1[3][3] ={
        {1,0,0},
        {0,1,-1*mirror->d_value},
        {0,0,1}
    };
    double m2[3][3] ={
        {1,0,0},
        {0,-1,0},
        {0,0,1}
    };
    double m3[3][3] ={
        {1,0,0},
        {0,1,mirror->d_value},
        {0,0,1}
    };
    if(mirror->dimension)
    {
        m1={
            {1,0,-1*mirror->d_value},
            {0,1,0},
            {0,0,1}
        };
        m2={
            {-1,0,0},
            {0,1,0},
            {0,0,1}
        };
        m3={
            {1,0,mirror->d_value},
            {0,1,0},
            {0,0,1}
        };
    }

    Point mirrored_point;
    double combined[3][3]={{0,0,0},{0,0,0},{0,0,0}}
    set_point_data(mirrored_point, point->x,point->y);
    for( int i = 0; i<3;i++){
        for(int j = 0; i<3; i++){
            combined[i][j]=m2[i][0]*m1[0][j]+m2[i][1]*m1[1][j]+m2[i][2]*m1[2][j];
        }
    }
    for( int i = 0; i<3;i++){
        for(int j = 0; i<3; i++){
            combined[i][j]=m3[i][0]*combined[0][j]+m3[i][1]*combined[1][j]+m3[i][2]*combined[2][j];
        }
    }
    double mirrored_point_data[3]={0,0,0};
    for( int i = 0; i<3;i++){
        mirrored_point_data[i]=combined[i][0]*point->x+combined[i][1]*point->y+combined[i][2];
    }
    set_point_data(mirrored_point,mirrored_point_data[0],mirrored_point_data[1]);



    return mirrored_point;
}
