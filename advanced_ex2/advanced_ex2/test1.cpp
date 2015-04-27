#include "Meeting_t.h"
#include "DayCalendar_t.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/* Meeting_t<T> cin cout overloading */
template <class T> ostream& operator<< (ostream& os, const Meeting_t<T>& p)
{
	if (NULL == &p)
	{
		os << "\n NULL (no element)";
	}

	else
	{
		os << "\nStart time: " << p.GetTimeStart()
			<< "\nEnd time: " << p.GetTimeEnd() 
			<< "\nSubject: " << p.GetSubject() << endl << endl;
	}

	return os;
}

template <class T> istream& operator>> (istream& is, Meeting_t<T>& p)
{
	
	T time_start;
	T time_end;
	string subject;

	is >> time_start;
	is >> time_end;
	is >> subject;

	p.SetTimeStart(time_start);
	p.SetTimeEnd(time_end);
	p.SetSubject(subject);
	
	return is;
}
//
///* PersonArray cin cout overloading */
//ostream& operator<< (ostream& os, PersonArray_t& pa)
//{
//	if (NULL == &pa)
//	{
//		os << "\n NULL (no array)";
//	}
//
//	else
//	{
//		for (int i = 0; i < pa.GetSize(); i++)
//		{
//			os << "\nElement number " << i;
//			os << *(pa[i]);
//		}
//
//	}
//
//	return os;
//}

class Test_t {
public:
	Test_t();
	~Test_t();
	virtual void	CreateIntMeeting();
	virtual void	CreateFloatMeeting();
	virtual void	CompareTwoMeetsInt();
	virtual void	AddMeeting();
/*
	virtual void    getNumOfElements();
	virtual void    getCapacity();
	virtual void	insert();
	virtual void	getFirst();
	virtual void	getLast();
	virtual void	find();		
	virtual void	remove();	
	virtual void	removeAll();
	virtual void	removeAndDeleteElement();
	virtual void	removeAndDeleteAll();
	virtual void	append();
	virtual void	prepend();
	virtual void    print();*/
public:
	//
};

Test_t::Test_t()
{
	//arr = new PersonArray_t();
}

Test_t::~Test_t()
{
	//arr->RemoveAndDeleteAll();

}

void Test_t::CreateIntMeeting()
{

	Meeting_t <int> meet;
	cin >> meet;
	cout << meet;

}

void Test_t::CreateFloatMeeting()
{

	Meeting_t <float> meet;
	cin >> meet;
	cout << meet;
}

void Test_t::CompareTwoMeetsInt ()
{
	Meeting_t <int> meet1 (1, 8, "meeting 1");
	Meeting_t <int> meet2 (1, 3, "meeting 2");
	Meeting_t <int> meet3 (2, 4, "meeting 3");
	Meeting_t <int> meet4 (5, 8, "meeting 4");
	cout << meet1;
	cout << meet2;
	cout << meet3;
	cout << meet4;
	cout << string ("does meeting 1 intersect meeting 2? ") << ((meet1==meet2)? "1" : "0") << endl;
	cout << string ("does meeting 2 intersect meeting 3? ") << ((meet2==meet3)? "1" : "0") << endl;
	cout << string ("does meeting 3 intersect meeting 4? ") << ((meet3==meet4)? "1" : "0") << endl;
}

void Test_t::AddMeeting()
{
	Meeting_t <int> meet1 (1, 9, "meeting 1");
	DayCalendar_t <int> cal1;
	cal1.AddMeeting(&meet1);
}

//
//void Test_t::insert()
//{
//	cout << "enter person details.. name, age \n";
//	Person_t* person = new Person_t();
//	cin >> *person;
//	arr->InsertLast(person);
//} 
//
//void Test_t::getNumOfElements()
//{
//	cout << "Number of elements is: " << arr->GetSize() << endl << endl;
//}
//
//void Test_t::getCapacity()
//{
//	cout << "Capacity is: " << arr->GetMaxSize() << endl << endl;
//}
//
//void Test_t::getFirst()
//{
//	cout << "First Element is: " << *arr->GetFirst() << endl << endl;
//}
//
//void Test_t::getLast()
//{
//	cout << "Last Element is: " << *arr->GetLast() << endl << endl;
//}
//
//void Test_t::find()
//{
//	cout << "enter person details.. name, age \n";
//	Person_t person;
//	cin >> person;
//	Person_t* found = arr->FindElement(person);
//
//	cout << "Found Element is: " << *found << endl << endl;
//}
//
//void Test_t::remove()
//{
//	cout << "enter person details.. name, age \n";
//	Person_t person;
//	cin >> person;
//	arr->RemoveElement(person);
//}
//
//void Test_t::removeAll()
//{
//	arr->RemoveAll();
//}
//
//void Test_t::removeAndDeleteElement()
//{
//	cout << "enter person details.. name, age \n";
//	Person_t person;
//	cin >> person;
//	arr->RemoveAndDeleteElement(person);
//}
//
//void Test_t::removeAndDeleteAll()
//{
//	arr->RemoveAndDeleteAll();
//}
//
//void Test_t::append()
//{
//	cout << "enter person details.. name, age \n";
//	Person_t* person = new Person_t;
//	cin >> *person;
//
//	cout << "enter index to insert after \n";
//	int index = 0;
//	cin >> index;
//
//	arr->InsertAfter(index, person);
//}
//
//void Test_t::prepend()
//{
//	cout << "enter person details.. name, age \n";
//	Person_t* person = new Person_t;
//	cin >> *person;
//
//	cout << "enter index to insert before \n";
//	int index = 0;
//	cin >> index;
//
//	arr->InsertBefore(index, person);
//}
//
//void Test_t::print()
//{
//	cout << *arr;
//}

int main ()
{
	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;
		cout << "Enter your choise:" << endl

			<< "1 - create int meeting" << endl
			<< "2 - create float meeting" << endl
			<< "3 - compare 2 int meetings " << endl
			<< "4 - add meeting" << endl
/*
			<< "1 - get number of elements" << endl
			<< "2 - get capacity" << endl
			<< "3 - insert" << endl
			<< "4 - get first" << endl
			<< "5 - get last" << endl
			<< "6 - find" << endl
			<< "7 - remove" << endl
			<< "8 - remove all" << endl
			<< "9 - remove and delete element" << endl
			<< "10 - remove and delete all" << endl
			<< "11 - append" << endl
			<< "12 - prepend" << endl
			<< "13 - print" << endl*/
			<< "Any other key - quit" << endl << endl;

		if (!(cin >> c))
		{

			cont = false;
			continue;
		}

		switch (c) {
		case 1:
			test.CreateIntMeeting();
			break;
		case 2:
			test.CreateFloatMeeting();
			break;
		case 3:
			test.CompareTwoMeetsInt();
			break;
		//case 4:
		//	test.getFirst();
		//	break;
		//case 5:
		//	test.getLast();
		//	break;
		//case 6:
		//	test.find();
		//	break;
		//case 7:
		//	test.remove();
		//	break;
		//case 8:
		//	test.removeAll();
		//	break;
		//case 9:
		//	test.removeAndDeleteElement();
		//	break;
		//case 10:
		//	test.removeAndDeleteAll();
		//	break;
		//case 11:
		//	test.append();
		//	break;
		//case 12:
		//	test.prepend();
		//	break;
		//case 13:
		//	test.print();
		//	break;
		default:
			cont = false;
			break;
		}
	}

	return 0;
}

