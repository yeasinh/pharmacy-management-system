#include "Meds.h"

Meds::Meds()
{
    //ctor
    pType=ProductType::Mdcn;//deciding Product Type
}
Meds::Meds(int id,std::string n,double p,double s,std::string ds,std::string mn,std::string cn,std::string cau,MedicineType mt):Product(id,n,p,s,ds)
{
    mName=mn;
    company=cn;
    caution=cau;
    mType=mt;
    pType=ProductType::Mdcn;// deciding Product Type
}
void Meds::productDetails()
{
    // will be implemented
    std::cout.setf(std::ios::left);
    std::cout.width(8);
    std::cout<<GetID();
    std::cout.width(20);
    std::cout<<Getname();
    std::cout.width(20);
    std::cout<<GetmName();
    std::cout.width(15);
    std::cout<<GetMedicineType();
    std::cout.width(15);
    std::cout<<Getcompany();
    std::cout.width(6);
    std::cout<<Getpurchase_price();
    std::cout.width(6);
    std::cout<<Getselling_price();
}

Meds::~Meds()
{
    //dtor
}
