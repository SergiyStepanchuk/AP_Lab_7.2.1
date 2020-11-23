// Lab_7_2_1
#include <iostream>
#include <iomanip>
using namespace std;

int myrand(const int& min, const int& max) {
	return min > 0 ?
		rand() % (max - min + 1) + min :
		rand() % (abs(min) + max + 1) + min;
}

void full_matrix(int** matrix, const int* size, const int* dia) {
	for (int i = 0; i < size[0]; i++)
		for (int j = 0; j < size[1]; j++)
			matrix[i][j] = myrand(dia[0], dia[1]);
}

void draw_matrix(int** matrix, const int* size) {
	for (int i = 0; i < size[0]; i++) {
		for (int j = 0; j < size[1]; j++)
			cout << setw(4) << matrix[i][j];
		cout << endl;
	}
}

int min_(const int* mass, int size_i) {
	int min = 0;
	for (--size_i; size_i > 0; --size_i)
		if (mass[size_i] < mass[min])
			min = size_i;
	return min;
}

void edit_matrix(int** matrix, const int &size) {
	for (int i = 0; i < size; i++) 
		swap(
			matrix[size - i - 1][i],
			matrix[size - i - 1][min_(matrix[size - i - 1], size)]
		);
}

void main() {
	srand(time(NULL));
	int** matrix = nullptr, n, dia[2] = {0, 0};
	cout << "n = "; cin >> n;
	cout << "start dia = "; cin >> dia[0];
	cout << "stop dia  = "; cin >> dia[1];

	int size[2] = { n, n };
	matrix = new int* [n];
	for (--n; n >= 0; n--)
		matrix[n] = new int[size[0]];

	full_matrix(matrix, size, dia);
	draw_matrix(matrix, size);
	edit_matrix(matrix, size[0]);
	cout << endl;
	draw_matrix(matrix, size);

	for (n = 0; n < size[0]; n++)
		delete[] matrix[n];
	delete[] matrix;
}