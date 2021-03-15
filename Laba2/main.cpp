#include <iostream>
#include <fstream>
using namespace std;

int dimention;
int** matrixA;
int** matrixA1;
int** matrixA2;
int** matrixB2;
int** matrixB1;
int** matrixC1;

double** matrixB;
double** matrixY1;
int** matrixY2;
int** matrixY3;
double** matrixC;

template<typename T>
void create_matrix(T**& matrix, int row, int column);
template<typename T>
void delete_matrix(T**& matrix, int row);
template<typename T>
void print_matrix(T**& matrix, int row, int column);
template<typename IN1, typename IN2, typename OUT>
OUT** matrix_add(IN1** matrixA, IN2** matrixB, int row, int column);
template<typename IN1, typename IN2, typename OUT>
OUT** matrix_sub(IN1** matrixA, IN2** matrixB, int row, int column);
template<typename IN1, typename IN2, typename OUT>
OUT** matrix_mul(IN1** matrixA, int rowA, int columnA, IN2** matrixB, int rowB, int columnB);
template<typename IN1, typename IN2, typename OUT>
OUT** matrix_mul_by_const(IN1** matrix, int row, int column, IN2 constant);
template<typename T>
T** matrix_transposition(T** matrix, int row, int column);
template<typename T>
void fill_matrix_zeros(T**& matrix, int row, int column);

void create_matrixes();
void fill_matrix(int**& matrix, int column, ifstream& file);
void fill_matrixes(ifstream& file);
void create_and_fill_matrixes(char* fileName);
void delete_matrixes();
void create_matrix_b(double** &matrix, int row);
void create_matrix_y2(int**& matrix);

int main(int argc, char *argv[]) {
	create_and_fill_matrixes(argv[1]);

	create_matrix_b(matrixB, dimention);
	create_matrix_y2(matrixY2);

	print_matrix<double>(matrixY2, dimention, 1);

	return 0;
}


template<typename T>
void create_matrix(T**& matrix, int row, int column) {
	matrix = new T * [row];
	for (int i = 0; i < row; i++)
		matrix[i] = new T[column];
}

template<typename T>
void delete_matrix(T**& matrix, int row) {
	for (int i = 0; i < row; i++)
		delete[] matrix[i];
	delete[] matrix;
}

template<typename T>
void print_matrix(T**& matrix, int row, int column) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

template<typename IN1, typename IN2, typename OUT>
OUT** matrix_add(IN1** matrixA, IN2** matrixB, int row, int column) {
	OUT** matrixC;
	create_matrix<OUT>(matrixC, row, column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrixC[i][j] = (OUT)(matrixA[i][j] + matrixB[i][j]);

	return matrixC;
}

template<typename IN1, typename IN2, typename OUT>
OUT** matrix_sub(IN1** matrixA, IN2** matrixB, int row, int column) {
	OUT** matrixC;
	create_matrix<OUT>(matrixC, row, column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrixC[i][j] = (OUT)(matrixA[i][j] - matrixB[i][j]);

	return matrixC;
}

template<typename IN1, typename IN2, typename OUT>
OUT** matrix_mul(IN1** matrixA, int rowA, int columnA, IN2** matrixB, int rowB, int columnB) {
	OUT** matrixC;
	create_matrix<OUT>(matrixC, rowA, columnB);
	fill_matrix_zeros<OUT>(matrixC, rowA, columnB);

	for (int i = 0; i < rowA; i++)
		for (int j = 0; j < columnB; j++)
			for (int k = 0; k < columnA; k++)
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];

	return matrixC;
}

template<typename IN1, typename IN2, typename OUT>
OUT** matrix_mul_by_const(IN1** matrix, int row, int column, IN2 constant) {
	OUT** matrixC;
	create_matrix<OUT>(matrixC, row, column);
	
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrixC[i][j] = matrix[i][j] * constant;

	return matrixC;
}

template<typename T>
T** matrix_transposition(T** matrix, int row, int column) {
	T** matrixB;
	create_matrix(matrixB, column, row);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrixB[j][i] = matrix[i][j];

	return matrixB;
}

template<typename T>
void fill_matrix_zeros(T**& matrix, int row, int column) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrix[i][j] = 0;
}

void create_matrixes() {
	create_matrix<int>(matrixA, dimention, dimention);
	create_matrix<int>(matrixA1, dimention, dimention);
	create_matrix<int>(matrixA2, dimention, dimention);
	create_matrix<int>(matrixB2, dimention, dimention);
	create_matrix<int>(matrixB1, dimention, 1);
	create_matrix<int>(matrixC1, dimention, 1);
}

void fill_matrix(int**& matrix, int column, ifstream& file) {
	for (int i = 0; i < dimention; i++)
		for (int j = 0; j < column; j++)
			file >> matrix[i][j];
}

void fill_matrixes(ifstream& file) {
	fill_matrix(matrixA, dimention, file);
	fill_matrix(matrixA1, dimention, file);
	fill_matrix(matrixA2, dimention, file);
	fill_matrix(matrixB2, dimention, file);
	fill_matrix(matrixB1, 1, file);
	fill_matrix(matrixC1, 1, file);
}

void create_and_fill_matrixes(char* fileName) {
	ifstream file;
	file.open(fileName);
	file >> dimention;

	create_matrixes();
	fill_matrixes(file);

	file.close();
}



void delete_matrixes() {
	delete_matrix<int>(matrixA, dimention);
	delete_matrix<int>(matrixA1, dimention);
	delete_matrix<int>(matrixA2, dimention);
	delete_matrix<int>(matrixB2, dimention);
	delete_matrix<int>(matrixB1, dimention);
	delete_matrix<int>(matrixC1, dimention);
	delete_matrix<double>(matrixB, dimention);
	delete_matrix<double>(matrixY1, dimention); 
	delete_matrix<double>(matrixY2, dimention);
}

void create_matrix_b(double**& matrix, int row) {
	create_matrix<double>(matrix, row, 1);
	for (int i = 0; i < row; i++)
		if (i & 1 == 1)
			matrix[i][0] = ((i+1) * (i+1)) / 12.0;
		else
			matrix[i][0] = i+1;
}

int** matrix_b1_mul_const(int**& matrixB1, int row, int constant) {
	return matrix_mul_by_const<int, int, int>(matrixB1, dimention, 1, constant);
}

int** matrix_b_mul_const_sub_matrix_c1(int**& matrixB1, int**& matrixC1) {
	return matrix_sub<int, int, int>(matrixB1, matrixC1, dimention, 1);
}

int** matrix_b_mul_const_sub_matrix_c1_mul_matrix_a(int** &matrixA, int** &matrixB1) {
	return matrix_mul<int, int, int>(matrixA, dimention, dimention, matrixB1, dimention, 1);
}

void create_matrix_y2(int**& matrix) {
	int** matrix_mul_const = matrix_b1_mul_const(matrixB1, dimention, 12);
	int** matrix_subscribe = matrix_b_mul_const_sub_matrix_c1(matrix_mul_const, matrixC1);
	matrix = matrix_mul<int, double, double>(matrixA1, dimention, dimention, matrix_subscribe, dimention, 1);
	delete_matrix(matrix_mul_const, dimention);
	delete_matrix(matrix_subscribe, dimention);
}