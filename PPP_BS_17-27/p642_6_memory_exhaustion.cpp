//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Exercise 6

#include "std_lib_facilities_update.h"

int main()
{
	int i = 0;

	while (true) {
		cout << i++ << " MB\n";
		double* pd = new double[131072]; // allocate 1 MB
	}

	keep_window_open();
}