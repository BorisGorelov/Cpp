#include <iostream>
#include <cmath>
#include <algorithm>
#include "Header.h"
using namespace std;

void print_2darr(int** t, unsigned rows, unsigned cols) {
	for (unsigned i = 0; i != rows; ++i) {
		for (unsigned j = 0; j != cols; ++j)
			cout << t[i][j] << ' ';
		cout << endl;
	}
}

int main() {
	int** m = new int* [3];
	m[0] = new int[4 * 3];
	for(int i = 1; i < 4; ++i)
		m[i] = 
	return 0;
}
