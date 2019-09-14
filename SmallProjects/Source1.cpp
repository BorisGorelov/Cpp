#include <iostream>
#include <cmath>
#include <algorithm>
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
	int* p = a;
	int* q = &a[size - 1];
	for (unsigned i = 0; i < size / 2; i++)
		mySwap((p + i), (q - i));
	return;
}

void rotate(int a[], unsigned size, int shift)
{
	shift %= size;
	int* p = a + shift;
	rev(a, shift);
	rev(p, size - shift);
	rev(a, size);
	return;
}

int main() {
	int a[4] = {1, 2, 3, 4};
	rotate(a, 4, 1);
	for (int* i = a; i <= a + 3; ++i)
		cout << *i << ' ';
	return 0;
}
