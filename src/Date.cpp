#include "Date.h"

Date::Date()
{
    day=0;
    month=0;
    year=0;
    //ctor
}
Date::Date(int dd,int mm,int yy)
{
    day=std::abs(dd);
    month=std::abs(mm);
    year=std::abs(yy);
}
void Date::SetDate(int dd, int mm,int yy)
{
    day=std::abs(dd);
    month=std::abs(mm);
    year=std::abs(yy);
}
bool Date::operator==(Date d)
{
    if(day==d.day && month==d.month && year==d.year) return true;
    else return false;
}
bool Date::operator>(Date d)
{
    if(year>d.year) return true;
    else if(year==d.year)
    {
        if(month>d.month) return true;
        else if(month==d.month)
        {
            if(day>d.day) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}
bool Date::operator<(Date d)
{
    if(year<d.year) return true;
    else if(year==d.year)
    {
        if(month<d.month) return true;
        else if(month==d.month)
        {
            if(day<d.day) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}
Date Date::operator=(Date d)
{
    day=d.day;
    month=d.month;
    year=d.year;
    return d;
}
void Date::GetDateFromTM()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    day=ltm->tm_mday;
    month=ltm->tm_mon+1;
    year=ltm->tm_year+1900;
}

Date::~Date()
{
    //dtor
}
