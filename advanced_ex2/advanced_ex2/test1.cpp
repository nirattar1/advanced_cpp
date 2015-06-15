#include "Meeting_t.h"
#include "MeetingLocation_t.h"
#include "DayCalendar_t.h"
#include <iostream>
#include <cstdlib>

using namespace std;

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
	virtual void	CompareTwoMeetsFloat();
	virtual void	AddMeetingBase();
	virtual void 	LocationMeeting_Add();

	/**add meeting to calendar member.
	*/
	virtual void	AddMeeting();
	template <class T> void	FindMeeting();
	virtual void RemoveIntMeeting();
	virtual void    print();

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
	*/
public:
	//member of calendar. 
	DayCalendar_t<int> _calendar_ints;
	DayCalendar_t<float> _calendar_floats;
};

Test_t::Test_t()
{
	//arr = new PersonArray_t();
}

Test_t::~Test_t()
{
	//TODO clean all meetings (dynamically allocated).


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
	cout << string ("does meeting 1 intersect meeting 3? ") << ((meet1==meet3)? "1" : "0") << endl;
	cout << string ("does meeting 3 intersect meeting 4? ") << ((meet3==meet4)? "1" : "0") << endl;
}

void Test_t::CompareTwoMeetsFloat ()
{
	Meeting_t <float> meet1 (1.1, 8.1, "meeting 1");
	Meeting_t <float> meet2 (1.1, 3.2, "meeting 2");
	Meeting_t <float> meet3 (2.2, 4.4, "meeting 3");
	Meeting_t <float> meet4 (5.5, 8.0, "meeting 4");
	Meeting_t <float> meet5 (8.0, 9.0, "meeting 5");
	Meeting_t <float> meet6 (7.9, 8.1, "meeting 6");
	cout << meet1;
	cout << meet2;
	cout << meet3;
	cout << meet4;
	cout << string ("does meeting 1 intersect meeting 2? ") << ((meet1==meet2)? "1" : "0") << endl;
	cout << string ("does meeting 2 intersect meeting 3? ") << ((meet2==meet3)? "1" : "0") << endl;
	cout << string ("does meeting 1 intersect meeting 3? ") << ((meet1==meet3)? "1" : "0") << endl;
	cout << string ("does meeting 3 intersect meeting 4? ") << ((meet3==meet4)? "1" : "0") << endl;
	cout << string ("does meeting 4 intersect meeting 5? ") << ((meet4==meet5)? "1" : "0") << endl;
	cout << string ("does meeting 5 intersect meeting 6? ") << ((meet5==meet6)? "1" : "0") << endl;
}

void Test_t::AddMeetingBase()
{
	Meeting_t <int> meet1 (1, 4, "meeting 1");
	Meeting_t <int> meet2 (4, 7, "meeting 2");
	DayCalendar_t <int> cal1;
	cal1.AddMeeting(&meet1);
	cal1.AddMeeting(&meet2);
}

void Test_t::AddMeeting()
{
	Meeting_t <int> * meet = new Meeting_t<int>;
	cin >> *meet;

	try
	{
		_calendar_ints.AddMeeting(meet);
	}
	catch  (string ex)
	{
		cout << ex;
	}
	

}

void Test_t::LocationMeeting_Add()
{
	Meeting_t <int> meet1 (1, 4, "meeting 1");
	MeetingLocation_t<int> locmeet2 (4, 7, "meeting 2", "new location");
	DayCalendar_t <int> cal1;
	cal1.AddMeeting(&meet1);
	cal1.AddMeeting(&locmeet2);
	
	//this should not compile (add meet of float):
	//MeetingLocation_t<float> meet3(4.6, 7.6, "meeting 3", "location3");
	//cal1.AddMeeting(&meet3);
}


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

template <class T> void Test_t::FindMeeting()
{
	cout << "Enter start time \n";
	T TimeStart;
	cin >> TimeStart;
	
	Meeting_t<T> * found = _calendar_ints.FindMeeting(TimeStart);

	if (!found)
	{
		cout << "Meeting not found ." ;
	}
	else
	{
		cout << "Found Element is: " << *found << endl << endl;
	}

}

void Test_t::RemoveIntMeeting()
{

	cout << "Enter start time \n";
	int TimeStart;
	cin >> TimeStart;

	bool found = _calendar_ints.DeleteMeeting(TimeStart);

	if (!found)
	{
		cout << "Meeting not found ."  << endl;
	}
	else
	{
		cout << "Meeting found and removed. " << endl;
	}
}

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

void Test_t::print()
{
	cout << _calendar_ints;
}

int main ()
{
	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;
		cout << "Enter your choice:" << endl

			<< "1 - create int meeting" << endl
			<< "2 - create float meeting" << endl
			<< "4 - add meeting (base test)" << endl
			<< "5 - add location meeting (base test)" << endl
			<< "6 - add meeting" << endl
			<< "7 - find int meeting" << endl
			<< "8 - remove int meeting" << endl
			<< "9 - compare 2 int meetings " << endl
			<< "10 - compare 2 float meetings " << endl

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
*/
			<< "13 - print calendar" << endl
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
		case 4:
			test.AddMeetingBase();
			break;
		case 5:
			test.LocationMeeting_Add();
		case 6:
			test.AddMeeting();
			break;
		case 7:
			test.FindMeeting<int>();
			break;
		case 8:
			test.RemoveIntMeeting();
			break;
		case 9:
			test.CompareTwoMeetsInt();
			break;
		case 10:
			test.CompareTwoMeetsFloat();
			break;
		//case 10:
		//	test.removeAndDeleteAll();
		//	break;
		//case 11:
		//	test.append();
		//	break;
		//case 12:
		//	test.prepend();
		//	break;
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

