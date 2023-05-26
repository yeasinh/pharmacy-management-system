#ifndef SALESMAN_H
#define SALESMAN_H

#include "User.h"


class Salesman : public User
{
    public:
        Salesman();
        ~Salesman();

         void SetjoinDate(int dd,int mm, int yy)
        {
            joinDate.SetDate(dd,mm,yy);
        }
        Date GetjoinDate() { return joinDate; }
        void SetuserID(int val) { userID=val; }
        int GetuserID() { return userID; }
        void userInfo();
        void addInSales(Sales *s);

    protected:
        int userID;
        Date joinDate;

    private:
};

#endif // SALESMAN_H
