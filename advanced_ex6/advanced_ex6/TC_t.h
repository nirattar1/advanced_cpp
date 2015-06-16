#ifndef TC_T_H
#define TC_T_H


//TC - Telephone Company class
//is a singleton

#include "Observer.h"

 class TC_t  : public Subject  {
 
 public:
	 static TC_t & GetInstance ()
	 {
		 return _tc;
	 }

	 virtual ~TC_t() {};

 public :
	 float GetPrice () {return _price;}; 
	 void SetPrice (float newPrice) {_price = newPrice;};

	 //changes the price and notifies clients.
	 void ChangePrice (float newPrice)
	 {
		 SetPrice (newPrice );
		 Notify();
	 }

 protected:
	 float _price;

 private:
	 //static data member- the sole instance of TC.
	 static TC_t _tc;

 private:
	 TC_t (float basePrice)	{_price=basePrice;};
	 TC_t (const TC_t&);	//not to allow copy
	 void operator==(TC_t&);
 };

#endif