#include <iostream>
#include "Stack_List_Vector.h"

std::istream& operator >> (std::istream&, stack&);
std::ostream& operator<< (std::ostream&, stack&);

int main()
{
	int i;
	do
	{
		try
		{
			stack_list_vector t, s, r;
			std::cin >> s;
			t = s;
			std::cout << t << '\n' << t << '\n';
			while (!t == false)
			{
				t >> i;
				r << i;
			}
			std::cout << t << '\n';
			std::cout << (r == s);
		}
		catch (std::runtime_error& e)
		{
			system("cls");
			std::cout << e.what() << '\n';
		}
		std::cin >> i;
	} while (i);
	return 0;
}

std::istream& operator >> (std::istream& in, stack& a)
{
	int x, i, j = 0, *v = NULL;
	while (!a == false)
	{
		a >> x;
		v = (int*)realloc(v, sizeof(int)*(j + 1));
		v[j] = x;
		++j;
	}
	in >> x;
	try
	{
		while (x)
		{
			in >> i;
			a << i;
			--x;
		}
	}
	catch (std::runtime_error e)
	{
		-a;
		while (j>1)
		{
			x = v[j];
			v = (int*)realloc(v, sizeof(int)*(j - 1));
			a << x;
			--j;
		}
		if (j)
		{
			x = v[0];
			free(v);
			a << x;
		}
		throw e;
	}
	return in;
}

std::ostream& operator << (std::ostream& out, stack& a)
{
	int *q, *p = NULL;
	int i = 0;
	while (!a == false)
	{
		q = (int*)realloc(p, sizeof(int)*(i + 1));
		if (q == NULL)
		{
			while (i > 0)
			{
				a << p[i - 1];
				--i;
			}
			free(p);
			throw std::runtime_error("Memory allocation failure!");
		}
		p = q;
		a >> p[i];
		++i;
	}
	while (i>0)
	{
		a << p[i - 1];
		out << p[i - 1] << ' ';
		--i;
	}
	free(p);
	return out;
}
