#include <memory>
#include <string>
#include <utility>
#include "StrVec.h"

using std::string;
using std::allocator;

StrVec::StrVec(const StrVec &rhs) 
{
	std::pair<string *,string*> newalloc = alloc_n_copy(rhs.elements,rhs.first_free);
	elements   = newalloc.first;
	first_free = newalloc.second;
	cap        = first_free;
}

StrVec & StrVec::operator=(const StrVec && rhs)
{
	//处理自赋值运算
	std::pair<string *,string*> newalloc = alloc_n_copy(rhs.elements,rhs.first_free);
	free();
	elements   = newalloc.first;
	first_free = newalloc.second;
	cap        = first_free;		
}

void StrVec::reserve(size_t n)
{
	while(capacity() < n)
	{
		reallocate(n);
	}
}

void StrVec::resize(size_t n)
{
	if(size() > n)
	{
		while(size() > n)
		{
			alloc.destroy(--first_free);
		}

	}else if(size() < n)
	{
		while(size() < n)
		{
			push_back(string());
		}
	}
}

void StrVec::resize(size_t n,const string &s)
{
	if(size() > n)
	{
		while(size() > n)
		{
			alloc.destroy(--first_free);
		}

	}else if(size() < n)
	{
		while(size() < n)
		{
			push_back(s);
		}
	}
}


void StrVec::free()
{
	if(!elements)
		return;
	size_t capa = capacity();
	while(first_free != elements)
	{
		alloc.destroy(--first_free);
	}
	alloc.deallocate(elements,capa);
}

void StrVec::reallocate()
{
	size_t capa = capacity() ? capacity() * 2 : 1;
	string *newdata = alloc.allocate(capa);
	string *dest    = newdata;
	string *elem    = elements;

	// string *e = std::uninitialized_copy(elements,first_free,s);
	for(size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++,std::move(*elem++));
	}

	free();
	elements = newdata;
	first_free = dest;
	cap = elements + capa;
}

void StrVec::reallocate(size_t n)
{
	size_t capa = n;
	string *newdata = alloc.allocate(capa);
	string *dest    = newdata;
	string *elem    = elements;

	// string *e = std::uninitialized_copy(elements,first_free,s);
	for(size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++,std::move(*elem++));
	}

	free();
	elements = newdata;
	first_free = dest;
	cap = elements + capa;
}


std::pair<string *,string *> StrVec::alloc_n_copy(string *st,string *ed)
{
	string *s = alloc.allocate(ed -st);
	string *e = std::uninitialized_copy(st,ed,s);
	return std::make_pair(s,e);
}

