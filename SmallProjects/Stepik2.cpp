#pragma once
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Header.h"
using namespace std;

char* resize(char* str, unsigned size, unsigned new_size)
{
	char* t = new char[new_size];
	for (int i = 0; i < new_size; ++i)
		t[i] = str[i];
	delete[] str;
	return t;
}

//char* getline()
//{
//	unsigned size = 1000;
//	char* ans = new char[size];
//	int i = 0;
//	int count = 0;
//	char ch;
//	while (cin.get(ch) && ch != '\n') {
//		if (i == 1000) {
//			resize(ans, size, size + 1000);
//			size += 1000;
//			i = 0;
//		}
//		else {
//			ans[count] = ch;
//			count++;
//		}
//		i++;
//	}
//	resize(ans, size, mystrlen(ans) + 1);
//	count++;
//	return ans;
//}


int** transpose(const int* const* m, unsigned rows, unsigned cols)
{
	int** t = new int* [cols];
	t[0] = new int[rows * cols];
	for (unsigned i = 1; i != cols; ++i)
		t[i] = t[i - 1] + rows;
	for (unsigned i = 0; i < cols; ++i)
		for (unsigned j = 0; j < rows; ++j)
			t[i][j] = m[j][i];
	return t;
}

void swap_min(int* m[], unsigned rows, unsigned cols)
{
	int ans = 0;
	int min = INT16_MAX;
	for (unsigned i = 0; i < rows; ++i)
		for (unsigned j = 0; j < cols; ++j)
			if (m[i][j] < min) {
				min = m[i][j];
				ans = i;
			}
	if (ans)
		std::swap(m[0], m[ans]);
}
