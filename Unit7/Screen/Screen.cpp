#include "Screen.h"
#include "Window_mgr.h"
#include <string>
#include <iostream>

using std::string;

Screen Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

Screen Screen::move(pos h,pos w)
{
	cursor = h * width + w;
	return *this;
}

Screen Screen::display(std::ostream & os) 
{
	do_display(os);
	return *this;

}

const Screen & Screen::display(std::ostream & os) const 
{
	do_display(os);
	return *this;
}
