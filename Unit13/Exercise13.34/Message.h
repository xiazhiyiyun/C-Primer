#include <iostream>
#include <string>
#include <set>
// #include "Folder.h"

class Folder;

class Message
{
	friend class Folder;
public:
	// explicit
	 Message(const std::string &s = std::string()): contents(s) { }
	Message(const Message &rhs);
	~Message();

public:
	Message & operator=(const Message &rhs);

	void save(Folder &);
	void remove(Folder &);
	void swap(Message &lhs,Message &rhs);

private:
	void add_to_Folders(Message &meg);
	void remove_to_Folders();
	
	void addFold(Folder *meg);
	void removeFold(Folder *meg);


private:
	std::string contents;
	std::set<Folder *> folders;
};