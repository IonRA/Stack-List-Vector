#pragma once

class list
{
public:
	virtual void reset() = 0;
	virtual bool next() = 0;
	virtual bool end() = 0;
	virtual bool ins_next(int) = 0;
	virtual bool get_next(int&) = 0;
	virtual bool delete_next() = 0;
	virtual ~list() {}
	void operator-();
	bool operator==(list&);
	bool operator!=(list&);
	list& operator=(list&);
};