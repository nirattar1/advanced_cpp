#include <string>
#include "Meeting_t.h"
using namespace std;


class DayCalendar_t
{

protected:
	list <IMeeting *> _meetings;

public:
	DayCalendar_t () : _meetings() {}
	virtual ~DayCalendar_t() {};

	void AddMeeting (IMeeting * meeting)
	{
		//TODO make good implementation.
		_meetings.push_back(meeting);
	}

};

