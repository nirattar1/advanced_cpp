#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "TC_t.h"
#include "PhoneOwner_t.h"
#include "PhoneOwnerImpl_t.h"
#include "ClientFactory_t.h"

PhoneOwner_t::~PhoneOwner_t()  
{
	delete _impl;				// delete implementation created by Factory
	//detach from subject upon destruction

	if (sbj != 0) 
	{
		sbj->Detach(this);
	}
	
	_impl=0;
}


//create new phone owner of certain type.
//will use client factory to create that type of client.
//will register the client as an observer of Telephone company.
PhoneOwner_t::PhoneOwner_t(const string& Impl ) {

	_impl = ClientFactory_t::ClientCreate(Impl);	
	// Use factory to create client over any implementations
	// If new implementations will be added the PhoneOwner_t class need not be changed !!!
	// the only change will be in Factory

	//Get telephone company , attach client to TC.
	vector<string> & topics = _impl->GetRelevantObserverTopics();
	for (std::vector<string>::iterator it = topics.begin() ; it != topics.end(); ++it)
	{
		std::cout << " attaching to topic: " << *it << endl;
		TC_t::GetInstance().Attach(this, *it);	
	}
}

void PhoneOwner_t::Print() {				// just redirection to implementation class
	_impl->Print(); 
}

void PhoneOwner_t::Update(Subject* ChngSubject, string topic) 	// just redirection to implementation class
{
	_impl->Update(ChngSubject, topic);
}