#include "Accessories.h"

Accessories::Accessories()
{
    //ctor
    pType=ProductType::Acssris;
}

Accessories::Accessories(int id,std::string n,double p,double s,std::string ds,std::string cn,AccessoriesType At ):Product(id,n,p,s,ds)
{
   // acc_name=an;
    company=cn;
    aType=At;
    pType=ProductType::Acssris;
}

void Accessories::productDetails()
{
    std::cout.setf(std::ios::left);
    std::cout.width(8);
    std::cout<<GetID();
    std::cout.width(20);
    std::cout<<Getname();
    std::cout.width(15);
    std::cout<<GetAccessoriesType();
    std::cout.width(15);
    std::cout<<Getcompany();
    std::cout.width(6);
    std::cout<<Getpurchase_price();
    std::cout.width(6);
    std::cout<<Getselling_price();
}


Accessories::~Accessories()
{
    //dtor
}

