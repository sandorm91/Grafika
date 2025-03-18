#include "matrix.h"

#include <stdio.h>

void init_zero_row(float row[3]) {
    for (int i = 0; i < 3; i++) {
        row[i] = 0;
    }
}

void init_zero_matrix(float matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        init_zero_row(matrix[i]);
    }
}

void move_point(const float point[3], const float vector[3], float result[3]) {
    float[3][3] matrix={
        {1,0,vector[0]},
        {0,1,vector[1]},
        {0,0,vector[2]}
    };
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += matrix[i][j] * point[j];
        }
    }
}