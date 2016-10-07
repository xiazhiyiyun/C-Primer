#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <vector>

std::istringstream &fun(std::istringstream &in);

int main(int argc,char **argv)
{  
  std::ifstream in;
  in.open("exercise8.10.cpp");
 
  if(!in)
  {
  
    return -1;
  }
  std::vector<std::string> vec;
  std::string line;
  while( getline(in,line) )
  {
    vec.push_back(line);
  }

  for(int i = 0; i < vec.size(); ++i)
  {
    std::istringstream in( vec[i] );
    fun(in);
  }
  return 0;
}

std::istringstream &fun(std::istringstream &in)
{
    std::string line;

    while( in >> line) 
    {
        printf("%s\n",line.c_str());
    }

    return in;
}

// std::ifstream &fun(std::ifstream &in)
// {
//     std::string line;

//     while( !getline(in,line).eof() )
//     {
//         // printf("%s\n",line.c_str());
//         std::istringstream stem(line);
//         fun(stem);        
//     }

//     in.clear();

//     return in;
// }
