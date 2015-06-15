#include "cDate_t.h"
#include <cstdio>
#include <sstream>

void cDate_t::ToBasicTime(time_t& rawTime)  const
{
	struct tm * timeinfo;

	/* get current timeinfo and modify it to the user's choice */
	time ( &rawTime );
	timeinfo = localtime ( &rawTime );
	timeinfo->tm_year = _year - 1900;
	timeinfo->tm_mon = _month - 1;
	timeinfo->tm_mday = _day;

	//change argument
	rawTime = mktime ( timeinfo );

}


void cDate_t::FromBasicTime(const time_t& rawTime) 
{
	struct tm * timeinfo;

	/* get current timeinfo and modify this object */
	timeinfo = localtime ( &rawTime );
	_year = timeinfo->tm_year + 1900;
	_month = timeinfo->tm_mon + 1;
	_day = timeinfo->tm_mday;

}


cDate_t :: cDate_t () 
{

	//get current time
	time_t now;
	now = time (0); 

	FromBasicTime(now);

	//by default date is not coupled to time.
	sbj = 0;

}


cDate_t :: cDate_t (int day, int month, int year) 
{
	_day = day;
	_month = month;
	_year = year;

	//by default date is not coupled to time.
	sbj = 0;
}



void cDate_t::operator= (const cDate_t & other)
{
	SetYear(other.GetYear());
	SetMonth(other.GetMonth());
	SetDay(other.GetDay());

	//if other is attached to subject,
	//then attach this object too.
	if (other.sbj != 0)
	{
		AttachTime(other.sbj);
	}
	
}


int cDate_t :: GetDayOfYear () 
{
	time_t rawtime;
	struct tm * timeinfo;

	/* get current timeinfo and modify it */
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	timeinfo->tm_year = _year - 1900;
	timeinfo->tm_mon = _month - 1;
	timeinfo->tm_mday = _day;

	//fixes wday and yday
	mktime ( timeinfo );

	return timeinfo->tm_yday + 1;

}


int cDate_t :: GetDayOfWeek () 
{
	time_t rawtime;
	struct tm * timeinfo;

	/* get current timeinfo and modify it */
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	timeinfo->tm_year = _year - 1900;
	timeinfo->tm_mon = _month - 1;
	timeinfo->tm_mday = _day;

	//fixes wday and yday
	mktime ( timeinfo );

	return timeinfo->tm_wday + 1;

}


bool cDate_t :: IsLeapYear ()
{
	int year = GetYear();
	if (year % 4 	!= 0)
		return false;
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	return true;
	
}


//Observer implementation
void cDate_t::AttachTime (Subject * time)
{
	sbj  = time;
	sbj->Attach(this);
}


void cDate_t::Update (Subject* ChngSubject) 
{ 
	if (ChngSubject == sbj )
	
	IncrementDay ();
	cout << "date was updated" << endl;
} 

//detach from subject upon destruction
cDate_t :: ~cDate_t ()
{
	if (sbj != 0) 
	{
		sbj->Detach(this);
	}
}



void cDate_t::IncrementDay() 
{

	time_t basicTime;
	time_t newTime;
	ToBasicTime (basicTime);
	struct tm * timeinfo =  localtime(&basicTime);

	//increment day and fix time if needed
	timeinfo->tm_mday++ ;
	newTime = mktime(timeinfo);

	//reflect changes.
	FromBasicTime (newTime);

}

string cDate_t::GetMonthName()
{
	string s;

	const string month_names[] = 
		{"January","February","March","April","May","June","July","August",
		"September","October","November","December"};
	return month_names [GetMonth() - 1];

}


string cDate_t::GetDayName()
{
	string s;

	const string day_names[] = 
	{"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	return day_names [GetDayOfWeek() - 1];

}

string cDate_t::Print(DatePrintFormat fmt) 
{
	string out = "";

	//get formatted day and month
	char day_c [3];
	sprintf(day_c, "%02d" , GetDay());
	string day = "";
	day.append(day_c, 2);

	char month_c [3];
	sprintf(month_c, "%02d" , GetMonth());
	string month = "";
	month.append(month_c, 2);

	stringstream ss;
	ss << GetYear();
	string year = ss.str();

	if (fmt == FORMAT_AMERICAN)
	{
		out += month;
		out += "/" + day;
	}
	else if (fmt == FORMAT_EUROPEAN)
	{
		out += day;
		out += "/" + month;
	}
	else if (fmt == FORMAT_DEFAULT)
	{
		out += day;
		out += "/" + GetMonthName().substr(0,3);
	}
	out += "/" + year;
	return out;
}