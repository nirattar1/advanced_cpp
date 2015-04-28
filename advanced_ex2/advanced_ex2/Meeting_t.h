#ifndef MEETING_T_H
#define MEETING_T_H

#include <string>
using namespace std;


template <class T> 
class Meeting_t
{

public:
	~ Meeting_t() {};
	Meeting_t(T time_start, T time_end, string subject) 
	{
		_time_start = time_start;
		_time_end = time_end;
		_subject = subject;
	};
	Meeting_t() {};
	
	//getters
	T	GetTimeStart ()		const {return _time_start;};
	T	GetTimeEnd ()		const {return _time_end;};
	string	GetSubject ()	const {return _subject;};

	//setters
	void SetTimeStart(const T & time_start) { _time_start = time_start; };
	void SetTimeEnd(const T & time_end) { _time_end = time_end; };
	void SetSubject(const string & subject) { _subject = subject; };


	//comparison operator
	//will check intersection between this meeting and other meeting.
	bool operator==(const Meeting_t<T>& other)
	{
		//TODO implement intersection
		return (other.GetTimeStart() == this->GetTimeStart());

	}

protected:
	T _time_start;
	T _time_end;
	string _subject;

};



/* Meeting_t<T> cin cout overloading */
template <class T> ostream& operator<< (ostream& os, const Meeting_t<T>& p)
{
	if (NULL == &p)
	{
		os << "\n NULL (no element)";
	}

	else
	{
		os << "\nStart time: " << p.GetTimeStart()
			<< "\nEnd time: " << p.GetTimeEnd() 
			<< "\nSubject: " << p.GetSubject() << endl << endl;
	}

	return os;
}

template <class T> istream& operator>> (istream& is, Meeting_t<T>& p)
{

	T time_start;
	T time_end;
	string subject;

	is >> time_start;
	is >> time_end;
	is >> subject;

	p.SetTimeStart(time_start);
	p.SetTimeEnd(time_end);
	p.SetSubject(subject);

	return is;
}

#endif

