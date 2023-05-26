#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"


class Administrator : public User
{
    public:
        Administrator();
        ~Administrator();

        void userInfo();
        void addInMedicine(Meds *m);
        void addInEquipment(Equipment *e);
        void addInAccessories(Accessories *a);
        void addInProductManager(ProductManager *p);

    protected:

    private:
};

#endif // ADMINISTRATOR_H
