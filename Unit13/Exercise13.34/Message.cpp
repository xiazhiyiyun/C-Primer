#include <string>
#include <set>
#include <algorithm>
#include "Message.h"
#include "Folder.h"

using std::set;
using std::string;
// using std::set;
// using std::set;
// using std::set;

Message::Message(const Message &rhs):contents(rhs.contents),folders(rhs.folders)
{
	// contents = rhs.contents;
	// folders = rhs.folders;
	add_to_Folders(*this);
}

Message::~Message()
{
	remove_to_Folders();
}

Message & Message::operator=(const Message &rhs)
{
	remove_to_Folders();
	
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(*this);
	return *this;
}

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.removeMsg(this);
}

void Message::swap(Message &lhs,Message &rhs)
{
	lhs.remove_to_Folders();
	rhs.remove_to_Folders();

	using std::swap;
	swap(lhs.contents,rhs.contents);
	swap(lhs.folders,rhs.folders);

	lhs.add_to_Folders(*this);
	rhs.add_to_Folders(*this);
}

void Message::add_to_Folders(Message &meg)
{
	for(const auto val:meg.folders)	
	{
		val->addMsg(this);
	}
}

void Message::remove_to_Folders()
{
	for(const auto val:folders)	
	{
		val->removeMsg(this);
	}
}

void Message::addFold(Folder *meg)
{
	folders.insert(meg);
}

void Message::removeFold(Folder *meg)
{
	folders.erase(meg);
}
