#include "Salesman.h"

Salesman::Salesman()
{
    //ctor
    uType=UserType::Slsmn;
}

void Salesman::userInfo()
{
    std::cout.setf(std::ios::left);
    std::cout.width(10);
   std::cout<<GetuserID();
   std::cout.width(15);
    std::cout<<GetuserName();
    std::cout<<GetjoinDate().Getday()<<"-"<<GetjoinDate().Getmonth()<<"-"<<GetjoinDate().Getyear();


}

void Salesman::addInSales(Sales *s)
{
    std::ofstream fSales;
    fSales.open("Sales.txt",std::ios::app);

    fSales<<s->GetsalesID()<<","<<s->GetproductID()<<","<<s->GetsoldAmount()
        <<","<<s->GetSalesDate().Getday()<<","<<s->GetSalesDate().Getmonth()<<","
        <<s->GetSalesDate().Getyear()<<std::endl;

    fSales.close();
}

Salesman::~Salesman()
{
    //dtor
}
