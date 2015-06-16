#ifndef PHONEOWNERIMPL_H
#define PHONEOWNERIMPL_H


#include "Observer.h"

class PhoneOwnerImpl_t 
{
public:
	PhoneOwnerImpl_t() {}

	virtual void	Print() = 0;
	virtual void	Update(Subject* ChngSubject, string topic) = 0;

	//each impl. will define its interesting topics to observe.
	virtual vector<string> GetRelevantObserverTopics () = 0;

};

#endif