#include <string>
#include "Meeting_t.h"
#include <list>
#include <iostream>
using namespace std;

template <class T>
class DayCalendar_t
{

protected:
	
	list <Meeting_t<T> * > _meetings;

public:
	DayCalendar_t () : _meetings() {}
	virtual ~DayCalendar_t() {};
	friend std::ostream& operator<<	(std::ostream&, const DayCalendar_t<T> &);

	void AddMeeting (Meeting_t<T> * meeting)
	{
		//TODO make good implementation.
		_meetings.push_back(meeting);
	}

	/** find the meeting by start time.
	**/
	Meeting_t<T> * FindMeeting(T TimeStart) const
	{
		for (list<Meeting_t<T> *>::const_iterator it = _meetings.begin(); it != _meetings.end(); ++it)
		{
			if ((*it)->GetTimeStart() == TimeStart)
			{
				return *it;
			}
		}

		return NULL;
	}

	/** delete meeting by start time
	@return true if meeting was found and deleted, or false if not found.
	*/
	bool DeleteMeeting (T TimeStart)
	{
		for (list<Meeting_t<T> *>::iterator it = _meetings.begin(); it != _meetings.end(); ++it)
		{
			if ((*it)->GetTimeStart() == TimeStart)
			{
				_meetings.erase(it);
				return true;
			}
		}

		//meeting not found
		return false;
	}

};


ostream& operator<<(std::ostream &strm, const DayCalendar_t<int> &calendar) 
{
		
	string str = "";

	//iterate and print meetings.
	for (list<Meeting_t<int> *>::const_iterator it = calendar._meetings.begin(); it != calendar._meetings.end(); ++it)
	{
		strm << **it;

	}


	return strm;
}

