#include <stdlib.h>
#include <stdexcept>
#include "List.h"

void list::operator-()
{
	reset();
	while (delete_next());
}

bool list::operator==(list& a)
{
	if (this == &a)
		return true;
	int n, m, i, j, x, y;
	i = j = n = m = 0;
	bool b = true;
	while (next())
		++n;
	reset();
	while (a.next())
		++m;
	a.reset();
	get_next(x) && a.get_next(y) ? (b = x == y, ++i, ++j) : (get_next(x) ? ++i : (get_next(y) ? ++j : 0));
	while (next() || a.next())
	{
		if (end() == false && a.end() == false)
		{
			if (b)
			{
				get_next(x);
				a.get_next(y);
				b = x == y;
			}
			++i, ++j;
		}
		else
			if (!end())
				++i;
			else
				++j;
	}
	if (j != i)
		b = false;
	reset(), a.reset();
	while (i - n)
	{
		next();
		--i;
	}
	while (j - m)
	{
		a.next();
		--j;
	}
	return b;
}

bool list::operator!=(list &a)
{
	return !(*this == a);
}

list& list::operator=(list &a)
{
	if (this == &a)
		return *this;
	int m, n, j, i, x, *p = NULL;
	n = m = j = i = 0;
	while (next())
		++n;
	reset();
	while (end() == false)
	{
		next();
		++i;
	}
	if (i)
	{
		reset();
		while (j<i)
		{
			get_next(x);
			delete_next();
			p = (int*)realloc(p, sizeof(int)*(j + 1));
			p[j] = x;
			++j;
		}
		j = 0;
	}
	while (a.next())
		++m;
	a.reset();
	while (a.end() == false)
	{
		a.get_next(x);
		if (ins_next(x) == false)
		{
			if (i)
			{
				int t = i;
				-(*this);
				while (t > 1)
				{
					x = p[t];
					p = (int*)realloc(p, sizeof(int)*(t - 1));
					ins_next(x);
					--t;
				}
				x = p[0];
				free(p);
				ins_next(x);
				while (i - n)
				{
					next();
					--i;
				}
			}
			a.next();
			++j;
			while (a.end() == false)
			{
				a.next();
				++j;
			}
			a.reset();
			while (j - m)
				a.next();
			throw std::runtime_error("Memory allocation failure!");
		}
		a.next();
		next();
		++j;
	}
	free(p);
	reset(), a.reset();
	while (j - m)
	{
		a.next(), next();
		--j;
	}
	return *this;
}