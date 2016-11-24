#include <memory>
#include <iostream>
#include <string>
#include <algorithm>
#include <initializer_list>
#include <utility>
#include <cstring>
#include "String.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::allocator;

std::pair<char *,char *> String::alloc_n_copy(const char *st,const char *ed)
{
	char *s = alloc.allocate(ed -st);
	char *e = std::uninitialized_copy(st,ed,s);
	return std::make_pair(s,e);
}

void String::free()
{
	if(!elements)
		return;
	size_t capa = capacity();
	std::for_each(begin(),end(),[](char &p) {alloc.destroy(&p);});
	alloc.deallocate(elements,capa);
}

void String::reallocate()
{
	size_t capa = capacity() ? capacity() * 2 : 1;
	char *newdata = alloc.allocate(capa);
	char *dest    = newdata;
	char *elem    = elements;

	for(size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++,std::move(*elem++));
	}

	free();
	elements = newdata;
	first_free = dest;
	cap = elements + capa;
}

String & String::operator=(const String && rhs)
{
	std::pair<char *,char*> newalloc = alloc_n_copy(rhs.elements,rhs.first_free);
	free();
	elements   = newalloc.first;
	first_free = newalloc.second;
	cap        = first_free;		
}