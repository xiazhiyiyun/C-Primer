#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdio>

std::istream &fun(std::istream &in = std::cin);

int main(int argc,char **argv)
{
   std::ifstream in;
   in.open("exercise8.1.cpp");
   
   if(in)
   {
        fun(in);
   }
   return 0;
}

std::istream &fun(std::istream &in)
{
    char c;

    while( in >> c,!in.eof() )
    {   
        if(in.bad())
            throw std::runtime_error("IO ERROR");
        if(in.fail())
        {
            std::cerr << "Input Error,Skip" << std::endl;
            in.clear();
            in.ignore(100,'\n');
            continue;
        }
        std::cout << c << std::endl;
    }

    in.clear();
    return in;
}