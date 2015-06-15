#include "cTime_t.h"
#include "cDate_t.h"
#include <iostream>



using namespace std;



//tester - for container of int pointers .


class Test_t 
{
public:

	Test_t() : _date (0), _time (0)
	{
	};

	virtual ~Test_t()
	{
		delete _date;
		delete _time;
	};

	virtual void	CreateTime();
	virtual void	CreateDate();
	virtual void	CopyTimeDate();
	virtual void	GetWeekDayYearDay();
	virtual void	IsLeapYear();
	virtual void	IncrementTime ();
	virtual void	IncrementConstTime();
	virtual void	AttachDateToTime ();
	virtual void	PrintDate ();
	virtual void	PrintTime ();
	virtual void	PrintConstDate ();
	virtual void	PrintConstTime ();
private:

	//pointers to test values.
	cDate_t * _date ;
	cTime_t * _time ;

};


void Test_t::CreateTime()
{

	int hour, minute, second;
	cout << "Enter time : hour" << endl;
	cin >> hour;
	cout << "Enter time : minute" << endl;
	cin >> minute;
	cout << "Enter time : second" << endl;
	cin >> second;
	_time = new cTime_t (hour, minute, second);

	PrintTime();
}

void Test_t::CreateDate()
{
	int day, month, year;
	cout << "Enter date: day" <<endl;
	cin >> day;
	cout << "Enter date: month" <<endl;
	cin >> month;
	cout << "Enter date: year" <<endl;
	cin >> year;
	_date = new cDate_t (day, month, year);	

	PrintDate();
}

void Test_t::CopyTimeDate ()
{
	cTime_t t1;
	cTime_t t2 (t1);


	cDate_t d1;
	cDate_t d2 (d1);

}

void Test_t::GetWeekDayYearDay()
{

	cDate_t	d1  ;
	cout << d1.GetDayOfWeek() << endl;
	cout << d1.GetDayOfYear() << endl;
	

}

void Test_t::IsLeapYear()
{

	const int years [9] = {2000, 2004, 1996, 1994, 1999, 2100, 2200, 2300, 2400};
	for (int i=0; i < 9; i++)
	{
		cDate_t	d (1, 1, years[i]);

		cout << "year " << d.GetYear() << " is leap ? : " << (d.IsLeapYear() ? "yes" : "no") << endl ;
	}
	

}


//will attach the date to time.
void Test_t :: AttachDateToTime()
{
	_date->AttachTime(_time);
}


void Test_t :: IncrementTime() 
{
	cout << "stored date and time: " << endl;
	cout << _date->Print(FORMAT_DEFAULT) << endl;
	cout << _time->Print(1) << endl;

	int hour, minute, second;
	cout << "Enter time : hour" << endl;
	cin >> hour;
	cout << "Enter time : minute" << endl;
	cin >> minute;
	cout << "Enter time : second" << endl;
	cin >> second;
	cTime_t t1 (hour, minute, second);

	//perform time addition, date should change
	_time->AddTime(t1);

	cout << "stored date and time: " << endl;
	cout << _date->Print(FORMAT_DEFAULT) << endl;
	cout << _time->Print(1) << endl;
}


void Test_t :: IncrementConstTime ()
{
	cTime_t t1 (23, 55, 0);
	cTime_t t2 (0, 10, 0);

	//build day object and connect to time.
	cDate_t d1 (31, 12, 2010);
	d1.AttachTime(&t1);

	cout << d1.Print(FORMAT_DEFAULT) << endl;
	cout << t1.Print(1) << endl;

	//perform time addition, date should change
	t1.AddTime(t2);

	cout << d1.Print(FORMAT_DEFAULT) << endl;
	cout << t1.Print(1) << endl;
}

void Test_t :: PrintConstDate ()
{
	cDate_t d1 (1, 2, 2013);
	cout << d1.Print(FORMAT_DEFAULT) << endl ;
	cout << d1.Print(FORMAT_EUROPEAN) << endl ;
	cout << d1.Print(FORMAT_AMERICAN) << endl ;

	cDate_t d2 (24, 5, 1999);
	cout << d2.Print(FORMAT_DEFAULT) << endl ;
	cout << d2.Print(FORMAT_EUROPEAN) << endl ;
	cout << d2.Print(FORMAT_AMERICAN) << endl ;
}


void Test_t :: PrintConstTime ()
{
	cTime_t t1 (13,23,12);
	cout << t1.Print(1) << endl ;
	cout << t1.Print(2) << endl ;

	cTime_t t2 (0,59,0);
	cout << t2.Print(1) << endl ;
	cout << t2.Print(2) << endl ;

	cTime_t t3 (6,0,1);
	cout << t3.Print(1) << endl ;
	cout << t3.Print(2) << endl ;
}

void Test_t :: PrintDate ()
{
	cout << _date->Print(FORMAT_DEFAULT) << endl ;
	cout << _date->Print(FORMAT_AMERICAN) << endl ;
	cout << _date->Print(FORMAT_EUROPEAN) << endl ;

}

void Test_t :: PrintTime ()
{
	cout << _time->Print(1) << endl ;
	cout << _time->Print(2) << endl ;
}



int main ()
{
	bool cont = true;			// trigger to stop loop

	Test_t test;

	while (cont) {
		unsigned int c;


		cout << "Note : to attach date to time select option 11 ." << endl;
		cout << "Enter your choice:" << endl

			<< "1 - create date" << endl

			<< "2 - create time" << endl

			<< "3 - copy time" << endl

			<< "4 - get time week and day" << endl

			<< "5 - is leap year" << endl

			<< "6 - increment const time " << endl

			<< "7 - print date" << endl

			<< "8 - print time" << endl

			<< "9 - print const date" << endl

			<< "10 - print const time" << endl

			<< "11 - attach date to time " << endl

			<< "12 - increment time" << endl

			<< "Any other key - quit" << endl << endl;

		if (!(cin >> c))
		{

			cont = false;
			continue;
		}

		switch (c) {
		case 1:
			test.CreateDate();
			break;
		case 2:
			test.CreateTime();
			break;
		case 3:
			test.CopyTimeDate();
			break;
		case 4:
			test.GetWeekDayYearDay();
			break;
		case 5:
			test.IsLeapYear();
			break;

		case 6:
			test.IncrementConstTime();
			break;

		case 7:
			test.PrintDate();
			break;

		case 8:
			test.PrintTime();
			break;

		case 9:
			test.PrintConstDate();
			break;

		case 10:
			test.PrintConstDate();
			break;

		case 11:
			test.AttachDateToTime();
			break;

		case 12:
			test.IncrementTime();
			break;


		default:
			cont = false;
			break;
		}
	}

	return 0;
}

