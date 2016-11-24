#include <memory>
#include <iostream>
#include <string>
#include <initializer_list>
#include <utility>
#include <cstring>

class String
{
public:
	String():elements(nullptr),first_free(nullptr),cap(nullptr) {}

	String(const char *s):elements(nullptr),first_free(nullptr),cap(nullptr)
	{
		auto data  = alloc_n_copy(s,s+strlen(s));
		elements   = data.first;
		first_free = cap = data.second;
	}

	String(String &&rhs):elements(nullptr),first_free(nullptr),cap(nullptr) 
	{
		std::cout << "----String(const String &&rhs)----" << std::endl;

		if(this != &rhs)
		{
			free();
			elements   = rhs.elements;
			first_free = rhs.first_free;
			cap        = rhs.cap;
		}
		rhs.elements   = nullptr;
		rhs.first_free = nullptr;
		rhs.cap        = nullptr;
	}

	String(const String &rhs):elements(nullptr),first_free(nullptr),cap(nullptr) 
	{
		std::cout << "----String(const String &rhs)----" << std::endl;
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
	// void reserve(size_t n);
	// void resize(size_t n);
	// void resize(size_t n,const char &s);

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
	// void reallocate(size_t n);
	std::pair<char *,char *> alloc_n_copy(const char *,const char *);

private:	
	static std::allocator<char> alloc;
	char *elements;
	char *first_free;
	char *cap;
};