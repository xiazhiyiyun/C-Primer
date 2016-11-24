#include "StrBlob.h"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include "StrBlobPtr.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::initializer_list;
using std::shared_ptr;
using std::make_shared;
using std::out_of_range;

StrBlob::StrBlob(): data(make_shared<vector<string>>() ) 
{}

StrBlob::StrBlob(initializer_list<string> i1): data( make_shared<vector<string>>(i1) ) 
{}

StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this,data->size());
	return ret;
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

void StrBlob::pop_back()
{
	check(0,"pop_back on empty StrBlob!");
	data->pop_back();
}

const string & StrBlob::front() const
{
	check(0,"front on empty StrBlob!");
	return data->front();
}

string & StrBlob::front() 
{
	check(0,"front on empty StrBlob!");
	return data->front();
}

const string & StrBlob::back() const
{
	check(0,"back on empty StrBlob!");
	return data->back();	
}

string & StrBlob::back() 
{
	check(0,"back on empty StrBlob!");
	return data->back();	
}

void  StrBlob::check(size_type i,const string & meg) const
{
	if(i >= data->size())	
	{
		throw out_of_range(meg);
	}
}
