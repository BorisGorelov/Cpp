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

void rotate(int a[], unsigned size, int shift){
	//left cyclic shift
	shift %= size;
	int* p = a + shift;
	rev(a, shift);
	rev(p, size - shift);
	rev(a, size);
	return;
}

unsigned strlen(const char* str) {
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

void test()
{
	(0 == mystrstr("", "")) ? cout << "OK : 1" << " (" << 0 << " : " << (0 == mystrstr("", "")) << " )" << endl : cout << "Failed : 1" << " (" << 0 << " : " << (0 == mystrstr("", "")) << " )" << endl;
	(0 == mystrstr("a", "")) ? cout << "OK : 2" << " (" << 0 << " : " << (0 == mystrstr("a", "")) << " )" << endl : cout << "Failed : 2" << " (" << 0 << " : " << (0 == mystrstr("a", "")) << " )" << endl;
	(0 == mystrstr("a", "a")) ? cout << "OK : 3" << " (" << 0 << " : " << (0 == mystrstr("a", "a")) << " )" << endl : cout << "Failed : 3" << " (" << 0 << " : " << (0 == mystrstr("a", "a")) << " )" << endl;
	(-1 == mystrstr("a", "b")) ? cout << "OK : 4" << " (" << -1 << " : " << (-1 == mystrstr("a", "b")) << " )" << endl : cout << "Failed : 4" << " (" << -1 << " : " << (-1 == mystrstr("a", "b")) << " )" << endl;

	(0 == mystrstr("aa", "")) ? cout << "OK : 5" << " (" << 0 << " : " << (0 == mystrstr("aa", "")) << " )" << endl : cout << "Failed : 5" << " (" << 0 << " : " << (0 == mystrstr("aa", "")) << " )" << endl;
	(0 == mystrstr("aa", "a")) ? cout << "OK : 6" << " (" << 0 << " : " << (0 == mystrstr("aa", "a")) << " )" << endl : cout << "Failed : 6" << " (" << 0 << " : " << (0 == mystrstr("aa", "a")) << " )" << endl;
	(0 == mystrstr("ab", "a")) ? cout << "OK : 7" << " (" << 0 << " : " << (0 == mystrstr("ab", "a")) << " )" << endl : cout << "Failed : 7" << " (" << 0 << " : " << (0 == mystrstr("ab", "a")) << " )" << endl;
	(1 == mystrstr("ba", "a")) ? cout << "OK : 8" << " (" << 1 << " : " << (1 == mystrstr("ba", "a")) << " )" << endl : cout << "Failed : 8" << " (" << 1 << " : " << (1 == mystrstr("ba", "a")) << " )" << endl;
	(-1 == mystrstr("bb", "a")) ? cout << "OK : 9" << " (" << -1 << " : " << (-1 == mystrstr("bb", "a")) << " )" << endl : cout << "Failed : 9" << " (" << -1 << " : " << (-1 == mystrstr("bb", "a")) << " )" << endl;

	(0 == mystrstr("aaa", "")) ? cout << "OK : 10" << " (" << 0 << " : " << (0 == mystrstr("aaa", "")) << " )" << endl : cout << "Failed : 10" << " (" << 0 << " : " << (0 == mystrstr("aaa", "")) << " )" << endl;
	(0 == mystrstr("aaa", "a")) ? cout << "OK : 11" << " (" << 0 << " : " << (0 == mystrstr("aaa", "a")) << " )" << endl : cout << "Failed : 11" << " (" << 0 << " : " << (0 == mystrstr("aaa", "a")) << " )" << endl;
	(1 == mystrstr("abc", "b")) ? cout << "OK : 12" << " (" << 1 << " : " << (1 == mystrstr("abc", "b")) << " )" << endl : cout << "Failed : 12" << " (" << 1 << " : " << (1 == mystrstr("abc", "b")) << " )" << endl;
	(2 == mystrstr("abc", "c")) ? cout << "OK : 13" << " (" << 2 << " : " << (2 == mystrstr("abc", "c")) << " )" << endl : cout << "Failed : 13" << " (" << 2 << " : " << (2 == mystrstr("abc", "c")) << " )" << endl;
	(-1 == mystrstr("abc", "d")) ? cout << "OK : 14" << " (" << -1 << " : " << (-1 == mystrstr("abc", "d")) << " )" << endl : cout << "Failed : 14" << " (" << -1 << " : " << (-1 == mystrstr("abc", "d")) << " )" << endl;

	(-1 == mystrstr("a", "aa")) ? cout << "OK : 15" << " (" << -1 << " : " << (-1 == mystrstr("a", "aa")) << " )" << endl : cout << "Failed : 15" << " (" << -1 << " : " << (-1 == mystrstr("a", "aa")) << " )" << endl;
	(-1 == mystrstr("a", "ba")) ? cout << "OK : 16" << " (" << -1 << " : " << (-1 == mystrstr("a", "ba")) << " )" << endl : cout << "Failed : 16" << " (" << -1 << " : " << (-1 == mystrstr("a", "ba")) << " )" << endl;
	(-1 == mystrstr("a", "ab")) ? cout << "OK : 17" << " (" << -1 << " : " << (-1 == mystrstr("a", "ab")) << " )" << endl : cout << "Failed : 17" << " (" << -1 << " : " << (-1 == mystrstr("a", "ab")) << " )" << endl;
	(-1 == mystrstr("a", "bb")) ? cout << "OK : 18" << " (" << -1 << " : " << (-1 == mystrstr("a", "bb")) << " )" << endl : cout << "Failed : 18" << " (" << -1 << " : " << (-1 == mystrstr("a", "bb")) << " )" << endl;

	(-1 == mystrstr("a", "aaa")) ? cout << "OK : 19" << " (" << -1 << " : " << (-1 == mystrstr("a", "aaa")) << " )" << endl : cout << "Failed : 19" << " (" << -1 << " : " << (-1 == mystrstr("a", "aaa")) << " )" << endl;
	(-1 == mystrstr("aa", "aaa")) ? cout << "OK : 20" << " (" << -1 << " : " << (-1 == mystrstr("aa", "aaa")) << " )" << endl : cout << "Failed : 20" << " (" << -1 << " : " << (-1 == mystrstr("aa", "aaa")) << " )" << endl;
	(0 == mystrstr("aaa", "aaa")) ? cout << "OK : 21" << " (" << 0 << " : " << (0 == mystrstr("aaa", "aaa")) << " )" << endl : cout << "Failed : 21" << " (" << 0 << " : " << (0 == mystrstr("aaa", "aaa")) << " )" << endl;
	(0 == mystrstr("aaab", "aaa")) ? cout << "OK : 22" << " (" << 0 << " : " << (0 == mystrstr("aaab", "aaa")) << " )" << endl : cout << "Failed : 22" << " (" << 0 << " : " << (0 == mystrstr("aaab", "aaa")) << " )" << endl;
	(1 == mystrstr("baaa", "aaa")) ? cout << "OK : 23" << " (" << 1 << " : " << (1 == mystrstr("baaa", "aaa")) << " )" << endl : cout << "Failed : 23" << " (" << 1 << " : " << (1 == mystrstr("baaa", "aaa")) << " )" << endl;
	(1 == mystrstr("baaaa", "aaa")) ? cout << "OK : 24" << " (" << 1 << " : " << (1 == mystrstr("baaaa", "aaa")) << " )" << endl : cout << "Failed : 24" << " (" << 1 << " : " << (1 == mystrstr("baaaa", "aaa")) << " )" << endl;
	(1 == mystrstr("baaab", "aaa")) ? cout << "OK : 25" << " (" << 1 << " : " << (1 == mystrstr("baaab", "aaa")) << " )" << endl : cout << "Failed : 25" << " (" << 1 << " : " << (1 == mystrstr("baaab", "aaa")) << " )" << endl;
	(-1 == mystrstr("abd", "abc")) ? cout << "OK : 26" << " (" << -1 << " : " << (-1 == mystrstr("abd", "abc")) << " )" << endl : cout << "Failed : 26" << " (" << -1 << " : " << (-1 == mystrstr("abd", "abc")) << " )" << endl;

	(2 == mystrstr("ababc", "abc")) ? cout << "OK : 27" << " (" << 2 << " : " << (2 == mystrstr("ababc", "abc")) << " )" << endl : cout << "Failed : 27" << " (" << 2 << " : " << (2 == mystrstr("ababc", "abc")) << " )" << endl;
	(3 == mystrstr("abdabc", "abc")) ? cout << "OK : 28" << " (" << 3 << " : " << (3 == mystrstr("abdabc", "abc")) << " )" << endl : cout << "Failed : 28" << " (" << 3 << " : " << (3 == mystrstr("abdabc", "abc")) << " )" << endl;

}

int main() {
	const char s[25] = "abcdef";
	const char f[14] = "cd";
	//cout << mystrstr(s, f);
	test();
	return 0;
}
