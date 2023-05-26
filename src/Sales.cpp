#include "Sales.h"

Sales::Sales()
{
    //ctor
}
Sales::Sales(int sid,int pid, int sa)
{
    salesID=sid;
    productID=pid;
    soldAmount=sa;
    salesDate.GetDateFromTM();//setting the date of the sale Date
}
void Sales::SetSalesInfo(int sid,int pid,int sa,int dd, int mm, int yy)
{
    salesID=sid;
    productID=pid;
    soldAmount=sa;
    salesDate.SetDate(dd,mm,yy);
}
Sales::~Sales()
{
    //dtor
}
