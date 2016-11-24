#include <string>
#include <set>
#include "Message.h"
#include "Folder.h"

using std::set;
using std::string;

int main(int argc, char const *argv[])
{
	Folder folder1;
	Folder folder2;

	Message msg1("Message1");
	Message msg2("Message2");
	Message msg3("Message3");

	msg1.save(folder1);
	msg1.save(folder2);
	
	msg2.save(folder2);
	
	msg3.save(folder2);

	Message msg4("Message4");
	msg4.save(folder1);
	msg4 = msg1;
	return 0;
}