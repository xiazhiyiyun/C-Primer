#include <iostream>
#include <fstream>
#include <cstdio>

std::istream &fun(std::istream &in = std::cin);

int main(int argc,char **argv)
{
    if(argc > 1)
    {
        while(argc > 1)
        {
            std::ifstream in( *++argv );
            fun(in);
            --argc;
        }
        return 0;        
    }
    fun();
    return 0;
}

std::istream &fun(std::istream &in)
{
    std::string line;

    while( !getline(in,line).eof() )
        printf("%s\n",line.c_str());
    in.clear();

    return in;
}
