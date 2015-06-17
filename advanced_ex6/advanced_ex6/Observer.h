#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

//Observer class with topic feature.
//each Observer attaches/detaches to specific topics of the subject.
//i.e.	observer1: "prices", "upgrades",...
//		observer2: "prices"

//================================================================================

class Subject;

class Observer {
public:
	virtual			~Observer() {}
    virtual void	Update(Subject* ChngSubject, string topic) = 0;
protected:
	Observer() {}
	Subject* sbj;
};

//================================================================================

class Subject {
public:
	virtual ~Subject() {}

    virtual void Attach(Observer* obs, string topic);
    virtual void Detach(Observer* obs);
    virtual void Notify(string topic);
protected:
	Subject() {}
private:

	map <string, vector <Observer *>> _topicObservers;

};





#endif //__OBSERVER_H__

