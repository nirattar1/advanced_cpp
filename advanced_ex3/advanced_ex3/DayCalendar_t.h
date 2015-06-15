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
	DayCalendar_t () : _meetings() {};
	virtual ~DayCalendar_t() {};

	// for print
	friend std::ostream& operator<<	(std::ostream&, const DayCalendar_t<T> &);

	/** will add the meeting pointed at "meeting_1" , to calendar.
	@throws exception , if meeting intersects with someone.
	*/
	void AddMeeting (Meeting_t<T> * meeting_1)
	{
		list<Meeting_t<T> *>::iterator it = _meetings.begin();
		bool inserted = false;

		//on empty list, just insert.
		if (_meetings.empty())
		{
			_meetings.push_back(meeting_1);
			return;
		}

		//list not empty, need to find the spot.

		//iterate while not reached end or found place.
		while (it != _meetings.end() && !inserted) 
		{
			//find the first meeting that is "after" meeting_1.
			//and meeting_1 does not intersect with it.
			if ((**it) == *meeting_1)//intersection
			{
				throw string("meeting intersects with another meeting");
			}

			//if found a possible place , insert there.
			if ((**it) > *meeting_1 )
			{
				_meetings.insert(it, meeting_1);
				inserted = true;
				return;
			}

			//move on
			 ++it;
		}

		//insert end if needed.
		if (!inserted && it == _meetings.end())
		{
			_meetings.insert(it, meeting_1);
			inserted = true;
		}

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


private:
	//meeting calendar is not copyable!  
	// make copy CTOR private
	DayCalendar_t(DayCalendar_t& source_cal);



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

