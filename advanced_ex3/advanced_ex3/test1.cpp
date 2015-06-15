#include "virtIO_t.h"
#include <iostream>
#include <cstdlib>

using namespace std;


class Test_t {
public:
	Test_t();
	~Test_t();
	virtual void	IO_Test1();
	virtual void    print();

};

Test_t::Test_t()
{
}

Test_t::~Test_t()
{
}

void Test_t::IO_Test1()
{
	virtIO_t IO_obj ("nir.txt", "");
	//
}

void Test_t::print()
{
	
}

int main ()
{
	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;
		cout << "Enter your choice:" << endl

			<< "1 - IO test 1"  << endl
			/*<< "2 - create float meeting" << endl
			<< "4 - add meeting (base test)" << endl
			<< "5 - add location meeting (base test)" << endl
			<< "6 - add meeting" << endl
			<< "7 - find int meeting" << endl
			<< "8 - remove int meeting" << endl
			<< "9 - compare 2 int meetings " << endl
			<< "10 - compare 2 float meetings " << endl*/
<< "13 - print calendar" << endl
			<< "Any other key - quit" << endl << endl;

		if (!(cin >> c))
		{

			cont = false;
			continue;
		}

		switch (c) {
		case 1:
			test.IO_Test1();
			break;
		case 2:
			//
			break;
		case 13:
			test.print();
			break;
		default:
			cont = false;
			break;
		}
	}

	return 0;
}

