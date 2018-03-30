#include "Stack_List_Vector.h"
#include <stdlib.h>

bool stack_list_vector::operator==(stack_list_vector& a)
{
	stack *p = this, *q = &a;
	return (*p) == (*q);
}

bool stack_list_vector::operator!=(stack_list_vector& a)
{
	stack *p = this, *q = &a;
	return (*p) != (*q);
}

stack_list_vector& stack_list_vector::operator=(stack_list_vector& a)
{
	stack *p = this, *q = &a;
	*p = *q;
	return *this;
}

void stack_list_vector::reset()
{
	k = 0;
}

bool stack_list_vector::next()
{
	if (k == n)
		return false;
	++k;
	return true;
}

bool stack_list_vector::end()
{
	if (k == n)
		return true;
	return false;
}

bool stack_list_vector::ins_next(int a)
{
	int *p = (int*)realloc(buf, sizeof(int)*(n + 1));
	if (p == NULL)
		return false;
	buf = p;
	int t = n;
	while (t != k)
	{
		buf[t] = buf[t - 1];
		--t;
	}
	buf[k] = a;
	++n;
	return true;
}

bool stack_list_vector::get_next(int& a)
{
	if (k == n || !n)
		return false;
	a = buf[k];
	return true;
}

bool stack_list_vector::delete_next()
{
	if (k == n || !n)
		return false;
	int t = k + 1;
	while (t < n)
		buf[t - 1] = buf[t], ++t;
	if (n == 1) free(buf), buf = NULL;
	else
		buf = (int*)realloc(buf, sizeof(int)*(n - 1));
	--n;
	return true;
}
