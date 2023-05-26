#include "Product.h"


Product::Product()
{
    //ctor
}
Product::Product(int id,std::string n,double p,double s,std::string ds)
{
    ID=id;
    name=n;
    purchase_price=p;
    if(s>=purchase_price)selling_price=s;
    else selling_price=purchase_price;
    description=ds;

}
void Product::Setselling_price_on_percentage(int val)
{
    selling_price=purchase_price+(purchase_price*val)/100;
}


Product::~Product()
{
    //dtor
}
