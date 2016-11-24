#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>
#include "StrBlobPtr.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::weak_ptr;

bool operator==(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock();
	auto r = rhs.wptr.lock();

	if(l == r && lhs.curr == rhs.curr)
		return true;
	else 
		return false;
}

bool operator!=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
	return !eq(lhs,rhs);
}

StrBlobPtr & StrBlobPtr::operator++()
{
	check(curr,"increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr  StrBlobPtr::operator++(int)
{
	auto temp = *this;
	++*this;
	return temp;
}

StrBlobPtr & StrBlobPtr::operator--()
{
	--curr;
	check(curr,"decrement past end of StrBlobPtr");
	return *this;
}

StrBlobPtr  StrBlobPtr::operator--(int)
{
	auto temp = *this;
	--(*this);
	return temp;
}

string& StrBlobPtr::operator*() const
{
	auto p = check(curr,"derefence past end!");
	return (*p)[curr];
}

StrBlobPtr   StrBlobPtr::operator+(std::size_t sz)
{
	// check(curr+sz,"increment past end of StrBlobPtr");
	auto temp = *this;
	temp.curr += sz;
	return temp;
}

StrBlobPtr   StrBlobPtr::operator-(std::size_t sz)
{
	// check(curr-sz,"decrement past end of StrBlobPtr");
	auto temp = *this;
	temp.curr -= sz;
	return temp;
}

std::string* StrBlobPtr::operator->() const
{
	return & this->operator*();
}

string& StrBlobPtr::deref() const
{
	auto p = check(curr,"derefence past end!");
	return (*p)[curr];
}

StrBlobPtr & StrBlobPtr::incr()
{
	check(curr,"increment past end of StrBlobPtr");
	++curr;
	return *this;
}


shared_ptr<vector<string>> StrBlobPtr::check(std::size_t i,const std::string &msg) const
{
	auto sp = wptr.lock();
	if(!sp)
	{
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if(i >= sp->size())
		throw std::out_of_range(msg);
	return sp;
}

bool eq(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock();
	auto r = rhs.wptr.lock();

	if(l == r && lhs.curr == rhs.curr)
		return true;
	else 
		return false;
}

bool neq(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
	return !eq(lhs,rhs);
}

