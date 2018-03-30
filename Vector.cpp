#include "Vector.h"
#include <stdlib.h>
#include <stdexcept>

vector::vector()
{
	n = 0;
	buf = NULL;
}

vector::vector(int a)
{
	buf = (int*)malloc(sizeof(int));
	if (buf == NULL)
	{
		n = 0;
		throw std::runtime_error("Memory allocation failure!");
	}
	n = 1;
	buf[0] = a;
}

vector::vector(const vector& a)
{
	n = a.n;
	if (n)
	{
		buf = (int*)malloc(sizeof(int)*n);
		if (buf == NULL)
		{
			n = 0;
			throw std::runtime_error("Memory allocation failure!");
		}
		else
			for (int i = 0; i < n; ++i)
				buf[i] = a.buf[i];
	}
	else
		buf = NULL;
}

vector& vector::operator=(const vector& a)
{
	if (this == &a)
		return *this;
	if (a.n)
	{
		int *p = (int*)malloc(sizeof(int)*a.n);
		if (p == NULL)
			throw std::runtime_error("Memory allocation failure!");
		free(buf), buf = p;
		for (int i = 0; i < n; ++i)
			buf[i] = a.buf[i];
		n = a.n;
	}
	else
		free(buf), buf = NULL, n = 0;
	return (*this);
}

bool vector::truncate(int a)
{
	if (!a)
	{
		n = 0, free(buf), buf = NULL;
		return true;
	}
	int *p = (int*)realloc(buf, sizeof(int)*a);
	if (p == NULL)
		return false;
	n = a, buf = p;
	return true;
}

int& vector::operator[](int a)
{
	if (a >= n)
	{
		int *p = (int*)realloc(buf, sizeof(int)*(a + 1));
		if (p == NULL)
			throw std::runtime_error("Memory allocation failure!");
		buf = p;
	}
	return buf[a];
}

int vector::length()
{
	return n;
}

vector::~vector()
{
	free(buf);
}