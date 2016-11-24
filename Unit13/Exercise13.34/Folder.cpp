#include <string>
#include <set>
#include "Message.h"
#include "Folder.h"

using std::set;
using std::string;


void Folder::addMsg(Message *meg)
{
	messages.insert(meg);
}

void Folder::removeMsg(Message *meg)
{
	messages.erase(meg);
}

void Folder::add_to_Messages(const Folder &m)
{
	for(const auto val:m.messages)
	{
		val->addFold(this);
	}
}

void Folder::remove_to_Messages()
{
	for(const auto val:messages)
	{
		// val->removeFold(*this);
		val->removeFold(this);
	}
}