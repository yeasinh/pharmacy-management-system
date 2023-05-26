#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <Product.h>

enum equipmentType{syringe , needle, gloves , PPE , goggles , mask , scissor , blade , waterBag};

class Equipment : public Product
{
    public:
        Equipment();
        ~Equipment();

        std::string Getcompany() { return company; }
        void Setcompany(std::string val) { company = val; }
        std::string Getcaution() { return caution; }
        void Setcaution(std::string val) { caution = val; }
        void SetEquipmentType(equipmentType val) { eqpType = val; }
        equipmentType GetEqpmentType(){ return eqpType;}
        std::string GetEquipmentType()
        {
            if(eqpType==syringe)
                return std::string("Syringe");
            else if(eqpType==needle)
                return std::string("Needle");
            else if(eqpType==gloves)
                return std::string("Gloves");
            else if(eqpType==PPE)
                return std::string("PPE");
            else if(eqpType==mask)
                return std::string("Mask");
            else if(eqpType==scissor)
                return std::string("Scissor");
            else if(eqpType==blade)
                return std::string("Blade");
            else if(eqpType==goggles)
                return std::string("Goggles");
            else if(eqpType==waterBag)
                return std::string("WaterBag");
            else return std::string("");
        }
        void productDetails();
        Equipment(int id,std::string n,double p,double s,std::string ds,std::string cn,std::string cau,equipmentType et);

    protected:

    private:

        std::string company;
        std::string caution;
        equipmentType eqpType;
};

#endif // EQUIPMENT_H

