#pragma once
#include "Stack.h"
#include "List.h"

class stack_list : private list, public stack
{
public:
	stack & operator<<(int);
	stack& operator >> (int&);
	bool operator!();
	virtual ~stack_list() {}
};