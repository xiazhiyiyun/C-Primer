#ifndef __STRBLOBPTR
#define __STRBLOBPTR
#include "StrBlob.h"

class StrBlobPtr
{
public:
	friend bool eq(const StrBlobPtr &lhs,const StrBlobPtr &rhs);
	friend bool neq(const StrBlobPtr &lhs,const StrBlobPtr &rhs);
	
	StrBlobPtr():curr(0) {}
	StrBlobPtr(StrBlob &a,size_t sz=0):wptr(a.data),curr(sz) {}
	StrBlobPtr(const StrBlob &a,size_t sz=0):wptr(a.data),curr(sz) {}
	std::string& deref() const;
	StrBlobPtr & incr();

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t,const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

bool eq(const StrBlobPtr &lhs,const StrBlobPtr &rhs);
bool neq(const StrBlobPtr &lhs,const StrBlobPtr &rhs);

#endif