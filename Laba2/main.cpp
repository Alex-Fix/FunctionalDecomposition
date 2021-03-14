#include <iostream>
#include <fstream>
using namespace std;

int** matrixA;
int** matrixA1;
int** matrixA2;
int** matrixB2;
int** matrixB1;
int** matrixC1;

void create_and_fill_matrixes(char* inputFile) {
	int n;
	ifstream input(inputFile);
	n = input.get();
}

int main(int argc, char *argv[]) {
	create_and_fill_matrixes(argv[1]);

	return 0;
}