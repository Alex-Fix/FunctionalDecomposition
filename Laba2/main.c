#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void fill_mitrix_randomly(unsigned int **matrix, int heigth, int weight, int max) {
	unsigned int seed = (unsigned int)time(NULL);
	srand(seed);
	for (int i = 0; i < heigth; i++) 
		for (int j = 0; j < weight; j++) 
			matrix[i][j] = rand() % max + 1;
}

unsigned int ** create_matrix(int row, int column) {
	unsigned int** matrix = (unsigned int **)calloc(row, sizeof(unsigned int *));
	if (matrix == NULL)
		exit(-1);

	for (int i = 0; i < row; i++)
			matrix[i] = (unsigned int*)calloc(column, sizeof(unsigned int));

	return matrix;
}

void print_matrix(unsigned int **matrix, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%u", matrix[i][j]);
			if (j != column - 1)
				printf(" ");
		}
		printf("\r\n");
	}
}

void print_vector(double *vector, int length) {
	for (int i = 0; i < length; i++)
	{
		printf("%f", vector[i]);
		if (i != length - 1)
			printf("\r\n");
	}
}

void free_matrix(unsigned int **matrix, int row) {
	for (int i = 0; i < row; i++)
		free(matrix[i]);
	free(matrix);
}

double * create_b_vector(int length) {
	double *vector = (double*)calloc(length, sizeof(double));
	if (vector == NULL)
		exit(-1);

	for (int i = 0; i < length; i++) {
		if (i + 1 & 1)
			vector[i] = pow((double)i+1.0, 2.0) / 12.0;
		else
			vector[i] = (double)i + 1.0;
	}
	return vector;
}

void free_vector(double* vector)
{
	if (vector != NULL)
		free(vector);
}

int main() {

	int n = 4;
	unsigned int **A = create_matrix(n, n);
	print_matrix(A, n, n);
	fill_mitrix_randomly(A, n, n, 100);
	print_matrix(A, n, n);

	double *b = create_b_vector(n);
	print_vector(b, n);

	free_matrix(A, n);
	free_vector(b);
	return 0;
}

