#ifndef CLIENTMOBILE_T_H
#define CLIENTMOBILE_T_H

#include "PhoneOwnerImpl_t.h"

class ClientMobile_t : public PhoneOwnerImpl_t {
public:
	ClientMobile_t () 
		: PhoneOwnerImpl_t () {/*..*/ }

	virtual void Print() 
	{ 
		cout << "Mobile client." << endl;
	}

	virtual void Update (Subject * ChngSubject)
	{
		//get instance of TC , get its price
		//MOBILE IMPLEMENTATION
	}
};

#endif