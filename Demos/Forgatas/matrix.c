#include "matrix.h"

#include <stdio.h>
#include <math.h>



void print_row(const float matrix[3])
{
    int i;

    for (i = 0; i < 3; ++i) {
        
        printf("%4.4f ", matrix[i]);
        printf("\n");
    }
}
void rotate_point(const float p[3], const float ang,float c[3])
{
    int i;
    int j;
    
	float a[3][3] = {
        { cos(ang*3.14/180), -sin(ang*3.14/180),  0.0f},
        { sin(ang*3.14/180), cos(ang*3.14/180),  0.0f},
        { 0.0f,  0.0f, 1.0f}
    };
    /*printf(" %4.4f", ang);
    printf("\n");
    printf(" %4.4f", cos(ang*3.14/180));
    printf("\n");
    print_row(a[0]);
    printf("\n");
    print_row(a[1]);
    printf("\n");
    print_row(a[2]);
    printf("\n");
    print_row(c);*/
	float b[3]={p[0],p[1],p[2]};
    
    for(i=0;i<3;i++){
        for (j = 0; j < 3; ++j) {
            c[i]=c[i]+a[i][j]*b[j];
        }
    }
}
void move_point(const float p[3], const float v[3],float c[3])
{
    int i;
    int j;
    
	float a[3][3] = {
        { 1.0f, 0.0f,  v[0]},
        { 0.0f, 1.0f,  v[1]},
        { 0.0f,  0.0f, v[2]}
    };
	float b[3]={p[0],p[1],p[2]};
    
    for(i=0;i<3;i++){
        for (j = 0; j < 3; ++j) {
            c[i]=c[i]+a[i][j]*b[j];
        }
    }
}

