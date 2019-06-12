//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Exercise 4

#include "std_lib_facilities_update.h"

char* strdup1(const char* s)
{
	if (s == 0)
	{
		return 0;
	}

	// count s
	int count = 0;
	for (int i = 0; s[i] != 0; i++)
	{
		count++;
	}

	// allocate memory
	char* result = new char[count + 1];

	// copy
	for (int i = 0; i < count; i++)
	{
		result[i] = s[i];
	}
		
	result[count] = 0;

	return result;
}

int main()
{
	char my_string[] = "Hello, World!";

	strdup1(my_string);

	keep_window_open();
}