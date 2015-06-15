#include "tContainer_t.h"
#include <iostream>


//note to checker: didn't have time to implement all tests.


using namespace std;



//tester - for container of int pointers .


class Test_t 
{
public:

	Test_t() : _Test_Container () , _values (0)
	{
		//dynamic allocated array of test values.
		_values = new int [4];
		_values[0] = 4;
		_values[1] = 6;
		_values[2] = 21;
		_values[3] = 16;

	};

	virtual ~Test_t()
	{
		delete _values;
	};

	virtual void	BasicTest1();
	virtual void	Insert();
	virtual void	Find();
	virtual void	Access();

private:
#ifndef TEMPLATE_TEMPLATE
	tContainer_t<int, vector<int*> > _Test_Container;	// first version
#else
	tContainer_t<int, vector> _Test_Container;
#endif

	//test array of values.
	int * _values;

};



void Test_t::BasicTest1()
{

	int x = 7;

	_Test_Container.Insert( & x);

}

void Test_t::Insert()
{
	_Test_Container.Insert(&_values[0]);
	_Test_Container.Insert(&_values[1]);
	_Test_Container.Insert(&_values[2]);
	_Test_Container.Insert(&_values[3]);
}

void Test_t::Find()
{
	Insert();
	int * found  = _Test_Container.Find(21);
	int * not_found = _Test_Container.Find(400);
}

void Test_t :: Access ()
{

	Insert();
	cout <<  *_Test_Container[2] << endl;

	cout << *_Test_Container[1] << endl;
}

int main ()
{
	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;
		cout << "Enter your choice:" << endl

			<< "1 - basic test 1" << endl

			<< "2 - insert" << endl

			<< "3 - find" << endl

			<< "4 - access" << endl


			<< "Any other key - quit" << endl << endl;

		if (!(cin >> c))
		{

			cont = false;
			continue;
		}

		switch (c) {
		case 1:
			test.BasicTest1();
			break;
		case 2:
			test.Insert();
			break;
		case 3:
			test.Find();
			break;
		case 4:
			test.Access();
			break;
		default:
			cont = false;
			break;
		}
	}

	return 0;
}

