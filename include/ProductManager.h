#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H
#include "Date.h"

class ProductManager
{
    public:
        ProductManager();
        ~ProductManager();
        ProductManager(int id,int amnt,Date exp);
        int GetProductID() { return ProductID; }
        void SetProductID(int val) { ProductID = val; }
        int GetProduct_Amount() { return Product_Amount; }
        void SetProduct_Amount(int val) { Product_Amount = val; }
        Date Getexp_Date() { return exp_Date; }
        void Setexp_Date(Date val) { exp_Date = val; }
        void SetRecord(int id,int amnt,Date exp);
        bool isExpired();
        bool operator==(ProductManager p);
        ProductManager operator=(ProductManager p);

    protected:

    private:
        int ProductID;
        int Product_Amount;
        Date exp_Date;
};

#endif // PRODUCTMANAGER_H
