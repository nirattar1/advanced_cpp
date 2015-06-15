#ifndef Container_H
#define Container_H

#include <memory>
#include <vector>
#include <list>
#include <algorithm>

#define TEMPLATE_TEMPLATE	

#ifdef TEMPLATE_TEMPLATE
template <typename T, template <typename S, typename = std::allocator<S>> class Container> class tContainer_t{
#else
template <typename T, class Container> class tContainer_t{
#endif

public:
	~tContainer_t(){}

	tContainer_t(){}

	size_t getNumOfElements() const { return cont.size(); }

	/*
	***bool isEmpty() const;***
	returns true iff container is empty
	*/
	bool isEmpty() const { return cont.empty(); }

	/*
	***void insert(T* elem);***
	inserts ekem to container
	*/
	void insert(T* elem){ cont.push_back(elem); }

	/*
	***void insert(T* elem);***
	inserts ekem to container
	*/
	T* getFirst() { 
		if (isEmpty())
			return 0;
		return cont.front(); }

	T* getLast() { 
		if (isEmpty())
			return 0; 
		return cont.back();
	}

	T* find(T val){
		findElem = &val;
		iter_t it = find_if(cont.begin(), cont.end(), compare<T>(findElem));
		if (it != cont.end())
			return *it;
		return 0;	// element was not found
	}

	T* removeElem(T val) {
		findElem = &val;
		iter_t it = find_if(cont.begin(), cont.end(), compare<T>(findElem));
		if (it == cont.end())
			return 0;
		T* m_val = *it;
		cont.erase(it);
		return m_val;
	}

	void removeAll(){
		cont.clear();
	}

	// remove and delete element with value val
	// throws int exception if such an element does not exist
	void removeAndDeleteElem(T val) {
		T* res = removeElem(val);
		if (res == 0)
			throw -1;
		delete res;
	}

	void removeAndDeleteAll() {
		for (size_t i = 0; i < getNumOfElements(); i++)
		{
			T* elem = getLast();
			cont.pop_back();
			delete elem;
		}
	}

	// assign[]
	// index must be >= 0 and < getNumOfElements
	//throws unsigned int
	T*& operator[](unsigned index){
		if (index >= getNumOfElements() || index < 0)
			throw index;
		if (typeid(cont) == typeid(vector<T*>))
			return (*(vector<T*> *)(&cont))[index];
		iter_t it = cont.begin();
		for (unsigned int i = 0; i < index; i++, it++);
		return *it;
	}

	// retrieve[]
	// index must be >= 0 and < getNumOfElements
	//throws unsigned int
	T* operator[] (unsigned index) const {
		if (index >= getNumOfElements() || index < 0)	// illegal index
			throw index;

		if (typeid(cont) == typeid(vector<T*>))
			return cont[index];
		iter_t it = cont.begin();
		for (i = 0; i <= index; i++, it++);
		return *it;
	}

private:
#ifdef TEMPLATE_TEMPLATE
	Container<T*> cont;
	typedef typename Container<T*>::iterator iter_t;

#else
	Container cont;
	typedef typename Container::iterator iter_t;
#endif

	/*
	copy ops are private to prevent copying
	*/
	tContainer_t(const tContainer_t& t);
	tContainer_t& operator= (const tContainer_t& t);

	mutable T* findElem;	//element to compare when searching for elem in the container

	iter_t myFind(T val){
		findElem = &val;
		return find_if(cont.begin(), cont.end(), compare<T>(findElem));
	}
};

//compare functor for find_if algorithm
template <typename T> struct compare{
public:
	compare(const T* elem) : m_elem(elem){}
	bool operator()(T *elem2) const{ return *m_elem == *elem2; }
private:
	const T *m_elem;
};

#endif