
#include "matrix.h"

int main() {
    float point[3];
    float vector[3]
    float result[3];
    printf("Adja meg a pontot: x.x y.y z.z\n");
    scanf("%f %f %f", &point[0], &point[1], &point[2]);
    printf("Adja meg a vektort: x.x y.y z.z\n");
    scanf("%f %f %f", &vector[0], &vector[1], &vector[2]);
    init_zero_row(result);
    move_point(point, vector, result);
    printf("Az eltolt pont: %f %f %f\n", result[0], result[1], result[2]);
    return 0;
}