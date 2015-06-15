#ifndef __CTIME_T_H__
#define __CTIME_T_H__

#include <string>
#include <time.h>
#include "Observer.h"

//class cTime_t which describes the behavior of time objects.
//
//Time objects is built from seconds, minutes and hours. This
//object describes only one day time ( not more than 24 hours ).
//


class cTime_t : public Subject
{
public:


	// Default CTOR - from current time
	cTime_t ();

	//copy CTOR (does not copy observers!)
	cTime_t (const cTime_t& t1);

	//CTORs from hour, minutes and seconds
	cTime_t (int hour, int minute, int seconds);

	//DTOR
	virtual ~cTime_t ()  {};

	//assignment operator (does not copy observers!)
	void operator= (const cTime_t& other);

	//getters
	int GetHour () const {return _hour;};
	int GetMinute () const {return _minute;};
	int GetSecond () const {return _second;};
	
	//setters
	void SetHour (int val) { _hour = val;};
	void SetMinute (int val) { _minute = val;};
	void SetSecond (int val) { _second = val;};

	//perform addition with another time object . (will notify observers if day has advanced.)
	void AddTime (const cTime_t& d1);

	//print time
	string Print (int fmt);

private:
	int _hour, _minute, _second ;

	//methods to convert between this object and basic c time
	void ToBasicTime(time_t &rawTime) const;
	void FromBasicTime (const time_t& rawTime);


};





#endif //__CTIME_T_H__

