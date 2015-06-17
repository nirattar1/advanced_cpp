#ifndef TC_T_H
#define TC_T_H


//TC - Telephone Company class
//is a singleton

#include "Observer.h"
#include <vector>
#include "PhoneOwner_t.h"

 class TC_t  : public Subject  {
 
 public:
	 static TC_t & GetInstance ()
	 {
		 return _tc;
	 }

	 virtual ~TC_t() 
	 {
		//detach and clear all clients
		 for (std::vector<PhoneOwner_t *>::iterator it = _allClients.begin() ; 
			 it != _allClients.end(); ++it)
		 {
			delete *it;
		 }
		
	 };

 public :
	 float GetPrice () const {return _price;} ; 
	 void SetPrice (float newPrice) {_price = newPrice;};

	 //changes the price and notifies clients.
	 void ChangePrice (float newPrice)
	 {
		 SetPrice (newPrice );
		 Notify(std::string("price"));
	 }

	 //adds client to TC data structure. (TC is responsible to destroy it)
	 void RegisterClient (PhoneOwner_t * client)
	 {
		_allClients.push_back(client);
	 }

 protected:
	 float _price;
	 vector<PhoneOwner_t *> _allClients;


 private:
	 //static data member- the sole instance of TC.
	 static TC_t _tc;

 private:
	 TC_t (float basePrice)	{_price=basePrice;};
	 TC_t (const TC_t&);	//not to allow copy
	 void operator==(TC_t&);
 };

#endif