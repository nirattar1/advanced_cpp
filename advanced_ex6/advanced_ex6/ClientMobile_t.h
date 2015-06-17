#ifndef CLIENTMOBILE_T_H
#define CLIENTMOBILE_T_H

#include "PhoneOwnerImpl_t.h"

class ClientMobile_t : public PhoneOwnerImpl_t {
public:
	ClientMobile_t () 
		: PhoneOwnerImpl_t () {/*..*/ }
	virtual ~ClientMobile_t(){};

	virtual void Print() const
	{ 
		cout << "Mobile client." << endl;
	}

	vector<string> GetRelevantObserverTopics () const
	{
		vector <string> topics;
		topics.push_back(std::string("upgrades"));
		topics.push_back(std::string("price"));
		return topics;
	}

	virtual void Update (Subject * ChngSubject, string topic)
	{

		cout << "mobile client was updated for topic :" << topic << endl;


		if (topic == std::string("upgrades"))
		{
			//update upgrades
		}

		if (topic == std::string("price"))
		{
			//update price
		}

	}
};

#endif