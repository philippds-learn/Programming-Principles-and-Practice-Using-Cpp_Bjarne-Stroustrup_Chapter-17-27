#include "std_lib_facilities_update.h"

class my_base_class
{

public:
	my_base_class()
	{
		cout << "constructing class" << endl;
	}

	~my_base_class()
	{
		cout << "destructing class" << endl;
	}
};

int main()
{
	my_base_class* mbc = new my_base_class;
	delete mbc;
	keep_window_open();
}

