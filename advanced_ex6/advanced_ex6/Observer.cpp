#include "Observer.h"

//implementation of observer functions.



//================================================================================
// Subject Implemenation
//================================================================================

void Subject::Attach (Observer* ob, string topic) 
{ 
	//find the container of observers for topic. (if not exist create a new one)
	vector <Observer *> & obsForTopic = _topicObservers[topic];

	//add observer to that container
	obsForTopic.push_back(ob); 
} 


//detach client of ALL its topics
void Subject ::Detach (Observer* ob) 
{ 

	//run on all topics
	for (std::map<string,vector<Observer *>>::iterator it=_topicObservers.begin(); it!=_topicObservers.end(); ++it)
	{
		std::string topic = it->first;
		
		//find the container of observers for topic. 
		vector <Observer *> & obsForTopic = it->second;

		//delete observer from it.
		unsigned int i=0; 
		for (i = 0; i < obsForTopic.size(); i++) 
		{
			if (obsForTopic[i] == ob) 
				break; 
		}
		obsForTopic.erase(obsForTopic.begin() + i); 
		//print
		cout << "detached observer " << "" << "from topic:" << topic;

	}

} 

//will notify observers that subscribed to topic
void Subject ::Notify (string topic)
{ 
	//check that topic subscribers exist
	if (_topicObservers.count(topic))
	{
		//find the container of observers for topic. 
		vector <Observer *> & obsForTopic = _topicObservers[topic];

		//update all of them
		for (unsigned int i = 0; i < obsForTopic.size(); i++) 
		{
			(obsForTopic[i])->Update(this, topic); 
		}

		//print
		cout << "notified observers of topic: " << topic << endl;
	}

}