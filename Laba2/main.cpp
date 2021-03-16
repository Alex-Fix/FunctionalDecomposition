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
int** matrix_Y2;
double** matrix_Y3;
double** matrix_C2;

// temporary data
int** matrix_temp1; // 12 * b1
int** matrix_temp2; // 12 * b1 - c1
double** matrix_temp3; // B2 - C2
double** matrix_temp4; // Y3^2
double** matrix_temp5; // Y3^2 * y1
double** matrix_temp6; // Y3^2 * y1 + y2
double** matrix_temp7; // y1'
double** matrix_temp8; // y1' * ( Y3^2 * y1 + y2 )
double** matrix_temp9; // y1' * ( Y3^2 * y1 + y2 ) * Y3
int** matrix_temp10; // y2'
double** matrix_temp11; // y1 * y2'
double** matrix_temp12; // y1' * ( Y3^2 * y1 + y2 ) * Y3 + y1 * y2'
double** matrix_temp13; // ( y1' * ( Y3^2 * y1 + y2 ) * Y3 + y1 * y2' ) * y2
double** matrix_temp14; // (( y1' * ( Y3^2 * y1 + y2 ) * Y3 + y1 * y2' ) * y2)'
double** matrix_X; // y2' + (( y1' * ( Y3^2 * y1 + y2 ) * Y3 + y1 * y2' ) * y2)'

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
void create_matrix_temp4();
void create_vatrix_temp5();
void create_matrix_temp6();
void create_matrix_temp7();
void create_matrix_temp8();
void create_matrix_temp9();
void create_matrix_temp10();
void create_matrix_temp11();
void create_matrix_temp12();
void create_matrix_temp13();
void create_matrix_temp14();
void create_matrix_X();
void calculate_sync(char* fileName);
void print_matrixes();

int main(int argc, char *argv[]) {
	calculate_sync(argv[1]);
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
	delete_matrix<int>(matrix_Y2, dimention);
	delete_matrix<int>(matrix_temp1, dimention);
	delete_matrix<int>(matrix_temp2, dimention);
	delete_matrix<double>(matrix_Y3, dimention);
	delete_matrix<double>(matrix_temp3, dimention);
	delete_matrix<double>(matrix_C2, dimention);
	delete_matrix<double>(matrix_temp4, dimention);
	delete_matrix<double>(matrix_temp5, dimention);
	delete_matrix<double>(matrix_temp6, dimention);
	delete_matrix<double>(matrix_temp7, 1);
	delete_matrix<double>(matrix_temp8, dimention);
	delete_matrix<double>(matrix_temp9, dimention);
	delete_matrix<int>(matrix_temp10, 1);
	delete_matrix<double>(matrix_temp11, dimention);
	delete_matrix<double>(matrix_temp12, dimention);
	delete_matrix<double>(matrix_temp13, dimention);
	delete_matrix<double>(matrix_temp14, 1);
	delete_matrix<double>(matrix_X, 1);
}

// b = i^2/12 || i
void create_matrix_b() {
	create_matrix<double>(matrix_B, dimention, 1);
	for (int i = 0; i < dimention; i++)
		if ((i + 1 & 1) == 1)
			matrix_B[i][0] = (double)(i) + 1.0;
		else
			matrix_B[i][0] = (((double)i + 1.0) * ((double)i + 1.0)) / 12.0;
}

// y1=A*b
void create_matrix_y1() {
	matrix_Y1 = matrix_mul<int, double, double>(matrix_A, dimention, dimention, matrix_B, dimention, 1);
}

// 12 * b1
void create_matrix_temp1() {
	matrix_temp1 = matrix_mul_by_const<int, int, int>(matrix_B1, dimention, 1, 12);
}

// 12 * b1 - c1
void create_matrix_temp2() {
	matrix_temp2 = matrix_sub<int, int, int>(matrix_temp1, matrix_C1, dimention, 1);
}

// A1*(12*b1-c1)f
void create_matrix_y2() {
	matrix_Y2 = matrix_mul<int, int, int>(matrix_A1, dimention, dimention, matrix_temp2, dimention, 1);
}

// A2* ( B2 - C2 )
void create_matrix_y3() {
	matrix_Y3 = matrix_mul<int, double, double>(matrix_A2, dimention, dimention, matrix_temp3, dimention, dimention);
}

// B2 - C2
void create_matrix_temp3() {
	matrix_temp3 = matrix_sub<int, double, double>(matrix_B2, matrix_C2, dimention, dimention);
}

// C2 = 1/(i+j^2)
void create_matrix_c2() {
	create_matrix<double>(matrix_C2, dimention, dimention);
	for (int i = 0; i < dimention; i++)
		for (int j = 0; j < dimention; j++)
			matrix_C2[i][j] = 1.0 / ((double)i+1.0 + ((double)j+1.0) * ((double)j+1.0));
}

// Y3^2
void create_matrix_temp4() {
	matrix_temp4 = matrix_mul<double, double, double>(matrix_Y3, dimention, dimention, matrix_Y3, dimention, dimention);
}

// Y3^2 * y1
void create_vatrix_temp5() {
	matrix_temp5 = matrix_mul<double, double, double>(matrix_temp4, dimention, dimention, matrix_Y1, dimention, 1);
}

// Y3^2 * y1 + y2
void create_matrix_temp6() {
	matrix_temp6 = matrix_add<double, int, double>(matrix_temp5, matrix_Y2, dimention, 1);
}

// y1'
void create_matrix_temp7() {
	matrix_temp7 = matrix_transposition<double>(matrix_Y1, dimention, 1);
}

// y1' * ( Y3^2 * y1 + y2 )
void create_matrix_temp8() {
	matrix_temp8 = matrix_mul<double, double, double>(matrix_temp6, dimention, 1, matrix_temp7, 1, dimention);
}

