#ifndef USER_H
#define USER_H
#include "Date.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Meds.h"
#include "Accessories.h"
#include "Equipment.h"
#include "ProductManager.h"
#include "Sales.h"
enum UserType{Admnstretr,Slsmn};
class User
{
    public:
        User();
        virtual ~User();


        std::string GetuserName() { return userName; }
        void SetuserName(std::string val) { userName = val; }
        char* Getpassword() { return password; }
        void Setpassword(char val[]) {
            strcpy(password,val);
//            int i;
//            for(i=0;val[i]!='\0';i++)
//            {
//                password[i]=val[i];
//            }
//            password[i]='\0';
            }

        std::string GetUserType()
        {
            if(uType==Admnstretr)
                return std::string("Administrator");
            else if(uType==Slsmn)
                return std::string("SalesMan");
            else return std::string("");
        }

        virtual void userInfo()=0;

    protected:

        std::string userName;

        UserType uType;


    private:
        char password[50];
};

#endif // USER_H
