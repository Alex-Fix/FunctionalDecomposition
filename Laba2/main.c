#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

unsigned int** create_uint_matrix(int row, int column) {
	unsigned int** matrix = (unsigned int**)calloc(row, sizeof(unsigned int*));
	if (matrix == NULL)
		exit(-1);
	for (int i = 0; i < row; i++)
	{
		matrix[i] = (unsigned int*)calloc(column, sizeof(unsigned int));
		if (matrix[i] == NULL)
			exit(-1);
	}
	return matrix;
}

unsigned int** create_int_matrix(int row, int column) {
	int** matrix = (int**)calloc(row, sizeof(int*));
	if (matrix == NULL)
		exit(-1);
	for (int i = 0; i < row; i++)
	{
		matrix[i] = (int*)calloc(column, sizeof(int));
		if (matrix[i] == NULL)
			exit(-1);
	}
	return matrix;
}

double** create_double_matrix(int row, int column) {
	double** matrix = (double**)calloc(row, sizeof(double*));
	if (matrix == NULL)
		exit(-1);
	for (int i = 0; i < row; i++)
	{
		matrix[i] = (double*)calloc(column, sizeof(double));
		if (matrix[i] == NULL)
			exit(-1);
	}
	return matrix;
}

unsigned int** fill_uint_matrix_randomly(unsigned int** matrix, int row, int column, int max) {
	unsigned int seed = rand();
	srand(seed);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] = rand() % max + 1;
	return matrix;
}

double** fill_b_matrix(double** b, int row) {
	for (int i = 0; i < row; i++)
	{
		if (i + 1 & 1)
			b[i][0] = (double)i+1.0;
		else
			b[i][0] = pow((double)i+1.0, 2.0) / 12.0;
	}
	return b;
}

void print_double_matrix(double** matrix, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%lf", matrix[i][j]);
			if (i != row - 1)
				printf("\r\n");
		}
		printf("\r\n");
	}
}

void print_uint_matrix(unsigned int** matrix, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d", matrix[i][j]);
			if (i != row - 1)
				printf("\r\n");
		}
		printf("\r\n");
	}
}

void free_double_matrix(double** matrix, int row) {
	for (int i = 0; i < row; i++)
		free(matrix[i]);
	free(matrix);
}

void free_uint_matrix(unsigned int** matrix, int row) {
	for (int i = 0; i < row; i++)
		free(matrix[i]);
	free(matrix);
}

int** sub_uint_matrix(unsigned int** left, unsigned int** right, int row, int column) {
	int** result = create_int_matrix(row, column);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			result[i][j] = left[i][j] - right[i][j];
	return result;
}

int** mul_int_matrix_by_int_const(int** matrix, int constant, int row, int column) {
	int** result = create_int_matrix(row, column);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			result[i][j] = matrix[i][j] - constant;
	return result;
}



int main() {
	int n = 4;

	unsigned int **A = create_uint_matrix(n, n);
	double** b = create_double_matrix(n, 1);
	unsigned int** A1 = create_uint_matrix(n, n);
	unsigned int** b1 = create_uint_matrix(n, 1);
	unsigned int** c1 = create_uint_matrix(n, 1);

	A = fill_uint_matrix_randomly(A, n, n, 100);
	b = fill_b_matrix(b, n);
	A1 = fill_uint_matrix_randomly(A1, n, n, 100);
	b1 = fill_uint_matrix_randomly(b1, n, 1, 100);
	c1 = fill_uint_matrix_randomly(c1, n, 1, 100);

	print_uint_matrix(A, n, n);
	print_double_matrix(b, n, 1);
	print_uint_matrix(A1, n, n);
	print_uint_matrix(b1, n, 1);
	print_uint_matrix(c1, n, 1);

	free_uint_matrix(A, n);
	free_double_matrix(b, n);
	free_uint_matrix(A1, n);
	free_uint_matrix(b1, n);
	free_uint_matrix(c1, n);

	return 0;
}

