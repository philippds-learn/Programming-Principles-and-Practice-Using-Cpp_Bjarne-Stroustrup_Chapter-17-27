//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Exercise 2

#include "std_lib_facilities_update.h"

void print_sizes()
{
	// 4
	cout << "The size of an integer is: " <<  sizeof(int) << endl;
	// 8
	cout << "The size of a double is: " << sizeof(double) << endl;
	// 1
	cout << "The size of a bool is: " << sizeof(bool) << endl;
}

int main()
{
	print_sizes();
	keep_window_open();
}