//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 17 Exercise 9

#include "std_lib_facilities_update.h"

int main()
{
	cout << "stack dummies:" << endl;

	int one = 1;
	cout << &one << endl;
	int two = 2;
	cout << &two << endl;

	int stack_delta = &two - &one;
	cout << "stack delta = " << stack_delta << endl;
	if (stack_delta > 0) cout << "stack grows up by " << stack_delta << " bite" << endl;
	else cout << "stack grows down by " << stack_delta << " bite" << endl;

	cout << "heap dummies:" << endl;

	int* one_ptr = new int(0);
	cout << &one << endl;
	int* two_ptr = new int(0);
	cout << &two << endl;

	int heap_delta = two_ptr - one_ptr;
	cout << "heap delta = " << heap_delta << endl;
	if (heap_delta > 0) cout << "heap grows up by " << heap_delta << " bite" << endl;
	else cout << "heap grows down by " << heap_delta << " bite" << endl;

	keep_window_open();
}
