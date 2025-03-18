#ifndef MATRIX_H
#define MATRIX_H

void init_zero_row(float row[3]);

void init_zero_matrix(float matrix[3][3]);

void move_point(const float point[3], const float vector[3], float result[3]);

#endif // MATRIX_H