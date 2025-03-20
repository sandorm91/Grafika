#ifndef MATRIX_H
#define MATRIX_H


/**
 * Print the elements of the row.
 */
void print_row(const float matrix[3]);


/**
 * Move the point with the vector.
 */
void rotate_point(const float p[3], const float ang,float c[3]);
/**
 * Move the point with the vector.
 */
void move_point(const float p[3], const float v[3],float c[3]);



#endif // MATRIX_H

