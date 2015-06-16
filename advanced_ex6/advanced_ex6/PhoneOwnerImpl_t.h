#ifndef PHONEOWNERIMPL_H
#define PHONEOWNERIMPL_H


#include "Observer.h"

class PhoneOwnerImpl_t 
{
public:
	PhoneOwnerImpl_t() {}

	virtual void	Print() = 0;
	virtual void	Update(Subject* ChngSubject) = 0;
};

#endif