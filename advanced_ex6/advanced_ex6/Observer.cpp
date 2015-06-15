#include "Observer.h"

//implementation of observer functions.



//================================================================================
// Subject Implemenation
//================================================================================

void Subject::Attach (Observer* ob) 
{ 
		m_observers.push_back(ob); 
} 

void Subject ::Detach (Observer* ob) 
{ 
	unsigned int i=0; 
	for (i = 0; i < m_observers.size(); i++) 
		if (m_observers[i] == ob) break; 
	m_observers.erase(m_observers.begin() + i); 
} 


void Subject ::Notify ()
{ 
	for (unsigned int i = 0; i < m_observers.size(); i++) 
		(m_observers[i])->Update(this); 
}