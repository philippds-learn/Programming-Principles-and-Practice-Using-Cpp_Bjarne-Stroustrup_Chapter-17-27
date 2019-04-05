//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Drill Part 1 1-10

#include "std_lib_facilities_update.h"

// drill 4
void print_array10(ostream& os, int* a)
{
	for (int i = 0; i < 10; i++)
	{
		os << a[i] << endl;
	}
}

// drill 6
void print_array10(ostream& os, int* a)
{
	for (int i = 0; i < 11; i++)
	{
		os << a[i] << endl;
	}
}

// drill 7
void print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		os << a[i] << endl;
	}
}

// drill 10
void print_vector(ostream& os, vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		os << v[i] << endl;
	}
}

int main()
{
	// drill 1
	int* a = new int[10];
	
	// drill 2
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << endl;
	}

	// drill 3
	delete[] a;

	// drill 4
	print_array10(cout, a);

	// drill 5
	int* b = new int[10]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };
	print_array10(cout, b);
	delete[] b;

	// drill 6
	int* c = new int[11]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };
	print_array10(cout, c);
	delete[] c;

	// drill 7
	int size = 10;
	int* d = new int[size]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };	
	print_array(cout, d, size);
	delete[] d;

	// drill 8
	size = 20;
	int* e = new int[size] { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
							 110, 111, 112, 113, 114, 115, 116, 117, 118, 119 };
	print_array(cout, e, size);
	delete[] e;

	// drill 10
	vector<int> p{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
				110, 111, 112, 113, 114, 115, 116, 117, 118, 119 };

	print_vector(cout, p);

	keep_window_open();
}