#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

std::ifstream &fun(std::ifstream &in);
std::istringstream &fun(std::istringstream &in);

int main(int argc,char **argv)
{  
   std::ifstream in;
   in.open("exercise8.1.cpp");
   
   if(in)
   {
        fun(in);
   }

   std::ostringstream ss;
   ss << "istringstream test!";
   
   printf("%s\n", ss.str().c_str());
   
   std::istringstream iss( ss.str() );
   fun(iss);
   
   return 0;
}

std::istringstream &fun(std::istringstream &in)
{
    std::string line;

    // printf("%s\n",in.str().c_str());

    while( in >> line,!in.eof() ) 
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
        printf("%s\n",line.c_str());
    }

    in.clear();
    return in;
}

std::ifstream &fun(std::ifstream &in)
{
    std::string line;

    while( !getline(in,line).eof() )
    {
        // printf("%s\n",line.c_str());
        std::istringstream stem(line);
        fun(stem);        
    }

    in.clear();

    return in;
}
