#ifndef _WINDOW_MGR
#define _WINDOW_MGR
#include <vector>

class Screen;

class Window_mgr
{
public:
	typedef std::vector<Screen>::size_type ScreenIndex;
	Window_mgr();
	~Window_mgr() = default;

	void  clear(ScreenIndex i);
	void  print(ScreenIndex i);
private:	
	//in-class initalization must use '=' or '{}' to represent
	std::vector<Screen> vec_screen;
};

#endif