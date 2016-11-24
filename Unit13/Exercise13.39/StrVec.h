#include <memory>
#include <string>
#include <utility>

class StrVec
{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr) {}
	StrVec(const StrVec &rhs); 
/*	{
		std::pair<string *,string*> newalloc = alloc_n_copy(rhs.elements,rhs.first_free);
		elements   = newalloc.first;
		first_free = newalloc.second;
		cap        = first_free;
	}
*/	~StrVec() {free();}

public:
	StrVec & operator=(const StrVec && rhs);
/*	{
		//处理自赋值运算
		std::pair<string *,string*> newalloc = alloc_n_copy(rhs.elements,rhs.first_free);
		free();
		elements   = newalloc.first;
		first_free = newalloc.second;
		cap        = first_free;		
	}
*/	
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
	std::pair<std::string *,std::string *> alloc_n_copy(std::string *,std::string *);

private:	
	static std::allocator<std::string> alloc;
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};