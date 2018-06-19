#include "std_lib_facilities_update.h"

void sizes(char ch, int i, int* p, bool b, double d)
{
	cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << '\n';
	cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
	cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';
	cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof(b) << '\n';
	cout << "the size of double is " << sizeof(double) << ' ' << sizeof(d) << '\n';
}

int main()
{
	int x = 1;
	int* pi = &x;

	sizes('c', 1, pi, true, 1.1);
	keep_window_open();
}