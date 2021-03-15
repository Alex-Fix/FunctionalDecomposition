#include <iostream>
#include <fstream>
using namespace std;

// input data
int dimention;
int** matrix_A;
int** matrix_A1;
int** matrix_A2;
int** matrix_B2;
int** matrix_B1;
int** matrix_C1;

// create by variants
double** matrix_B;
double** matrix_Y1;
double** matrix_Y2;
double** matrix_Y3;
double** matrix_C2;

// temporary data
double** matrix_temp1; // 12 * b1
double** matrix_temp2; // 12 * b1 - c1
double** matrix_temp3; // B2 - C2
int** matrix_temp4; // Y3^2

// prototypes generics
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

// prototype functions
void create_input_matrixes();
void fill_matrix(int**& matrix, int column, ifstream& file);
void fill_matrixes(ifstream& file);
void create_and_fill_input_matrixes(char* fileName);
void delete_matrixes();
void create_matrix_b();
void create_matrix_y1();
void create_matrix_y2();
void create_matrix_temp1();
void create_matrix_temp2();
void create_matrix_y3();
void create_matrix_temp3();
void create_matrix_c2();

int main(int argc, char *argv[]) {
	create_and_fill_input_matrixes(argv[1]);
	create_matrix_b();
	create_matrix_y1();
	create_matrix_temp1();
	create_matrix_temp2();
	create_matrix_y2();
	create_matrix_c2();
	create_matrix_temp3();
	create_matrix_y3();
	return 0;
}

// templates
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
				matrixC[i][j] += (OUT)(matrixA[i][k] * matrixB[k][j]);

	return matrixC;
}

template<typename IN1, typename IN2, typename OUT>
OUT** matrix_mul_by_const(IN1** matrix, int row, int column, IN2 constant) {
	OUT** matrixC;
	create_matrix<OUT>(matrixC, row, column);
	
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			matrixC[i][j] = (OUT)(matrix[i][j] * constant);

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

// functions 
void create_input_matrixes() {
	create_matrix<int>(matrix_A, dimention, dimention);
	create_matrix<int>(matrix_A1, dimention, dimention);
	create_matrix<int>(matrix_A2, dimention, dimention);
	create_matrix<int>(matrix_B2, dimention, dimention);
	create_matrix<int>(matrix_B1, dimention, 1);
	create_matrix<int>(matrix_C1, dimention, 1);
}

void fill_matrix(int**& matrix, int column, ifstream& file) {
	for (int i = 0; i < dimention; i++)
		for (int j = 0; j < column; j++)
			file >> matrix[i][j];
}

void fill_matrixes(ifstream& file) {
	fill_matrix(matrix_A, dimention, file);
	fill_matrix(matrix_A1, dimention, file);
	fill_matrix(matrix_A2, dimention, file);
	fill_matrix(matrix_B2, dimention, file);
	fill_matrix(matrix_B1, 1, file);
	fill_matrix(matrix_C1, 1, file);
}

void create_and_fill_input_matrixes(char* fileName) {
	ifstream file;
	file.open(fileName);
	file >> dimention;

	create_input_matrixes();
	fill_matrixes(file);

	file.close();
}



void delete_matrixes() {
	delete_matrix<int>(matrix_A, dimention);
	delete_matrix<int>(matrix_A1, dimention);
	delete_matrix<int>(matrix_A2, dimention);
	delete_matrix<int>(matrix_B2, dimention);
	delete_matrix<int>(matrix_B1, dimention);
	delete_matrix<int>(matrix_C1, dimention);
	delete_matrix<double>(matrix_B, dimention);
	delete_matrix<double>(matrix_Y1, dimention); 
	delete_matrix<double>(matrix_Y2, dimention);
	delete_matrix<double>(matrix_temp1, dimention);
	delete_matrix<double>(matrix_temp2, dimention);
	delete_matrix<double>(matrix_Y3, dimention);
	delete_matrix<double>(matrix_temp3, dimention);
	delete_matrix<double>(matrix_C2, dimention);
}

void create_matrix_b() {
	create_matrix<double>(matrix_B, dimention, 1);
	for (int i = 0; i < dimention; i++)
		if (i & 1 == 1)
			matrix_B[i][0] = ((i+1) * (i+1)) / 12.0;
		else
			matrix_B[i][0] = i+1;
}

void create_matrix_y1() {
	matrix_Y1 = matrix_mul<int, double, double>(matrix_A, dimention, dimention, matrix_B, dimention, 1);
}

void create_matrix_temp1() {
	matrix_temp1 = matrix_mul_by_const<double, double, double>(matrix_B, dimention, 1, 12.0);
}

void create_matrix_temp2() {
	matrix_temp2 = matrix_sub<double, int, double>(matrix_temp1, matrix_C1, dimention, 1);
}

void create_matrix_y2() {
	matrix_Y2 = matrix_mul<double, int, double>(matrix_temp2, dimention, 1, matrix_A1, dimention, dimention);
}


void create_matrix_y3() {
	matrix_Y3 = matrix_mul<int, double, double>(matrix_A2, dimention, dimention, matrix_temp3, dimention, 1);
}

void create_matrix_temp3() {
	matrix_temp3 = matrix_sub<int, double, double>(matrix_B2, matrix_C2, dimention, 1);
}

void create_matrix_c2() {
	create_matrix<double>(matrix_C2, dimention, dimention);
	for (int i = 0; i < dimention; i++)
		for (int j = 0; j < dimention; j++)
			matrix_C2[i][j] = 1.0 / (i + j * j);
}

