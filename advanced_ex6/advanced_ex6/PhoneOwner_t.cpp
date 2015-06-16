#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "TC_t.h"
#include "PhoneOwner_t.h"
#include "PhoneOwnerImpl_t.h"
#include "ClientFactory_t.h"

PhoneOwner_t::~PhoneOwner_t()  {
	delete _impl;				// delete implementation created by Factory
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
	TC_t::GetInstance().Attach(this);	
}

void PhoneOwner_t::Print() {				// just redirection to implementation class
	_impl->Print(); 
}

void PhoneOwner_t::Update(Subject* ChngSubject) 	// just redirection to implementation class
{
	_impl->Update(ChngSubject);
}