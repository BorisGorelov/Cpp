#pragma once
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

void squareEq(double a, double b, double c) {
	double d = b * b - 4 * a * c;
	if (d > 0) {
		double x1 = (-b + sqrt(d)) / (2 * a);
		double x2 = (-b - sqrt(d)) / (2 * a);
		cout << x1 << ' ' << x2;
		return;
	}
	else if (d == 0) {
		double x1 = (-b) / (2 * a);
		cout << x1 << ' ' << x1;
		return;
	}
	else
		cout << "No real roots";
}

void spaceRemove() {
	char c = '\0';
	bool flag = true;
	while (cin.get(c)) {
		if (c != ' ') {
			cout << c;
			flag = false;
		}
		else if ((c == ' ') && (!flag)) { //first space
			cout << c;
			flag = true;
			continue;
		}
		else if ((c == ' ') && (flag))
			continue;
	}
	return;
}

unsigned gcd(unsigned a, unsigned b) {
	if (!a)
		return b;
	if (!b)
		return a;
	return gcd(max(a, b) % min(a, b), min(a, b));

}

void print(int a) {
	// 15 1 0 to 1 15
	if (a) {
		int buf;
		cin >> buf;
		print(buf);
		cout << a << ' ';
	}
	else
		return;
}

void mySwap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
	return;
}

void rev(int a[], unsigned size) {
	//reverse 
	int* p = a;
	int* q = &a[size - 1];
	for (unsigned i = 0; i < size / 2; i++)
		mySwap((p + i), (q - i));
	return;
}

void rotate(int a[], unsigned size, int shift) {
	//left cyclic shift
	shift %= size;
	int* p = a + shift;
	rev(a, shift);
	rev(p, size - shift);
	rev(a, size);
	return;
}

unsigned mystrlen(char* str) {
	//length of C-style string (without '\0')
	unsigned ans = 0;
	while (*(str++) != '\0')
		ans++;
	return ans;
}

void mystrcat(char* to, const char* from)
{
	//string concatenation
	unsigned len = strlen(to) - 1;
	int i = -1;
	do {
		len++;
		i++;
		to[len] = from[i];
	} while (from[i]);
	return;
}

bool equal(const char* a, const char* b) {
	//b is start part of a
	while (*b) {
		if (*a != *b)
			return false;
		else {
			a++;
			b++;
		}
	}
	return true;
}

int mystrstr(const char* text, const char* pattern)
{
	//returns the first occurrence of the pattern in the text
	unsigned patLen = strlen(pattern);
	unsigned texLen = strlen(text);
	if (patLen > texLen)
		return -1;
	if (patLen) {
		int ans = 0;
		while (ans <= strlen(text) - patLen) {
			if (equal(text + ans, pattern))
				return ans;
			else
				ans++;
		}
		return -1;
	}
	else
		return 0;
}