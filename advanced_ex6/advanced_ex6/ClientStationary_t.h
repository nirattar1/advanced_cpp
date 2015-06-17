#ifndef CLIENTSTATIONARY_T_H
#define CLIENTSTATIONARY_T_H

#include "PhoneOwnerImpl_t.h"

class ClientStationary_t : public PhoneOwnerImpl_t {
public:
	ClientStationary_t () 
		: PhoneOwnerImpl_t () {/*..*/ }
	virtual ~ClientStationary_t(){};

	virtual void Print() const
	{ 
		cout << "Stationary client." << endl;
	}


	vector<string> GetRelevantObserverTopics () const
	{
		vector <string> topics;
		topics.push_back(std::string("price"));
		return topics;
	}

	virtual void Update (Subject * ChngSubject, string topic)
	{

		//STATIONARY implementation
		
		cout << "stationary client was updated for topic :" << topic << endl;

		if (topic == std::string("price"))
		{
			//update price
			
		}

	}
};

#endif