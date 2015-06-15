#ifndef __TCONTAINER_T_H__
#define __TCONTAINER_T_H__

#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#include <string>

#define TEMPLATE_TEMPLATE	



//Predicate (for find algorithm)
template <typename T> struct GenericCompare 
{
	//in CTOR- saves original value.
	GenericCompare (const T & elem) : original_val(elem) {};

	//compares given value to original.
	bool operator()(const T *val) const
	{ 
		return (*val == original_val); 
	}

private:
	const T original_val;
};


#ifndef TEMPLATE_TEMPLATE
template <typename T, class Container_type> 
#else
template <typename T, template <typename, typename> class Container_type>
#endif

class tContainer_t
{
public:


	// Default CTOR - call empty container
	tContainer_t () : _container () {};


	//DTOR
	virtual ~tContainer_t ()  {};


	//is empty
	bool IsEmpty () 
	{
		return (_container.empty());
	}

	//return num. of elements in container
	unsigned int Count(void) const 
	{
		return (_container.size());
	}


	//insert a new element in the end of array
	void Insert(T * elem) 
	{
		_container.push_back(elem);
	}


	//  - return first element in container
	T * GetFirst()
	{
		if (!IsEmpty())
		{
			return _container.front();
		}
		else
		{
			return 0;
		}

	}


	//	- return last  element in container
	T * GetLast()
	{
		if (!IsEmpty())
		{
			return _container.back();
		}
		else
		{
			return 0;
		}

	}


	//Find – find element in container (by value)
	T* Find( const T& elem ) 
	{
		iter_t result = std::find_if (_container.begin () , _container.end(), 
			GenericCompare <T> (elem) );
		if (result == _container.end())	//element not found
		{
			return 0;
		}
		else	//element found.
		{
			return *result;
		}
	}


	//remove specific element and returns pointer to it ( parameter is T value )
	T* RemoveVal(T elem) 
	{
		iter_t result = find_if(_container.begin(), _container.end(),
			GenericCompare<T>(elem));
		if (result == _container.end())
		{
			return 0;
		}
		else
		{
			T* found_val = *result;
			_container.erase(result);
			return found_val;
		}
	}

	//	remove all elements ( without deleting them )
	void RemoveAll()
	{
		_container.clear();
	}

	// remove and delete specific element ( parameter is T value )
	void RemoveAndDeleteVal(T elem) 
	{
		T* found = RemoveVal(elem);
		if (!found)
			throw string ("element not found.");
		delete *found;

	}

	// remove and delete all elements 
	void RemoveAndDeleteAll() 
	{
		for (unsigned int i = 0; i < Count(); i++)
		{
			T* elem = GetLast();
			cont.pop_back();
			delete *elem;
		}
	}

	// differentiates between list and vector.
	T* operator[] (unsigned int i) 
	{
		//index out of bounds.
		if (i < 0 || i >= Count())	
		{
			throw string ("tried to access container in an out of bounds index .");
		}

		//on vector , direct access
		if (typeid(_container) == typeid(vector<T*>))
		{
			return _container[i];
		}
		else	//it is list, need to traverse i elements.
		{
			iter_t it = _container.begin();

			//traverse list.
			for (unsigned int j = 0; j <= i; j++, it++);
			return *it;
		}

	}

					


private:
	//copy CTOR is private - prevent copying
	tContainer_t(const tContainer_t& _other) : _container () {}		
	//= operator is private - prevent copying
	tContainer_t& operator= (const tContainer_t& t);



#ifndef TEMPLATE_TEMPLATE
	Container_type _container;
	typedef typename Container_type::iterator iter_t;
#else
	Container_type <T *, std::allocator<T *> > _container;
	typedef typename Container_type<T*, std::allocator<T *>>::iterator iter_t;
#endif

};





#endif //__TCONTAINER_T_H__

