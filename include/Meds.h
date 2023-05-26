#ifndef MEDS_H
#define MEDS_H

#include "Product.h"

enum MedicineType{Liquid,Tablet,Capsule,Suppository,Drop,Inhaler,Injection};
class Meds : public Product
{
    public:
        Meds();
        ~Meds();

        std::string GetmName() { return mName; }
        void SetmName(std::string val) { mName = val; }
        std::string Getcompany() { return company; }
        void Setcompany(std::string val) { company = val; }
        std::string Getcaution() { return caution; }
        void Setcaution(std::string val) { caution = val; }
        void SetMedicineType(MedicineType val) { mType = val; }
        MedicineType GetMType() { return mType;}
        std::string GetMedicineType()
        {
            if(mType==Liquid)
                return std::string("Liquid");
            else if(mType==Tablet)
                return std::string("Tablet");
            else if(mType==Capsule)
                return std::string("Capsule");
            else if(mType==Suppository)
                return std::string("Suppository");
            else if(mType==Drop)
                return std::string("Drop");
            else if(mType==Inhaler)
                return std::string("Inhaler");
            else if(mType==Injection)
                return std::string("Injection");
            else return std::string("");
        }
        void productDetails();
        Meds(int id,std::string n,double p,double s,std::string ds,std::string mn,std::string cn,std::string cau,MedicineType mt);

    protected:

    private:
        std::string mName;
        std::string company;
        std::string caution;
        MedicineType mType;
};

#endif // MEDS_H
