#pragma once

class vector
{
protected:
	int *buf;
	int n;
public:
	vector();
	vector(int);
	vector(const vector&);
	~vector();
	int& operator[](int);
	vector& operator=(const vector&);
	bool truncate(int);
	int length();
};