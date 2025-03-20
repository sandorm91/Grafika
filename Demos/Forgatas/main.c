#include "matrix.h"
#include <stdio.h>
int main(int argc, char* argv[])
{

    float point[3];
    float vector[3];
    float angle;
    printf("Adja meg a pontot ( x.x y.y z.z ): ");
    scanf("%f %f %f", &point[0], &point[1], &point[2]);
    printf("Adja meg a vektort ( x.x y.y z.z): ");
    scanf("%f %f %f", &vector[0], &vector[1],  &vector[2]);
    printf("Adja meg a forgatási szöget: ");
    scanf("%f", &angle);
	float c[3]={0.0f,0.0f,0.0f};
    float d[3]={0.0f,0.0f,0.0f};

    move_point(point,vector,c);
    rotate_point(point,angle,d);
    printf("Eltolás: \n");
    print_row(c);
    printf("Forgatás: \n");
    print_row(d);
	return 0;
}

