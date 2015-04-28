#include <string>
#include "Meeting_t.h"
#include <list>
using namespace std;

template <class T>
class DayCalendar_t
{

protected:
	
	list <Meeting_t<T> * > _meetings;

public:
	DayCalendar_t () : _meetings() {}
	virtual ~DayCalendar_t() {};

	void AddMeeting (Meeting_t<T> * meeting)
	{
		//TODO make good implementation.
		_meetings.push_back(meeting);
	}

};

