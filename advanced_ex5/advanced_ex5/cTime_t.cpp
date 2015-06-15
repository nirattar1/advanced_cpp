#include "cTime_t.h"
#include <sstream>


cTime_t::cTime_t () : Subject ()
{
	//get current time
	time_t now;
	now = time (0); 
	struct tm * currentTime;
	currentTime = localtime(&now);

	//store in members
	_hour = currentTime->tm_hour;
	_minute = currentTime->tm_min;
	_second = currentTime->tm_sec;
	
}

cTime_t::cTime_t (const cTime_t& t1) : Subject ()
{

	SetHour(t1.GetHour());
	SetMinute(t1.GetMinute());
	SetSecond(t1.GetSecond());
}


cTime_t::cTime_t (int hour, int minute, int seconds) : Subject ()
{
	_hour = hour;
	_minute = minute;
	_second = seconds;
}


void cTime_t::operator= (const cTime_t& t1)
{
	SetHour(t1.GetHour());
	SetMinute(t1.GetMinute());
	SetSecond(t1.GetSecond());
}


void cTime_t::ToBasicTime(time_t& rawTime)  const
{
	struct tm * timeinfo;

	/* get current timeinfo and modify it to the user's choice */
	time ( &rawTime );
	timeinfo = localtime ( &rawTime );
	timeinfo->tm_hour = _hour;
	timeinfo->tm_min = _minute;
	timeinfo->tm_sec = _second;

	//change argument
	rawTime = mktime ( timeinfo );

}


void cTime_t::FromBasicTime(const time_t& rawTime) 
{
	struct tm * timeinfo;

	/* get current timeinfo and modify this object */
	timeinfo = localtime ( &rawTime );
	_hour = timeinfo->tm_hour;
	_minute= timeinfo->tm_min;
	_second = timeinfo->tm_sec;

}



void cTime_t :: AddTime (const cTime_t& t1)
{

	time_t basicTime;
	time_t newTime;
	ToBasicTime (basicTime);
	struct tm * timeinfo =  localtime(&basicTime);

	int original_day = timeinfo->tm_mday;

	//increment time, fix if needed (will advance day)
	timeinfo->tm_hour += t1.GetHour() ;
	timeinfo->tm_min += t1.GetMinute() ;
	timeinfo->tm_sec += t1.GetSecond() ;
	newTime = mktime(timeinfo);

	//reflect changes.
	FromBasicTime (newTime);

	//reached time past the day, should update all attached date objects.
	if (original_day != timeinfo->tm_mday)
	{
		//update observers
		Notify();
	}


}

string cTime_t :: Print (int fmt)
{

	stringstream out;


	//print 24h format.
	if (fmt==1)
	{
		out << GetHour();
		out << ":" << GetMinute();
		out << ":" << GetSecond();
	}
	//print 12h format
	else if (fmt==2)
	{
		int hour = GetHour();
		string am_pm = "AM";
		 //if after midday, fix hour and change to PM
		if ((hour/12) >= 1)
		{
			hour = hour % 12;
			am_pm = "PM";
		}
		out << hour;
		out << ":" << GetMinute();
		out << ":" << GetSecond();
		out << " " << am_pm;
	}

	string str = out.str();
	return str;
}