// y1' * ( Y3^2 * y1 + y2 ) * Y3
void create_matrix_temp9() {
	matrix_temp9 = matrix_mul<double, double, double>(matrix_temp8, dimention, dimention, matrix_Y3, dimention, dimention);
}

// y2'
void create_matrix_temp10() {
	matrix_temp10 = matrix_transposition<int>(matrix_Y2, dimention, 1);
}

// y1 * y2'
void create_matrix_temp11() {
	matrix_temp11 = matrix_mul<double, int, double>(matrix_Y1, dimention, 1, matrix_temp10, 1, dimention);
}

// y1' * ( Y3^2 * y1 + y2 ) * Y3 + y1 * y2'
void create_matrix_temp12() {
	matrix_temp12 = matrix_add<double, double, double>(matrix_temp9, matrix_temp11, dimention, dimention);
}

// ( y1' * ( Y3^2 * y1 + y2 ) * Y3 + y1 * y2' ) * y2
void create_matrix_temp13() {
	matrix_temp13 = matrix_mul<double, int, double>(matrix_temp12, dimention, dimention, matrix_Y2, dimention, 1);
}

// (( y1' * ( Y3^2 * y1 + y2 ) * Y3 + y1 * y2' ) * y2)'
void create_matrix_temp14() {
	matrix_temp14 = matrix_transposition<double>(matrix_temp13, dimention, 1);
}

// y2' + (( y1' * (Y3 ^ 2 * y1 + y2) * Y3 + y1 * y2' ) * y2)'
void create_matrix_X() {
	matrix_X = matrix_add<int, double, double>(matrix_temp10, matrix_temp14, 1, dimention);
}

void print_matrixes() {
	cout << "\t\t\tA" << endl;
	print_matrix<int>(matrix_A, dimention, dimention);
	cout << endl << "\t\t\tA1" << endl;
	print_matrix<int>(matrix_A1, dimention, dimention);
	cout << endl << "\t\t\tA2" << endl;
	print_matrix<int>(matrix_A2, dimention, dimention);
	cout << endl << "\t\t\tB2" << endl;
	print_matrix<int>(matrix_B2, dimention, dimention);
	cout << endl << "\t\t\tB1" << endl;
	print_matrix<int>(matrix_B1, dimention, 1);
	cout << endl << "\t\t\tC1" << endl;
	print_matrix<int>(matrix_C1, dimention, 1);
	cout << endl << "\t\t\tB" << endl;
	print_matrix<double>(matrix_B, dimention, 1);
	cout << endl << "\t\t\tY1" << endl;
	print_matrix<double>(matrix_Y1, dimention, 1);
	cout << endl << "\t\t\tY2" << endl;
	print_matrix<int>(matrix_Y2, dimention, 1);
	cout << endl << "\t\t\ttemp1" << endl;
	print_matrix<int>(matrix_temp1, dimention, 1);
	cout << endl << "\t\t\ttemp2" << endl;
	print_matrix<int>(matrix_temp2, dimention, 1);
	cout << endl << "\t\t\tY3" << endl;
	print_matrix<double>(matrix_Y3, dimention, dimention);
	cout << endl << "\t\t\ttemp3" << endl;
	print_matrix<double>(matrix_temp3, dimention, dimention);
	cout << endl << "\t\t\tC2" << endl;
	print_matrix<double>(matrix_C2, dimention, dimention);
	cout << endl << "\t\t\ttemp4" << endl;
	print_matrix<double>(matrix_temp4, dimention, dimention);
	cout << endl << "\t\t\ttemp5" << endl;
	print_matrix<double>(matrix_temp5, dimention, 1);
	cout << endl << "\t\t\ttemp6" << endl;
	print_matrix<double>(matrix_temp6, dimention, 1);
	cout << endl << "\t\t\ttemp7" << endl;
	print_matrix<double>(matrix_temp7, 1, dimention);
	cout << endl << "\t\t\ttemp8" << endl;
	print_matrix<double>(matrix_temp8, dimention, dimention);
	cout << endl << "\t\t\ttemp9" << endl;
	print_matrix<double>(matrix_temp9, dimention, dimention);
	cout << endl << "\t\t\ttemp10" << endl;
	print_matrix<int>(matrix_temp10, 1, dimention);
	cout << endl << "\t\t\ttemp11" << endl;
	print_matrix<double>(matrix_temp11, dimention, dimention);
	cout << endl << "\t\t\ttemp12" << endl;
	print_matrix<double>(matrix_temp12, dimention, dimention);
	cout << endl << "\t\t\ttemp13" << endl;
	print_matrix<double>(matrix_temp13, dimention, 1);
	cout << endl << "\t\t\ttemp14" << endl;
	print_matrix<double>(matrix_temp14, 1, dimention);
	cout << endl << "\t\t\tX" << endl;
	print_matrix<double>(matrix_X, 1, dimention);
}

void calculate_sync(char* fileName) {
	create_and_fill_input_matrixes(fileName);
	create_matrix_b();
	create_matrix_y1();
	create_matrix_temp1();
	create_matrix_temp2();
	create_matrix_y2();
	create_matrix_c2();
	create_matrix_temp3();
	create_matrix_y3();
	create_matrix_temp4();
	create_vatrix_temp5();
	create_matrix_temp6();
	create_matrix_temp7();
	create_matrix_temp8();
	create_matrix_temp9();
	create_matrix_temp10();
	create_matrix_temp11();
	create_matrix_temp12();
	create_matrix_temp13();
	create_matrix_temp14();
	create_matrix_X();
	print_matrixes();
	delete_matrixes();
}

