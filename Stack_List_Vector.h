#pragma once
#include "Stack_List.h"
#include "Vector.h"

class stack_list_vector :private vector, public stack_list
{
	int k = 0;
public:
	void reset();
	bool next();
	bool end();
	bool ins_next(int);
	bool get_next(int&);
	bool delete_next();
	bool operator==(stack_list_vector&);
	bool operator!=(stack_list_vector&);
	stack_list_vector& operator=(stack_list_vector&);
};