//a virtual class that will handle C++ input output.
//derived classes will give specific functionality - ascii or binary

#ifndef VIRTIO_T_H
#define VIRTIO_T_H


#include <iostream>
#include <string>
#include <cstdio>

class virtIO_t {

public:
	virtIO_t() {};
	
	//constructor, will open file.
	virtIO_t(const char * param_filename, const char * param_mode) 
	{
		//open file
		//char * mode = param_mode;
		char * mode = "w+";
		FILE * opened_file = fopen(param_filename, mode);
		if (opened_file == NULL)
		{
			//report error
		}

		_file = opened_file;
	};

	//destructor
	~virtIO_t()
	{
		//always flush and close.
		fflush(_file);
		fclose(_file);
	}

	//input stream operator
//	virtual operator>>(void* Buf) = 0;

	//output stream operator
//	virtual	operator<<(const void* Buf) = 0;

//	virtual void operator,(int len) = 0;


	//read 
	//virtual void read();

	////write
	//virtual void write();

private:
	FILE * _file;
	int _pos;

};

#endif
