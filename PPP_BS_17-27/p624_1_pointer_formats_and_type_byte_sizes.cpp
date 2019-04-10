//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Exercise 1 - 2

#include "std_lib_facilities_update.h"

int main()
{
	// Exercise 1
	int p = 7;
	int* p1 = &p;
	cout << "The format of a pointer is a long hexadecimal number, for example: " <<  p1 << endl;	

	// Exercise 2
	cout << "the size of int is " << sizeof(int) << '\n';
	cout << "the size of double is " << sizeof(double) << '\n';
	cout << "the size of bool is " << sizeof(bool) << '\n';
	
	keep_window_open();
}