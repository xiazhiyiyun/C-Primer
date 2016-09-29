#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <cstdio>


int main(int argc,char **argv)
{
    std::ifstream in;
    in.open("exercise8.4.cpp");
    
    if(!in)
    {
        std::cerr << "can't open the file!";
        return -1;
    }

    std::string line;
    std::vector<std::string> vec_str;

    while( in>>line )
    {
        vec_str.push_back(line);
    }

    in.close();

    std::vector<std::string>::iterator it = vec_str.begin();
    while(it != vec_str.end())
    {
        std::cout << *it << std::endl;
        ++it;
    }
}