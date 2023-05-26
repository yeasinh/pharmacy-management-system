#ifndef ACCESSORIES_H
#define ACCESSORIES_H

#include "Product.h"

enum AccessoriesType{Handwash,Sanitizer,Tissue,Shampoo,Chocolate};


class Accessories : public Product
{
    public:
        Accessories();
        ~Accessories();

      //  std::string GetaName(){return acc_name;}
      //  void SetaName( std::string val){acc_name=val;}
         std::string Getcompany(){return company;}
         void Setcompany( std::string val){company=val;}
          void SetAccessoriesType(AccessoriesType val)
          {
              aType=val;
          }
          AccessoriesType GetAccsrsType(){ return aType;}
           std::string GetAccessoriesType()
           {
               if(aType==Handwash)
                return  std::string("Handwash");
              else if(aType==Sanitizer)
               return  std::string("Sanitizer");
              else if(aType==Tissue)
               return  std::string("Tissue");
              else if(aType==Shampoo)
                return  std::string("Shampoo");
               else if(aType==Chocolate)
               return  std::string("Chocolate");
               else
                return  std::string(" ");
           }
           void productDetails();
           Accessories(int id,std::string n,double p,double s,std::string ds,std::string cn,AccessoriesType At);


    protected:

    private:
       // std::string acc_name;
        std::string company;
        AccessoriesType aType;

};

#endif // ACCESSORIES_H
