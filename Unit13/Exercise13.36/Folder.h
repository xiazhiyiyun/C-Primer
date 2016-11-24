#include <set>

class Message;

class Folder
{
public:
	Folder() {}
	Folder(const Folder &f):messages(f.messages) {add_to_Messages(f);}
	~Folder() 
	{
		remove_to_Messages();
	}

public:
	Folder & operator=(const Folder &f)
	{
		remove_to_Messages();
		messages = f.messages;
		add_to_Messages(f);
		return *this;
	}
	void addMsg(Message *meg);
	void removeMsg(Message *meg);

private:
	void add_to_Messages(const Folder &m);
	void remove_to_Messages();

private:
	std::set<Message *>	messages;
};