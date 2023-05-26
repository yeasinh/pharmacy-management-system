#ifndef DATE_H
#define DATE_H
#include <ctime>
#include <cmath>

class Date
{
    public:
        Date();
        ~Date();
        Date(int dd,int mm, int yy);
        int Getday() { return day; }
        void Setday(int val) { day = val; }
        int Getmonth() { return month; }
        void Setmonth(int val) { month = val; }
        int Getyear() { return year; }
        void Setyear(int val) { year = val; }
        void SetDate(int dd,int mm,int yy);
        bool operator ==(Date d);
        bool operator >(Date d);
        bool operator <(Date d);
        Date operator =(Date d);
        void GetDateFromTM();


    protected:

    private:
        int day;
        int month;
        int year;
};

#endif // DATE_H
