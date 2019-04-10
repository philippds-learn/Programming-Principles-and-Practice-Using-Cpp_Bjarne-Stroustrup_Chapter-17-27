//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Drill Par2 1 1-13

#include "std_lib_facilities_update.h"

void print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		os << a[i] << endl;
	}
}

int main()
{	
	// Drill 1
	int p = 7;
	int* p1 = &p;

	// Drill 2
	//cout << p << endl;
	//cout << p1 << endl;

	// Drill 3
	int* p2 = new int[7]{ 1,2,4,8,16,32,64 };

	// Drill 4
	//cout << p2 << endl;
	//print_array(cout, q, 7);

	// Drill 5
	int* p3 = p2;

	// Drill 6
	p2 = p1;

	// Drill 7
	p2 = p3;

	// Drill 8
	/*
	cout << p1 << endl;
	cout << *p1 << endl;
	cout << p2 << endl;
	cout << *p2 << endl;
	*/

	// Drill 9
	delete[] p2;

	// Drill 10
	int* p4 = new int[10]{ 1,2,4,8,18,32,64,128,256,512 };

	// Drill 11
	int* p5 = new int[10]{ 1,2,3,4,5,6,7,8,9,10 };

	// Drill 12
	p4 = p5;

	// Drill 13
	vector<int> p6{ 1,2,4,8,18,32,64,128,256,512 };
	vector<int> p7{ 1,2,3,4,5,6,7,8,9,10 };
	p6 = p7;

	keep_window_open();
}