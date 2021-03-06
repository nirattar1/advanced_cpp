#ifndef PHONEOWNER_T_H
#define PHONEOWNER_T_H

#include "TC_t.h"
#include "Observer.h"
#include <string>


class PhoneOwnerImpl_t;

class PhoneOwner_t : public Observer {
public:
	virtual ~PhoneOwner_t();
	PhoneOwner_t(const string& Impl );
	virtual void Print() const;

	//Observer implementation
	virtual void Update(Subject* ChngSubject, string topic);

protected:
	PhoneOwnerImpl_t *  _impl;
};

#endif
