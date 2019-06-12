//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Exercise 3

#include "std_lib_facilities_update.h"

void to_lower(char* s)
{
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] += 'a' - 'A';
		}
	}

	delete[] s;
}

void print_array(char* s)
{
	for (int i = 0; s[i]; ++i)
	{
		cout << s[i];
	}
	cout << endl;
	
	delete[] s;
}

int main()
{
	char my_string[] = "Hello, World!";
	print_array(my_string);

	to_lower(my_string);
	print_array(my_string);

	keep_window_open();
}