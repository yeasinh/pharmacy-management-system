#ifndef SALES_H
#define SALES_H
#include "Date.h"

class Sales
{
    public:
        Sales();
        ~Sales();

        int GetsalesID() { return salesID; }
        void SetsalesID(int val) { salesID = val; }
        int GetproductID() { return productID; }
        void SetproductID(int val) { productID = val; }
        int GetsoldAmount() { return soldAmount; }
        void SetsoldAmount(int val) { soldAmount = val; }
        Date GetSalesDate() { return salesDate; }
        Sales(int sid,int pid, int sa);
        void SetSalesInfo(int sid,int pid,int sa,int dd, int mm, int yy);

    protected:

    private:
        int salesID;
        int productID;
        int soldAmount;
        Date salesDate;
};

#endif // SALES_H
