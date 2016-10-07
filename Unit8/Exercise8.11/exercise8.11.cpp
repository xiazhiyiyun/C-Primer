#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class PersonInfo
{
public:
	string name;
	vector<string> phones;
};

int main()
{

	ifstream in("people.txt");
	
	if(!in)
	{
		cout << "can not open file" << endl;
		return -1;
	}

	string line,word;
	istringstream record;
	std::vector<PersonInfo> vec_people;

	while(getline(in,line))
	{
		PersonInfo people;
		record.clear();
		record.str(line);

		record >> people.name;
		while( record>>word )
		{
			people.phones.push_back(word);
		}

		vec_people.push_back(people);
	}

	for(const auto &person:vec_people)
	{
		cout << person.name << endl;
		for(const auto & one: person.phones)
		{
			cout << one << endl;
		}
	}
	// for(int i = 0; i < vec_people.size();i++)
	// {
	// 	cout << vec_people[i].name << endl;
	// 	for(int j = 0; j < vec_people[i].phones.size(); ++j)
	// 	{
	// 		cout << vec_people[i].phones[j] << endl;
	// 	}
	// }
}