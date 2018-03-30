#include "Stack.h"
#include <stdlib.h>
#include <stdexcept>

void stack::operator-()
{
	int a;
	while (!(*this) == false)
		*this >> a;
}

bool stack::operator==(stack& a)
{
	if (this == &a)
		return true;
	int *p, *q, j, i = 0;
	p = q = NULL;
	bool b = true;
	while (!a == false && !(*this) == false && b)
	{
		*this >> j;
		p = (int*)realloc(p, sizeof(int)*(i + 1));
		p[i] = j;
		a >> j;
		q = (int*)realloc(q, sizeof(int)*(i + 1));
		q[i] = j;
		if (p[i] != q[i])
			b = false;
		++i;
	}
	if (!a == false || !(*this) == false)
		b = false;
	while (i>1)
	{
		j = p[i - 1];
		p = (int*)realloc(p, sizeof(int)*(i - 1));
		*this << j;
		j = q[i - 1];
		q = (int*)realloc(q, sizeof(int)*(i - 1));
		a << j;
		--i;
	}
	if (i)
	{
		j = p[0];
		free(p);
		*this << j;
		j = q[0];
		free(q);
		a << j;
	}
	return b;
}

bool stack::operator!=(stack& a)
{
	return !((*this) == a);
}

stack& stack::operator=(stack& a)
{
	if (this == &a)
		return *this;
	int *p, *v, j, i, x;
	i = j = 0;
	v = p = NULL;
	while (!(*this) == false)
	{
		*this >> x;
		v = (int*)realloc(v, sizeof(int)*(j + 1));
		v[j] = x;
		++j;
	}
	while (!a == false)
	{
		a >> x;
		p = (int*)realloc(p, sizeof(int)*(i + 1));
		p[i] = x;
		++i;
	}
	try
	{
		while (i > 1)
		{
			x = p[i - 1];
			p = (int*)realloc(p, sizeof(int)*(i - 1));
			a << x;
			--i;
			(*this) << x;
		}
		if (i)
		{
			x = p[0];
			a << x;
			free(p);
			(*this) << x;
		}
		free(v);
		return *this;
	}
	catch (std::runtime_error e)
	{
		-(*this);
		while (i > 1)
		{
			x = p[i - 1];
			p = (int*)realloc(p, sizeof(int)*(i - 1));
			a << x;
			--i;
		}
		if (i)
		{
			x = p[0];
			free(p);
			a << x;
		}
		while (j > 1)
		{
			x = v[j - 1];
			v = (int*)realloc(v, sizeof(int)*(j - 1));
			*this << x;
			--j;
		}
		if (j)
		{
			x = v[0];
			free(v);
			*this << x;
		}
		throw e;
	}
}