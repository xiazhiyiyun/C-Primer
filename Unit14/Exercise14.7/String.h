#include <memory>
#include <iostream>
#include <string>
#include <initializer_list>
#include <utility>
#include <cstring>

class String
{
	friend std::ostream & operator<<(std::ostream &os,const String &s);
public:
	String():elements(nullptr),first_free(nullptr),cap(nullptr) {}

	String(const char *s):elements(nullptr),first_free(nullptr),cap(nullptr)
	{
		auto data  = alloc_n_copy(s,s+strlen(s));
		elements   = data.first;
		first_free = cap = data.second;
	}

	String(const String &rhs):elements(nullptr),first_free(nullptr),cap(nullptr) 
	{
		auto data  = alloc_n_copy(rhs.elements,rhs.first_free);
		elements   = data.first;
		first_free = cap = data.second;

	}
	~String() { free(); }

public:

	String & operator=(const String && rhs);
 	void push_back (const char & val) 
	{
		chk_n_alloc();
		alloc.construct(first_free++,val);
	}
	char *begin() const 		{return elements;}
	char *end() const 		{return first_free;}
	size_t size() const 		{return first_free - elements;}
	size_t capacity() const 	{return cap - elements;}

private:	
	void chk_n_alloc() 
	{ 
		if(size() == capacity()) 
			reallocate(); 
	}
	void free();
	void reallocate();
	std::pair<char *,char *> alloc_n_copy(const char *,const char *);

private:	
	static std::allocator<char> alloc;
	char *elements;
	char *first_free;
	char *cap;
};

std::ostream & operator<<(std::ostream &os,const String &s);