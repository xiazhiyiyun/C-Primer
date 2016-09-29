#ifndef _SCREEN
#define _SCREEN

#include <string>
#include <iostream>
#include "Window_mgr.h"

class Screen
{
public:
	typedef std::string::size_type pos;
	friend void Window_mgr::clear(Window_mgr::ScreenIndex i);
	//friend Window_mgr;
	Screen() = default;
	Screen(pos h,pos w):height(h),width(w),contents(h*w,' ') {}	
	Screen(pos h,pos w,char c):height(h),width(w),contents(h*w,c) {}
	~Screen() {}

	Screen  set(char c);
	inline Screen & set(pos h,pos w,char c);

	char get() const { return contents[cursor]; }
	inline char get(pos h,pos w) const;
	Screen move(pos r,pos c);

	Screen display(std::ostream & os);
	const Screen & display(std::ostream & os) const;

private:
	inline void do_display(std::ostream & os) const;

private:	
	// in-class initalizer
	pos height = 0,width = 0;
	pos cursor = 0;
	std::string contents;
	// mtutable data member
	mutable int access_num;
};

inline Screen & Screen::set(pos h,pos w,char c)
{
	contents[h*width + w] = c;
	return *this;
}

inline char Screen::get(pos h,pos w) const
{
	return contents[h * width + w];
}

inline void Screen::do_display(std::ostream & os) const
{
	os << contents;
}

#endif