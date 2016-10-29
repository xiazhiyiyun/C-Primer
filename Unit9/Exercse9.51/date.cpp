#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>
#include "date.h"

using std::vector;
using std::string;
using std::ostream;
using std::cout;
using std::endl;
using std::invalid_argument;

// 1/1/1900
// Jan 1 1900
// January 1,1900c

Date::Date(const string &s)
{
	if(s.empty())
	{
		return;
	}

	if(isdigit(s[0]))
	{
		getDateWithForm1(s);
	}

	string::size_type offset = 0;
	int mon,dat,yea;
	mon = dat = yea = 0;

	if(getMonth(s,mon,offset))
	{
		if(getDate(s,dat,mon,offset))
		{
			if(getYear(s,yea,offset))
			{
				month = mon;
				day  = dat;
				year   = yea;
				legal = true;
				return;	
			}
		}
	}

	return;
}

// 11/1/1900
bool Date::getDateWithForm1(const string &s)
{
	size_t p;
	int mon,dat,yea;
	mon = dat = yea = 0;
	
	mon = stoi(s,&p);
	if( mon < 0 || mon > 12 )
	{
		return false;
	}
	
	string::size_type offset = p;
	if(isDelim(s[offset]))
	{
		offset += 1;
		dat = stoi(s.substr(offset),&p);
	}
	else
	{
		return false;
	}

	if(dat <= 0 && dat > vec_days[mon])
	{
		return false;
	}
	
	offset = offset + p;
	if(isDelim(s[offset]))
	{
		offset += 1;
		yea = stoi(s.substr(offset),&p);
	}
	
	if(s.size() > offset + p)
	{
		throw invalid_argument("illegal end!");
		return false;
	}
	month = mon;
	year  = yea;
	day   = dat;
	legal = true;

}

bool Date::getMonth(const string &str,int &mon,string::size_type &offset)
{
	vector<string>::size_type i;
	// cout << "str :" << str << endl;
	for( i = 0; i != vec_monthAbbr.size(); ++i)
	{
		if(str.compare(0,vec_monthAbbr[i].size(),vec_monthAbbr[i]) == 0)
		{
			if(str.size() > vec_monthAbbr[i].size() && isDelim(str[ vec_monthAbbr[i].size() ]))
			{
				mon = i + 1;
				// break monthAbbr and delim
				offset = vec_monthAbbr[i].size() + 1;
				return true;
			}
			break;
		}
	}
	if( vec_monthAbbr.size()==i )
	{
		return false;
	}

	if(str.compare(0,vec_monthName[i].size(),vec_monthName[i]) == 0)
	{
		if(str.size() > vec_monthName[i].size() && isDelim(str[ vec_monthName[i].size() ]))
		{
			mon = i + 1;
			// break monthName and delim
			offset = vec_monthName[i].size() + 1;
			return true;
		}

	}

	return false;
}

bool Date::getDate(const string &str,int &dat,int mon,string::size_type &offset)
{
	size_t p;
	dat = stoi(str.substr(offset),&p);
	if(dat > 0 && dat <= vec_days[mon] && str.size() > offset + p && isDelim(str[offset + p]) )
	{
		offset = offset + p + 1;
		return true;
	}else
	{
		throw invalid_argument("illegal date number!");
		return false;
	}
}

bool Date::getYear(const string &str,int &yea,string::size_type &offset)
{
	size_t p;
	yea = stoi(str.substr(offset),&p);

	if(str.size() > offset + p)
	{
		throw invalid_argument("illegal end!");
		return false;
	}
	return true;
}

bool Date::isDelim(char c)
{
	for(auto val:vec_deli)
	{
		if(val == c)
			return true;
	}
	return false;
}

ostream &operator<<(std::ostream &out,const Date &date)
{
	if(date.legal)
	{
		cout << date.year << "-" << date.month << "-" << date.day;
		return out;
	}
	return out;
}
