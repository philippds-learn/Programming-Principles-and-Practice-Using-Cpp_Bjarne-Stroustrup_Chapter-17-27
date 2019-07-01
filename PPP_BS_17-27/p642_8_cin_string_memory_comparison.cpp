//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Exercise 8

#include "std_lib_facilities_update.h"

int main()
{
	char ch;
	string s;

	while (cin >> ch && ch != '!')
	{
		s += ch;
	}

	cout << s << endl;
	keep_window_open();
}