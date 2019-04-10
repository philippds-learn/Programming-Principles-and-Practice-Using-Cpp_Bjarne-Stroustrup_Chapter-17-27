//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Exercise 3

#include "std_lib_facilities_update.h"

char* strdup(const char* s)
{

}

void print_array(char* s)
{
	for (int i = 0; s[i]; ++i)
	{
		cout << s[i];
	}
	cout << endl;
}

int main()
{
	char my_string[] = "Hello, World!";

	keep_window_open();
}