#ifndef _DATE_H_INCLUDED
#define _DATE_H_INCLUDED

#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>


class Date
{
public:
	Date() = default;
	~Date() = default;
	Date(const std::string &s);

public:
	friend std::ostream  & operator<<(std::ostream &,const Date &);
	int Month()  {return month;}
	int Day()  {return day;}
	int Year()  {return year;}

private:
	bool getDateWithForm1(const std::string &s);
	bool getMonth(const std::string &str,int &mon,std::string::size_type &offset);
	bool getDate(const std::string &str,int &dat,int mon,std::string::size_type &offset);
	bool getYear(const std::string &str,int &mon,std::string::size_type &offset);
	bool isDelim(char c);

private:
	int month = 0;
	int day   = 0;
	int year  = 0;
	bool legal = false;
	const static std::vector<std::string> vec_monthName ;
	const static std::vector<std::string> vec_monthAbbr ;
	const static std::vector<int> vec_days              ;
	const static std::vector<char> vec_deli             ;
	// const static std::vector<std::string> vec_monthName = {"January","February","March","April","May","June","July ","August","September","October","November","December"};
	// const static std::vector<std::string> vec_monthAbbr = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	// const static std::vector<int> vec_days              = {31,28,31,30,31,30,31,31,30,31,30,31};
	// const static std::vector<char> vec_deli             = {'-',' ',',','/'};
};

std::ostream & operator<<(std::ostream &,const Date &);
#endif