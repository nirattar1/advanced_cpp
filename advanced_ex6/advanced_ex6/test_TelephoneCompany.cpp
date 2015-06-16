#include <iostream>
#include "TC_t.h"
#include "PhoneOwner_t.h"

using namespace std;


//tester - Telephone Company

class Test_t 
{
public:

	Test_t() 
	{
	};

	virtual ~Test_t()
	{
	
	};

	virtual void	TC_GetInstance();
	virtual void	Client_CreateMobile();
	virtual void	Client_CreateStationary();
	virtual void	TC_ChangePrice();
private:

	
};


void Test_t :: TC_GetInstance ()
{

	TC_t & TC1 = TC_t::GetInstance();
	cout << TC1.GetPrice() << endl;

}



void Test_t::Client_CreateMobile()
{
	PhoneOwner_t * client = new PhoneOwner_t("mobile");
	client->Print();
}

void Test_t::Client_CreateStationary()
{
	PhoneOwner_t * client = new PhoneOwner_t("stationary");
	client->Print();
}

//void Test_t::TC_GetAllClients()
//{
//
//}

void Test_t::TC_ChangePrice ()
{
	//changing price.
	//all clients should be notified.


	cout << "enter new price: " <<endl ;
	float price;
	cin >> price;

	TC_t & TC = TC_t::GetInstance();
	TC.ChangePrice (price);

}

void AttachToTopics ()
{

	//
}

//
//void Test_t::CopyTimeDate ()
//{
//	cTime_t t1;
//	cTime_t t2 (t1);
//
//
//	cDate_t d1;
//	cDate_t d2 (d1);
//
//}
//
//void Test_t::GetWeekDayYearDay()
//{
//
//	cDate_t	d1  ;
//	cout << d1.GetDayOfWeek() << endl;
//	cout << d1.GetDayOfYear() << endl;
//	
//
//}
//
//void Test_t::IsLeapYear()
//{
//
//	const int years [9] = {2000, 2004, 1996, 1994, 1999, 2100, 2200, 2300, 2400};
//	for (int i=0; i < 9; i++)
//	{
//		cDate_t	d (1, 1, years[i]);
//
//		cout << "year " << d.GetYear() << " is leap ? : " << (d.IsLeapYear() ? "yes" : "no") << endl ;
//	}
//	
//
//}
//
//
////will attach the date to time.
//void Test_t :: AttachDateToTime()
//{
//	_date->AttachTime(_time);
//}
//
//
//void Test_t :: IncrementTime() 
//{
//	cout << "stored date and time: " << endl;
//	cout << _date->Print(FORMAT_DEFAULT) << endl;
//	cout << _time->Print(1) << endl;
//
//	int hour, minute, second;
//	cout << "Enter time : hour" << endl;
//	cin >> hour;
//	cout << "Enter time : minute" << endl;
//	cin >> minute;
//	cout << "Enter time : second" << endl;
//	cin >> second;
//	cTime_t t1 (hour, minute, second);
//
//	//perform time addition, date should change
//	_time->AddTime(t1);
//
//	cout << "stored date and time: " << endl;
//	cout << _date->Print(FORMAT_DEFAULT) << endl;
//	cout << _time->Print(1) << endl;
//}
//
//
//void Test_t :: IncrementConstTime ()
//{
//	cTime_t t1 (23, 55, 0);
//	cTime_t t2 (0, 10, 0);
//
//	//build day object and connect to time.
//	cDate_t d1 (31, 12, 2010);
//	d1.AttachTime(&t1);
//
//	cout << d1.Print(FORMAT_DEFAULT) << endl;
//	cout << t1.Print(1) << endl;
//
//	//perform time addition, date should change
//	t1.AddTime(t2);
//
//	cout << d1.Print(FORMAT_DEFAULT) << endl;
//	cout << t1.Print(1) << endl;
//}
//
//void Test_t :: PrintConstDate ()
//{
//	cDate_t d1 (1, 2, 2013);
//	cout << d1.Print(FORMAT_DEFAULT) << endl ;
//	cout << d1.Print(FORMAT_EUROPEAN) << endl ;
//	cout << d1.Print(FORMAT_AMERICAN) << endl ;
//
//	cDate_t d2 (24, 5, 1999);
//	cout << d2.Print(FORMAT_DEFAULT) << endl ;
//	cout << d2.Print(FORMAT_EUROPEAN) << endl ;
//	cout << d2.Print(FORMAT_AMERICAN) << endl ;
//}
//
//
//void Test_t :: PrintConstTime ()
//{
//	cTime_t t1 (13,23,12);
//	cout << t1.Print(1) << endl ;
//	cout << t1.Print(2) << endl ;
//
//	cTime_t t2 (0,59,0);
//	cout << t2.Print(1) << endl ;
//	cout << t2.Print(2) << endl ;
//
//	cTime_t t3 (6,0,1);
//	cout << t3.Print(1) << endl ;
//	cout << t3.Print(2) << endl ;
//}
//
//void Test_t :: PrintDate ()
//{
//	cout << _date->Print(FORMAT_DEFAULT) << endl ;
//	cout << _date->Print(FORMAT_AMERICAN) << endl ;
//	cout << _date->Print(FORMAT_EUROPEAN) << endl ;
//
//}
//
//void Test_t :: PrintTime ()
//{
//	cout << _time->Print(1) << endl ;
//	cout << _time->Print(2) << endl ;
//}
//


int main ()
{
	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;


		cout << "Enter your choice:" << endl

			<< "1 - get Telephone Company" << endl

			<< "2 - create client : mobile" << endl

			<< "3 - create client : stationary" << endl

			<< "4 - change service price" << endl

			<< "Any other key - quit" << endl << endl;

		if (!(cin >> c))
		{

			cont = false;
			continue;
		}

		switch (c) {
		case 1:
			test.TC_GetInstance();
			break;
		case 2:
			test.Client_CreateMobile();
			break;
		case 3:
			test.Client_CreateStationary();
			break;

		case 4:
			test.TC_ChangePrice();
			break;
		

		default:
			cont = false;
			break;
		}
	}

	return 0;
}

