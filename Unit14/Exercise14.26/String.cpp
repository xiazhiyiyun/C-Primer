#include <initializer_list>
#include <algorithm>
#include <iostream>
#include <utility>
#include <memory>
#include <string>
#include <cstring>
#include <stdexcept>
#include "String.h"

using std::cin;
using std::out_of_range;
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

char & String::operator[](std::size_t n)
{
	if(n < (first_free - elements))
	{
		return *(elements+n);
	}else
	{
		throw out_of_range("past out of the range");
	}
}

const char & String::operator[](std::size_t n) const
{
	if(n < (first_free - elements))
	{
		return *(elements+n);
	}else
	{
		throw out_of_range("past out of the range");
	}

}

std::ostream & operator<<(std::ostream &os,const String &s)
{
	auto start = s.elements;
	while(start != s.first_free)
	{
		cout<< *(start)++;
	}
	return os;
}

bool  operator!=(const String &s1,const String &s2)
{
	return !(s1 == s2);
}


bool  operator==(const String &s1,const String &s2)
{
	  auto start1 = s1.elements;
	  auto start2 = s2.elements;

	  while( start1 != s1.first_free && start2 != s2.first_free)
	  {
	  	if(*start1++ != *start2++)
	  		break;
	  }

	  if(start1 == s1.first_free && start2 == s2.first_free)
	  	return true;
	  return false;
}

bool operator<(const String &s1,const String &s2)
{
	  auto start1 = s1.elements;
	  auto start2 = s2.elements;

	  while( start1 != s1.first_free && start2 != s2.first_free)
	  {
	  	if(*start1++ < *start2++)
	  		return true;
	  }
	  if(start1==s1.first_free && start2 != s2.first_free)
	  	return true;
	  return false;
}

bool  operator<=(const String &s1,const String &s2)
{
	return ( s1 < s2 ) || (s1 == s2);
}

bool  operator>(const String &s1,const String &s2)
{
	return !(s1 <= s2);
}

bool  operator>=(const String &s1,const String &s2)
{
	return ( s1 > s2 )||(s1 == s2);

}