#include <memory>
#include <iostream>
#include <string>
#include <initializer_list>
#include <utility>

class StrVec
{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr) {}
	StrVec(std::initializer_list<std::string> i1);
	StrVec(const StrVec &rhs); 
	~StrVec() {free();}

public:
	StrVec & operator=(const StrVec && rhs);
	void push_back (const std::string& val) 
	{
		chk_n_alloc();
		alloc.construct(first_free++,val);
	}
	void reserve(size_t n);
	void resize(size_t n);
	void resize(size_t n,const std::string &s);
	std::string *begin() const {return elements;}
	std::string *end() const {return first_free	;}
	size_t size() const {return first_free - elements;}
	size_t capacity() const {return cap - elements;}

private:	
	void chk_n_alloc() 
	{ if(size() == capacity()) 
		reallocate(); 
	}
	void free();
	void reallocate();
	void reallocate(size_t n);
	std::pair<std::string *,std::string *> alloc_n_copy(const std::string *,const std::string *);

private:	
	static std::allocator<std::string> alloc;
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};