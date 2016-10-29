 
int main(int argc, char const *argv[])
{
	ifstream in("file.txt");
	if(!in)
	{
		cout << "Error: cannot open file.txt!" << endl;
	}

	istream_iterator<string> is(in),eof;
	vector<string> vec(is,eof);
	sort(vec.begin(),vec.end());

	vector<string> vec1;
	unique_copy(vec.begin(),vec.end(),back_inserter(vec1));

	ostream_iterator<string> out(cout," ");
	copy(vec.begin(),vec.end(),out);
	cout << endl;
	cout << endl;
	copy(vec1.begin(),vec1.end(),out);
	cout << endl;

	return 0;
}