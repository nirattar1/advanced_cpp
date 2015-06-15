
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "TException_t.h"
#include "Container_t.h"
#include "Array_t.h"
#include "List_t.h"

//-------------------------------------------------------------------

typedef enum
{
	INCORRECT_INPUT
} MainErros;

string mainErrorsStr[] = {"incorrect input"};

//-------------------------------------------------------------------

typedef enum
{
	INSERT,
	REMOVE,
	REMOVE_ALL,
	FIND,
	COUNT,
	PRINT,
	APPENND,
	PREPENR,
	EXIT
} Options;

//-------------------------------------------------------------------

string optionsName[] ={ "Insert",
						"Remove",
						"Remove All",
						"Find",
						"Count",
						"Print",
						"Append",
						"Prepend",
						"exit"}; 


//-------------------------------------------------------------------
//																			  
//						  HELP FUNCTIOMS PROTOTYPES							  	
//-------------------------------------------------------------------

void PrintOptions(void);

template<typename T> void TestInsert(Container_t<T>& _obj);
template<typename T> void TestRemove(Container_t<T>& _obj);
template<typename T> void TestRemoveAll(Container_t<T>& _obj);
template<typename T> void TestFind(Container_t<T>& _obj);
template<typename T> void TestCount(Container_t<T>& _obj);
template<typename T> void TestPrint(Container_t<T>& _obj);


//-------------------------------------------------------------------
//																			  
//						  			GLOBAL									  	
//-------------------------------------------------------------------

template <class T>
struct TestFunc
{
	static void(* const functions[])(Container_t<T>& _test);
};



template<typename T> void(* const TestFunc<T>::functions[])(Container_t<T>&)=
{
    &TestInsert<T>,
    &TestRemove<T>,
    &TestRemoveAll<T>,
    &TestFind<T>,
    &TestCount<T>,
    &TestPrint<T>
};

 

//-------------------------------------------------------------------
//																			  
//						HELP FUNCTIOMS IMPLEMENTATION						  	
//-------------------------------------------------------------------

void PrintOptions()
{
	for(int i=0; i<=EXIT ;i++)
	{
		cout << i << ". " << optionsName[i] << endl;
	}
}

//-------------------------------------------------------------------

template<typename T> void TestInsert(Container_t<T>& _obj)
{
	cout<<"please insert an item (int): "<<endl;
	int item;
	cin>>item;
	try
	{
		_obj.Insert(item);
	}
	catch(TException_t<int>& err)
	{
		cout<<err.GetDesCription();
	}	
}

//-------------------------------------------------------------------

template<typename T> 
void TestRemove(Container_t<T>& _obj)
{
	if(_obj.Count() == 0)
	{
		cout<<"no items to remove"<<endl;
		return;
	}
	cout<<"please choose an index(0-"<<(_obj.Count()-1)<<")"<<endl;
	int index;
	cin>>index;
	try
	{
		T item = _obj.Remove(index);
		cout<<"removed item is "<< item <<endl;		
	}
	catch(TException_t<int>& err)
	{
		cout<<err.GetDesCription();
	}
}

//-------------------------------------------------------------------

template<typename T> 
void TestRemoveAll(Container_t<T>& _obj)
{
	_obj.RemoveAll();
	cout<<"all items was removed"<<endl;
}

//-------------------------------------------------------------------

template<typename T> 
void TestFind(Container_t<T>& _obj)
{
	if(_obj.Count() == 0)
	{
		cout<<"no items"<<endl;
		return;
	}
	cout<<"please choose an index(0-"<<(_obj.Count()-1)<<")"<<endl;
	int index;
	cin>>index;
	try
	{
		T item = _obj.Find(index);
		cout<<"found item is "<< item <<endl;		
	}
	catch(TException_t<int>& err)
	{
		cout<<err.GetDesCription();
	}
}

//-------------------------------------------------------------------

template<typename T> 
void TestCount(Container_t<T>& _obj)
{
	cout<<"num of items is: "<<_obj.Count()<<endl;
}

/*----------------------------------------------------------------------------*/



template<typename T> 
void TestPrint(Container_t<T>& _obj)
{
	_obj.Print();	
}
 
//-------------------------------------------------------------------
//																			  
//						  			 MAIN									  	
//-------------------------------------------------------------------

int main()
{
	unsigned int	choice=0;
	unsigned int	ArrOrList; 
	Array_t<int>*	testArr;
	List_t<int>*	testList;
	Container_t<int>* test;
	
	cout<<"please choose array(0) or list(1)"<<endl;
	cin>>ArrOrList;
	while(ArrOrList > 1)
	{
		cout<<"wrong input, please enter 0 for array and 1 for list"<<endl;
		cin>>ArrOrList;	
	}
	 
	try
	{
		if(ArrOrList == 0)	// array
		{
			testArr = new Array_t<int>;
			test = testArr; 	
		}
		if(ArrOrList == 1)	//list
		{
			testList = new List_t<int>;
			test = testList; 				
		}	
	}
	catch(TException_t<int>& err)
	{
		cout<<err.GetDesCription() << endl;
	}
	
	PrintOptions();
	
	cout << endl <<"Please choose: " << endl;
	cin >> choice;		
	
	
	while(choice < EXIT)
	{
		(*TestFunc<int>::functions[choice])(*test);
	
		cout<<endl<<"/*---------------------------------------------*/" << endl;
		cout << endl <<"Please choose: " << endl;
		cin >> choice;
					
	}
	return 0;
}
