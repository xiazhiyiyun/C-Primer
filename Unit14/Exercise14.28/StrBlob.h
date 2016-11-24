#ifndef __STRBLOB
#define __STRBLOB

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

class StrBlobPtr;

class StrBlob
{
public:
	friend class StrBlobPtr;
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> i1);
	~StrBlob() {}

public:
	StrBlobPtr begin();
	StrBlobPtr end();
	
	size_type size() const {return data->size();}
	bool empty() const {return data->empty();}
	
	void push_back(const std::string & s) { data->push_back(s); }
	void pop_back();
	
	std::string & back();
	const std::string & back() const;
	std::string & front();
	const std::string & front() const;

private:
	void check(size_type i,const std::string & meg) const;

private:
	std::shared_ptr<std::vector<std::string>> data;
};

#endif