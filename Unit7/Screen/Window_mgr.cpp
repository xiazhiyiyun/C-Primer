#include <vector>
#include <iostream>
#include "Screen.h"
#include "Window_mgr.h"
#include "string"

void Window_mgr::clear(ScreenIndex i) 
{
	Screen& s= vec_screen[i];
	s.contents = std::string(s.height * s.width,'*');
}
// vec_screen{Screen(8,10,'c')} 
// Window_mgr::Window_mgr():vec_screen{Screen(8,10,'c')} {}
Window_mgr::Window_mgr():vec_screen{Screen()} {}


void  Window_mgr::print(ScreenIndex i) 
{
	vec_screen[i].display(std::cout);
}

