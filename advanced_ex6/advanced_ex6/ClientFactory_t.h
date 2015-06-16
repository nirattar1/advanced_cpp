#ifndef CLIENTFACTORY_T_H
#define CLIENTFACTORY_T_H

#include <string>
#include "PhoneOwner_t.h"
#include "ClientMobile_t.h"		
#include "ClientStationary_t.h"	

using namespace std;

class ClientFactory_t
{
public:
	static PhoneOwnerImpl_t * ClientCreate(const string& Impl ) {
		PhoneOwnerImpl_t * ptrClientImpl = 0;
		if (Impl == "mobile")   
			ptrClientImpl = new ClientMobile_t(  );
		if (Impl == "stationary") 
			ptrClientImpl = new ClientStationary_t( );
		return ptrClientImpl;
	};
private:
	~ClientFactory_t();
	ClientFactory_t();
};

#endif
