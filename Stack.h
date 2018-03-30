#pragma once

class stack
{
public:
	virtual stack& operator<<(int a) = 0;
	virtual stack& operator >> (int& a) = 0;
	virtual bool operator!() = 0;
	virtual ~stack() {}
	void operator-();
	stack& operator=(stack&);
	bool operator==(stack&);
	bool operator!=(stack&);
};
