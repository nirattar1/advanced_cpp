#ifndef MEETINGLOCATION_T_H
#define MEETINGLOCATION_T_H

#include <string>
#include "Meeting_t.h"



template <class T> 
class MeetingLocation_t : public Meeting_t<T>
{

public:
	~ MeetingLocation_t() {};
	MeetingLocation_t(T time_start, T time_end, string subject, string location) : Meeting_t(time_start, time_end, subject) 
	{
		_location = location;
	};
	MeetingLocation_t() {};


	string	GetLocation ()	const {return _location;};
	void SetLocation(const string & location) { _location = location; };

protected:
	string _location;

};

#endif

