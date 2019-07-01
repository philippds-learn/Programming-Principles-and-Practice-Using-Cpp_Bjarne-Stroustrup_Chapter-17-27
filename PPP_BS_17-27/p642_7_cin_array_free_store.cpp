//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Exercise 7

#include "std_lib_facilities_update.h"

char* add(const char* s)
{
	// if s is 0 exit
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
	char* result = new char[count + 2];

	// copy
	for (int i = 0; i < count; i++)
	{
		result[i] = s[i];
	}

	result[count] = 0;

	delete[] s;
	return result;
}

int main()
{
	char ch;
	char* my_array = new char[1];
	*my_array = 0;

	int count = 0;

	while (cin >> ch && ch != '!')
	{
		// get count of old array and add an item
		my_array = add(my_array);
		// place letter into array
		my_array[count] = ch;

		// make sure last item in array is 0
		count++;
		my_array[count] = 0;
	}

	cout << my_array << endl;
	delete[] my_array;
	keep_window_open();
}