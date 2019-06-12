//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Exercise 5

#include "std_lib_facilities_update.h"

int findx(const char* s, const char* x)
{
	// if s is 0 exit
	if (s == 0)
	{
		delete[] s;
		delete[] x;

		return 0;
	}

	// count s
	int count_s = 0;
	for (int i = 0; s[i] != 0; i++)
	{
		count_s++;
	}

	// count x
	int count_x = 0;
	for (int i = 0; x[i] != 0; i++)
	{
		count_x++;
	}

	// if word to search for is too long exit
	if (count_s < count_x)
	{
		delete[] s;
		delete[] x;

		return 0;
	}

	for (int i = 0; i < count_s; i++)
	{
		for (int j = 0; j < count_x + 1; j++)
		{
			// if loop reaches end of search word return index
			if (x[j] == 0)
			{
				delete[] s;
				delete[] x;
				
				return i;
			}

			if (s[i + j] != x[j])
			{
				break;
			}
		}
	}

	delete[] s;
	delete[] x;

	return 0;
}

int main()
{
	char my_string[] = "Hello, World!";
	char search_for[] = "World";

	cout << findx(my_string, search_for) << endl;

	keep_window_open();
}