#include "Administrator.h"

Administrator::Administrator()
{
    //ctor
    uType=UserType::Admnstretr;
}



void Administrator::userInfo()
{

    std::cout<<GetuserName()<<std::endl;
    std::cout<<GetUserType()<<std::endl;
}

void Administrator::addInMedicine(Meds *m)
{
   std::ofstream fMedicine;
    fMedicine.open("Medicine.txt",std::ios::app);

    fMedicine<<m->GetID()<<","<<m->Getname()<<","<<m->Getpurchase_price()<<","
    <<m->Getselling_price()<<","<<m->Getdescription()<<","
    <<m->GetmName()<<","<<m->Getcompany()<<","<<m->Getcaution()<<","<<m->GetMType()<<std::endl;

    fMedicine.close();
}
void Administrator::addInEquipment(Equipment *e)
{
    std::ofstream fEqpmnt;
    fEqpmnt.open("Equipment.txt",std::ios::app);

    fEqpmnt<<e->GetID()<<","<<e->Getname()<<","<<e->Getpurchase_price()<<","
        <<e->Getselling_price()<<","<<e->Getdescription()<<","
        <<e->Getcompany()<<","<<e->Getcaution()<<","<<e->GetEqpmentType()<<std::endl;

    fEqpmnt.close();
}
void Administrator::addInAccessories(Accessories *a)
{
    std::ofstream fAccessrs;
    fAccessrs.open("Accessories.txt",std::ios::app);

    fAccessrs<<a->GetID()<<","<<a->Getname()<<","<<a->Getpurchase_price()<<","
            <<a->Getselling_price()<<","<<a->Getdescription()<<","
            <<a->Getcompany()<<","<<a->GetAccsrsType()<<std::endl;

    fAccessrs.close();
}
void Administrator::addInProductManager(ProductManager *p)
{
    std::ofstream fproManger;
    fproManger.open("ProductManager.txt",std::ios::app);

    fproManger<<p->GetProductID()<<","<<p->GetProduct_Amount()<<","
        <<p->Getexp_Date().Getday()<<","<<p->Getexp_Date().Getmonth()<<","
        <<p->Getexp_Date().Getyear()<<std::endl;

    fproManger.close();
}

Administrator::~Administrator()
{
    //dtor
}
