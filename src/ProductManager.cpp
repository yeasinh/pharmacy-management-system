#include "ProductManager.h"
#include "Date.h"

ProductManager::ProductManager()
{
    //ctor
}
ProductManager::ProductManager(int id,int amnt,Date exp)
{
    ProductID=id;
    Product_Amount=amnt;
    exp_Date=exp;
}
void ProductManager::SetRecord(int id,int amnt,Date exp)
{
    ProductID=id;
    Product_Amount=amnt;
    exp_Date=exp;
}
bool ProductManager::isExpired()
{
    Date today;
    today.GetDateFromTM();
    if(exp_Date>today) return false;
    else return true;
}
bool ProductManager::operator==(ProductManager p)
{
    if(ProductID==p.ProductID && exp_Date==p.exp_Date) return true;//in this case the amount of product does not matter
    else return false;
}
ProductManager ProductManager::operator=(ProductManager p)
{
    ProductID=p.ProductID;
    Product_Amount=p.Product_Amount;
    exp_Date=p.exp_Date;
    return p;
}
ProductManager::~ProductManager()
{
    //dtor
}
