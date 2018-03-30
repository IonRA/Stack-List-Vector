#include "Stack_List.h"
#include <stdexcept>

stack& stack_list::operator<<(int a)
{
	while (next());
	if (!ins_next(a))
		throw std::runtime_error("Memory allocation failure!");
	return *this;
}

stack& stack_list::operator >> (int& a)
{
	int i = 0;
	reset();
	while (get_next(a))
		next(), ++i;
	reset();
	while (i > 1)
		next(), --i;
	delete_next();
	return *this;
}

bool stack_list::operator!()
{
	reset();
	return end();
}


