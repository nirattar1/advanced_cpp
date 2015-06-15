#ifndef __CDATE_T_H__
#define __CDATE_T_H__

#include <string>
#include <time.h>
#include "Observer.h"
#include "cTime_t.h"

//formats for the default print operation.
typedef enum
{
	FORMAT_DEFAULT, 
	FORMAT_AMERICAN,
	FORMAT_EUROPEAN
}	DatePrintFormat;


class cDate_t : public Observer
{
public:


	// Default CTOR - from current time
	cDate_t ()  ;

	//copy CTOR
	cDate_t (const cDate_t& d1)
	{
		SetYear(d1.GetYear());
		SetMonth(d1.GetMonth());
		SetDay(d1.GetDay());
	}

	//constructor from values
	cDate_t (int day, int month, int year);

	//DTOR
	virtual ~cDate_t () ;


	//assignment operator (will register to subject!)
	void operator= (const cDate_t & other);


	//getters
	int GetYear () const {return _year;};
	int GetMonth () const {return _month;};
	int GetDay () const {return _day;};

	//return number of days from start of year (1-365) (366)
	int GetDayOfYear () ;

	//return day in week this date is in. (1-7)
	int GetDayOfWeek () ;

	//return is leap year
	bool IsLeapYear ();
	

	//setters
	void SetYear (int val) { _year = val;};
	void SetMonth (int val) { _month = val;};
	void SetDay (int val) { _day = val;};

	//Observer interface 
	void	Update(Subject * ChngSubject);
	void	AttachTime (Subject * time);

	//prints out date.
	virtual string Print(DatePrintFormat fmt) ;

	//get the name of month, may be overridden by derived 
	virtual string GetMonthName();
	//get the name of day, may be overridden by derived 
	virtual string GetDayName();

protected:
	int _day , _month, _year;


private:

	//will advance the day in 1 . will also change month / year if needed.
	void IncrementDay();

	//methods to convert between this object and basic c time
	void ToBasicTime(time_t &rawTime) const;
	void FromBasicTime (const time_t& rawTime);


};





#endif //__CDATE_T_H__

