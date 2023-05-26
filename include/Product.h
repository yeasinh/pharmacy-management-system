#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>

enum ProductType{Mdcn,Eqpmnt,Acssris};
class Product
{
    public:
        Product();
        virtual ~Product();
        Product(int id,std::string n,double p,double s,std::string ds);
        int GetID() { return ID; }
        void SetID(int val) { ID = val; }
        std::string Getname() { return name; }
        void Setname(std::string val) { name = val; }
        std::string Getdescription() { return description; }
        void Setdescription(std::string val) { description = val; }
        void Setpurchase_price(double val){purchase_price=val;}
        double Getpurchase_price(){return purchase_price;}
        void Setselling_price(double val){
            if(val>=purchase_price)selling_price=val;
            else selling_price=purchase_price;
            }
        double Getselling_price(){return selling_price;}
        std::string GetproductType()
        {
           if(pType==Mdcn) return std::string("Medicine");
           else if(pType==Eqpmnt) return std::string("Equipment");
           else if(pType==Acssris) return std::string("Accessories");
           else return std::string("");
        }

        void Setselling_price_on_percentage(int val);
        virtual void productDetails()=0;//Pure virtual function

    protected:
        int ID;
        std::string name;
        std::string description;
        double purchase_price;
        double selling_price;
        ProductType pType;
    private:

};

#endif // PRODUCT_H
