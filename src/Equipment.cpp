#include "Equipment.h"

Equipment::Equipment()
{
    //ctor
    pType=ProductType::Eqpmnt;//deciding Product Type
}
Equipment::Equipment(int id,std::string n,double p,double s,std::string ds,std::string cn,std::string cau,equipmentType et):Product(id,n,p,s,ds)
{

    company=cn;
    caution=cau;
    eqpType=et;
    pType=ProductType::Eqpmnt;// deciding Product Type
}
void Equipment::productDetails()
{
    // will be implemented
    std::cout.setf(std::ios::left);
    std::cout.width(8);
    std::cout<<GetID();
    std::cout.width(20);
    std::cout<<Getname();
    std::cout.width(15);
    std::cout<<GetEquipmentType();
    std::cout.width(15);
    std::cout<<Getcompany();
    std::cout.width(6);
    std::cout<<Getpurchase_price();
    std::cout.width(6);
    std::cout<<Getselling_price();
}

Equipment::~Equipment()
{
    //dtor
}

