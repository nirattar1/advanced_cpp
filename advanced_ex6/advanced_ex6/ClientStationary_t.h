#ifndef CLIENTSTATIONARY_T_H
#define CLIENTSTATIONARY_T_H

#include "PhoneOwnerImpl_t.h"

class ClientStationary_t : public PhoneOwnerImpl_t {
public:
	ClientStationary_t () 
		: PhoneOwnerImpl_t () {/*..*/ }

	virtual void Print() 
	{ 
		cout << "Stationary client." << endl;
	}

	virtual void Update (Subject * ChngSubject)
	{
		//get instance of TC , get its price
		//STATIONARY implementation
	}
};

#endif