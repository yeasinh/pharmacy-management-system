#include <iostream>
#include "Date.h"
#include "Product.h"
#include "Meds.h"
#include "Sales.h"
#include "User.h"
#include "Accessories.h"
#include "Equipment.h"
#include "Administrator.h"
#include "Salesman.h"
#include "ProductManager.h"
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

unordered_map<int, Meds*> Medicinedata;
unordered_map<int, Accessories*> Accessoriesdata;
unordered_map<int,Equipment*> Equipmentdata;
unordered_map<int,ProductManager*> ProductManagerdata;
unordered_map<int,Sales*> Salesdata;
unordered_map<int,int> Stockdata;// product id, total amount
unordered_map<int,Salesman*> SalesmanData;

const int medsID=75000;
const int eqpID=55000;
const int accsrsID=15000;
const int slsID=80000;
const int slsmnID=22200;

int medsCount=medsID;
int eqpCount=eqpID;
int accsrsCount=accsrsID;
int slsCount=slsID;
int slsmnCount=slsmnID;
int PMcount=0;

Administrator admin;
int current_Salesman;


void encrypt(char a[])
{
    for(int i=0;a[i]!='\0';i++)
    {
        a[i]=a[i]+5;
    }
}

void decrypt(char a[])
{
    for(int i=0;a[i]!='\0';i++)
    {
        a[i]=a[i]-5;
    }
}
void updateCountData()
{
    ofstream fCount;
    fCount.open("CountData.txt");
    fCount<<medsCount<<" "<<eqpCount<<" "<<accsrsCount<<" "<<slsCount<<" "<<slsmnCount;
    fCount.close();
}

void updateSalesmanData()
{
    ofstream fslsmn;
    fslsmn.open("Salesman.txt");

    for(auto i:SalesmanData)
    {
        char p[50];
        strcpy(p,i.second->Getpassword());
        encrypt(p);
        fslsmn<<i.second->GetuserID()<<","<<i.second->GetuserName()<<","<<p<<","<<i.second->GetjoinDate().Getday()
        <<","<<i.second->GetjoinDate().Getmonth()<<","<<i.second->GetjoinDate().Getyear()<<endl;
    }
    fslsmn.close();
}
void GetSalesmanData()
{
   ifstream fin;
   fin.open("Salesman.txt");
   string name,sid,sdd,smm,syy,sp;
   char p[50];
   int dd,mm,yy,id;


   while(!fin.eof())
   {
       getline(fin,sid,',');
       getline(fin,name,',');
       getline(fin,sp,',');
       getline(fin,sdd,',');
       getline(fin,smm,',');
       getline(fin,syy,'\n');

       if(sid!=""){
        stringstream turnid(sid),turndd(sdd),turnmm(smm),turnyy(syy);
        turnid>>id;
        turndd>>dd;
        turnmm>>mm;
        turnyy>>yy;

        strcpy(p,sp.c_str());

        decrypt(p);

        Salesman *s =new Salesman();
        s->SetuserID(id);
        s->SetuserName(name);
        s->SetjoinDate(dd,mm,yy);
        s->Setpassword(p);

        SalesmanData[id]=s;
       }
   }
   fin.close();
}
void updateAdmin()
{
    ofstream fadmn;
    fadmn.open("Administrator.txt");
    char p[50];
    strcpy(p,admin.Getpassword());
    encrypt(p);
    fadmn<<admin.GetuserName()<<" "<<p;
}
void Getadmin()
{
    ifstream fadmn;
    fadmn.open("Administrator.txt");
    string name;
    char pass[50];
    fadmn>>name>>pass;
    fadmn.close();
    admin.SetuserName(name);
    decrypt(pass);
    admin.Setpassword(pass);
}
void updateMedicine()
{
    ofstream fMedicine;
    fMedicine.open("Medicine.txt");

    for(auto i:Medicinedata)
    {
       fMedicine<<i.second->GetID()<<","<<i.second->Getname()<<","<<i.second->Getpurchase_price()<<","
    <<i.second->Getselling_price()<<","<<i.second->Getdescription()<<","
    <<i.second->GetmName()<<","<<i.second->Getcompany()<<","<<i.second->Getcaution()<<","<<i.second->GetMType()<<endl;
    }

    fMedicine.close();
}

void updateAccessories()
{
    ofstream fAccessrs;
    fAccessrs.open("Accessories.txt");

    for(auto i:Accessoriesdata)
    {
      fAccessrs<<i.second->GetID()<<","<<i.second->Getname()<<","<<i.second->Getpurchase_price()<<","
            <<i.second->Getselling_price()<<","<<i.second->Getdescription()<<","
            <<i.second->Getcompany()<<","<<i.second->GetAccsrsType()<<endl;
    }
    fAccessrs.close();
}

void updateEquipment()
{
    ofstream fEqpmnt;
    fEqpmnt.open("Equipment.txt");

    for(auto i:Equipmentdata)
    {
        fEqpmnt<<i.second->GetID()<<","<<i.second->Getname()<<","<<i.second->Getpurchase_price()<<","
        <<i.second->Getselling_price()<<","<<i.second->Getdescription()<<","
        <<i.second->Getcompany()<<","<<i.second->Getcaution()<<","<<i.second->GetEqpmentType()<<endl;
    }
    fEqpmnt.close();

}

void updateProductManager()
{
    ofstream fproManger;
    fproManger.open("ProductManager.txt");

    for(auto i:ProductManagerdata)
    {
        fproManger<<i.second->GetProductID()<<","<<i.second->GetProduct_Amount()<<","
        <<i.second->Getexp_Date().Getday()<<","<<i.second->Getexp_Date().Getmonth()<<","
        <<i.second->Getexp_Date().Getyear()<<endl;
    }
    fproManger.close();

}
void updateSalesdata()
{
    ofstream fSales;
    fSales.open("Sales.txt");

    for(auto i:Salesdata)
    {
        fSales<<i.second->GetsalesID()<<","<<i.second->GetproductID()<<","<<i.second->GetsoldAmount()
        <<","<<i.second->GetSalesDate().Getday()<<","<<i.second->GetSalesDate().Getmonth()<<","
        <<i.second->GetSalesDate().Getyear()<<endl;
    }

    fSales.close();
}

void GetStockdata()
{
    for(auto i:ProductManagerdata)
    {
        Stockdata[i.second->GetProductID()]+=i.second->GetProduct_Amount();
    }
}

void GetCountData()
{
    ifstream fCount;
    fCount.open("CountData.txt");
    fCount>>medsCount>>eqpCount>>accsrsCount>>slsCount>>slsmnCount;
    fCount.close();
}
void GetMedicinedata()
{
   ifstream fin;
   fin.open("Medicine.txt");
   string name,des,com,cau,mdtyp,sid,spp,ssp,mnam;
   int id,mt;
   double pp,sp;

   MedicineType medType;

   while(!fin.eof())
   {
       getline(fin,sid,',');
       getline(fin,name,',');
       getline(fin,spp,',');
       getline(fin,ssp,',');
       getline(fin,des,',');
       getline(fin,mnam,',');
       getline(fin,com,',');
       getline(fin,cau,',');
       getline(fin,mdtyp,'\n');

       if(sid!=""){
        stringstream turnid(sid),turnpp(spp),turnsp(ssp),turnmtyp(mdtyp);
        turnid>>id;
        turnpp>>pp;
        turnsp>>sp;
        turnmtyp>>mt;
        if(mt==0) medType=Liquid;
        else if(mt==1) medType=Tablet;
        else if(mt==2) medType=Capsule;
        else if(mt==3) medType=Suppository;
        else if(mt==4) medType=Drop;
        else if(mt==5) medType=Inhaler;
        else if(mt==6) medType=Injection;


       Meds *m= new Meds(id,name,pp,sp,des,mnam,com,cau,medType);
      Medicinedata[id]=m;

       ////will have to change later

       }
    }
    fin.close();
}

void GetEquipmentdata()
{
    ifstream fin;
   fin.open("Equipment.txt");
   string name,des,com,cau,mdtyp,sid,spp,ssp;
   int id,mt;
   double pp,sp;

   equipmentType eqType;

   while(!fin.eof())
   {
       getline(fin,sid,',');
       getline(fin,name,',');
       getline(fin,spp,',');
       getline(fin,ssp,',');
       getline(fin,des,',');
       getline(fin,com,',');
       getline(fin,cau,',');
       getline(fin,mdtyp,'\n');

       if(sid!=""){
        stringstream turnid(sid),turnpp(spp),turnsp(ssp),turnmtyp(mdtyp);
        turnid>>id;
        turnpp>>pp;
        turnsp>>sp;
        turnmtyp>>mt;
        if(mt==0) eqType=syringe;
        else if(mt==1) eqType=needle;
        else if(mt==2) eqType=gloves;
        else if(mt==3) eqType=PPE;
        else if(mt==4) eqType=goggles;
        else if(mt==5) eqType=mask;
        else if(mt==6) eqType=scissor;
        else if(mt==7) eqType=blade;
        else if(mt==8) eqType=waterBag;


       Equipment *e= new Equipment(id,name,pp,sp,des,com,cau,eqType);
      Equipmentdata[id]=e;

       ////will have to change later

       }
    }
    fin.close();
}

void GetAccessoriesdata()
{
   ifstream fin;
   fin.open("Accessories.txt");
   string name,des,com,mdtyp,sid,spp,ssp;
   int id,mt;
   double pp,sp;

   AccessoriesType AcType;

   while(!fin.eof())
   {
       getline(fin,sid,',');
       getline(fin,name,',');
       getline(fin,spp,',');
       getline(fin,ssp,',');
       getline(fin,des,',');
       getline(fin,com,',');
       getline(fin,mdtyp,'\n');

       if(sid!=""){
        stringstream turnid(sid),turnpp(spp),turnsp(ssp),turnmtyp(mdtyp);
        turnid>>id;
        turnpp>>pp;
        turnsp>>sp;
        turnmtyp>>mt;
        if(mt==0) AcType=Handwash;
        else if(mt==1) AcType=Sanitizer;
        else if(mt==2) AcType=Tissue;
        else if(mt==3) AcType=Shampoo;
        else if(mt==4) AcType=Chocolate;

       Accessories *a= new Accessories(id,name,pp,sp,des,com,AcType);
      Accessoriesdata[id]=a;

       ////will have to change later

       }
    }
    fin.close();
}
void GetProductManagerdata()
{
    ifstream fin;
   fin.open("ProductManager.txt");
   string sid,samnt,sdd,smm,syy;
   int id,amn,dd,mm,yy;


   while(!fin.eof())
   {

       getline(fin,sid,',');
       getline(fin,samnt,',');
       getline(fin,sdd,',');
       getline(fin,smm,',');
       getline(fin,syy,'\n');

       if(sid!=""){
        stringstream turnid(sid),turnpp(samnt),turnsp(sdd),turnmtyp(smm),turnyr(syy);//turning string into integer
        turnid>>id;
        turnpp>>amn;
        turnsp>>dd;
        turnmtyp>>mm;
        turnyr>>yy;


        Date ex(dd,mm,yy);
       ProductManager *p= new ProductManager(id,amn,ex);
      ProductManagerdata[PMcount]=p;

       PMcount++;////will have to change later

       }
    }
    fin.close();
}

void GetSalesdata()
{
  ifstream fin;
   fin.open("Sales.txt");
   string sid,spid,samnt,sdd,smm,syy;
   int id,amn,dd,mm,yy,pid;


   while(!fin.eof())
   {

       getline(fin,sid,',');
       getline(fin,spid,',');
       getline(fin,samnt,',');
       getline(fin,sdd,',');
       getline(fin,smm,',');
       getline(fin,syy,'\n');

       if(sid!=""){
        stringstream turnid(sid),turnpp(samnt),turnsp(sdd),turnmtyp(smm),turnyr(syy),turnpid(spid);//turning string into integer
        turnid>>id;
        turnpid>>pid;
        turnpp>>amn;
        turnsp>>dd;
        turnmtyp>>mm;
        turnyr>>yy;


        Sales *s= new Sales();
        s->SetSalesInfo(id,pid,amn,dd,mm,yy);
        Salesdata[id]=s;

      ////will have to change later

       }
    }
    fin.close();
}


void SearchForProduct()
{
    cout<<"ENTER NAME: ";
    string val;
    getchar();
    getline(cin,val);
    int l=val.length();
    int mcnt=0,ecnt=0,acnt=0;
    cout<<endl;
    cout<<"MEDICINES: "<<endl;
    for(auto i:Medicinedata)
    {
       string pnam=i.second->Getname();
       pnam=pnam.substr(0,l);
       string mnam=i.second->GetmName();
       mnam=mnam.substr(0,l);
       if(val.compare(pnam)==0 || val.compare(mnam)==0)
       {
           mcnt++;
           if(mcnt==1)
           {
               cout<<"PRODUCT ID     PRODUCT NAME        MED NAME            MED TYPE       AMOUNT    PURCHASE PRICE  SELLING PRICE"<<endl;
               cout<<"----------     ------------        --------            --------       ------    --------------  -------------"<<endl;
           }
           cout.setf(ios::left);
           cout.width(15);
           cout<<i.second->GetID();
           cout.width(20);
           cout<<i.second->Getname();
           cout.width(20);
           cout<<i.second->GetmName();
           cout.width(15);
           cout<<i.second->GetMedicineType();
           cout.width(10);
           cout<<Stockdata[i.second->GetID()];
           cout.width(16);
           cout<<i.second->Getpurchase_price();
           cout<<i.second->Getselling_price();
           cout<<endl;
       }
    }
    if(mcnt==0)
    {
        cout<<"NO PRODUCT FOUND"<<endl;
    }

    cout<<endl;
    cout<<"EQUIPMENTS: "<<endl;
    for(auto i:Equipmentdata)
    {
       string pnam=i.second->Getname();
       pnam=pnam.substr(0,l);

       if(val.compare(pnam)==0)
       {
           ecnt++;
           if(ecnt==1)
           {
               cout<<"PRODUCT ID     PRODUCT NAME        EQP TYPE       AMOUNT    PURCHASE PRICE  SELLING PRICE"<<endl;
               cout<<"----------     ------------        --------       ------    --------------  -------------"<<endl;
           }
           cout.setf(ios::left);
           cout.width(15);
           cout<<i.second->GetID();
           cout.width(20);
           cout<<i.second->Getname();
           cout.width(15);
           cout<<i.second->GetEquipmentType();
           cout.width(10);
           cout<<Stockdata[i.second->GetID()];
           cout.width(16);
           cout<<i.second->Getpurchase_price();
           cout<<i.second->Getselling_price();
           cout<<endl;
       }
    }
    if(ecnt==0)
    {
        cout<<"NO PRODUCT FOUND"<<endl;
    }

    cout<<endl;
    cout<<"ACCESSORIES: "<<endl;
    for(auto i:Accessoriesdata)
    {
       string pnam=i.second->Getname();
       pnam=pnam.substr(0,l);

       if(val.compare(pnam)==0)
       {
           acnt++;
           if(acnt==1)
           {
               cout<<"PRODUCT ID     PRODUCT NAME        ACS TYPE       AMOUNT    PURCHASE PRICE  SELLING PRICE"<<endl;
               cout<<"----------     ------------        --------       ------    --------------  -------------"<<endl;
           }
           cout.setf(ios::left);
           cout.width(15);
           cout<<i.second->GetID();
           cout.width(20);
           cout<<i.second->Getname();
           cout.width(15);
           cout<<i.second->GetAccessoriesType();
           cout.width(10);
           cout<<Stockdata[i.second->GetID()];
           cout.width(16);
           cout<<i.second->Getpurchase_price();
           cout<<i.second->Getselling_price();
           cout<<endl;
       }
    }
    if(acnt==0)
    {
        cout<<"NO PRODUCT FOUND"<<endl;
    }
}

void SellProducts()
{
  system("CLS");
           cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
           cout<<"1.MEDICINE"<<endl<<"2.EQUIPMENT"<<endl<<"3.ACCESSORIES"<<endl;
            int pTyp;
            cin>>pTyp;

            if(pTyp!=1 && pTyp!=2 && pTyp!=3){
                cout<<"WRONG KEY"<<endl;
            }
            else
            {
                cout<<"ENTER PRODUCT ID: ";
                int pid;
                cin>>pid;
                if(pTyp==1)
                {
                    if(!Medicinedata.count(pid))
                    {
                        cout<<"NO PRODUCT WITH THIS ID"<<endl;
                    }
                    else
                    {
                        if(!Stockdata.count(pid))
                        {
                            cout<<"THIS PRODUCT IS OUT OF STOCK"<<endl;
                        }
                        else{
                            cout<<"PRODUCT AMOUNT: ";
                            int amnt;
                            cin>>amnt;
                            if(amnt> Stockdata[pid])
                            {
                                cout<<"DOES NOT HAVE ENOUGH"<<endl;
                            }
                            else{
                            cout<<"PID     PRODUCT NAME        MEDICINE NAME       MTYPE          COMPANY        PPU   SPU   AMOUNT  TOTAL PRICE"<<endl;
                            cout<<"---     ------------        -------------       -----          -------        ---   ---   ------  -----------"<<endl;
                            Medicinedata[pid]->productDetails();
                            cout.setf(ios::left);
                            cout.width(8);
                            cout<<amnt;
                            cout<<amnt*Medicinedata[pid]->Getselling_price()<<endl;
                            cout<<"1.CONFIRM"<<endl<<"2.CANCEL"<<endl;
                                int t,key=-1;
                                cin>>t;
                                if(t==1)
                                {
                                   Stockdata[pid]-=amnt;

                                   for(auto i:ProductManagerdata)
                                   {
                                       if(i.second->GetProductID()==pid && i.second->GetProduct_Amount()>=amnt)
                                       {
                                           i.second->SetProduct_Amount(i.second->GetProduct_Amount()-amnt);
                                           if(i.second->GetProduct_Amount()==0)
                                           {
                                               key=i.first;
                                           }
                                           break;
                                       }
                                   }
                                   if(key!=-1)
                                   {
                                      ProductManagerdata.erase(key);
                                   }
                                   updateProductManager();
                                   slsCount++;
                                   Sales *s=new Sales(slsCount,pid,amnt);
                                   Salesman sman;
                                   sman.addInSales(s);
                                   cout<<"------------SUCCESSFULLY SOLD-------------"<<endl;
                                   delete s;

                                }
                                else if(t==2)
                                {
                                    //something will be here
                                }
                            }
                        }
                    }
                }
                else if(pTyp==2)
                {
                    if(!Equipmentdata.count(pid))
                    {
                        cout<<"NO PRODUCT WITH THIS ID"<<endl;
                    }
                    else{
                        if(!Stockdata.count(pid))
                        {
                            cout<<"THIS PRODUCT IS OUT OF STOCK"<<endl;
                        }
                        else{
                            cout<<"PRODUCT AMOUNT: ";
                            int amnt;
                            cin>>amnt;
                            if(amnt> Stockdata[pid])
                            {
                                cout<<"DOES NOT HAVE ENOUGH"<<endl;
                            }
                            else{
                            cout<<"PID     PRODUCT NAME        ETYPE          COMPANY        PPU   SPU   AMOUNT  TOTAL PRICE"<<endl;
                            cout<<"---     ------------        -----          -------        ---   ---   ------  -----------"<<endl;
                             Equipmentdata[pid]->productDetails();
                            cout.setf(ios::left);
                            cout.width(8);
                            cout<<amnt;
                            cout<<amnt*Equipmentdata[pid]->Getselling_price()<<endl;
                                cout<<"1.CONFIRM"<<endl<<"2.CANCEL"<<endl;
                                int t,key=-1;
                                cin>>t;
                                if(t==1)
                                {
                                   Stockdata[pid]-=amnt;

                                   for(auto i:ProductManagerdata)
                                   {
                                       if(i.second->GetProductID()==pid && i.second->GetProduct_Amount()>=amnt)
                                       {
                                           i.second->SetProduct_Amount(i.second->GetProduct_Amount()-amnt);
                                           if(i.second->GetProduct_Amount()==0)
                                           {
                                               key=i.first;
                                           }
                                           break;
                                       }
                                   }
                                   if(key!=-1)
                                   {
                                      ProductManagerdata.erase(key);
                                   }
                                   updateProductManager();
                                   slsCount++;
                                   Sales *s=new Sales(slsCount,pid,amnt);
                                   Salesman sman;
                                   sman.addInSales(s);
                                   cout<<"------------SUCCESSFULLY SOLD-------------"<<endl;
                                   delete s;

                                }
                                else if(t==2)
                                {
                                    //something will be here
                                }
                            }
                        }
                    }
                }
                else{
                    if(!Accessoriesdata.count(pid))
                    {
                        cout<<"NO PRODUCT WITH THIS ID"<<endl;
                    }
                    else
                    {
                        if(!Stockdata.count(pid))
                        {
                            cout<<"THIS PRODUCT IS OUT OF STOCK"<<endl;
                        }
                        else{
                            cout<<"PRODUCT AMOUNT: ";
                            int amnt;
                            cin>>amnt;
                            if(amnt> Stockdata[pid])
                            {
                                cout<<"DOES NOT HAVE ENOUGH"<<endl;
                            }
                            else{
                                cout<<"PID     PRODUCT NAME        ATYPE          COMPANY        PPU   SPU   AMOUNT  TOTAL PRICE"<<endl;
                                cout<<"---     ------------        -----          -------        ---   ---   ------  -----------"<<endl;
                             Accessoriesdata[pid]->productDetails();
                            cout.setf(ios::left);
                            cout.width(8);
                            cout<<amnt;
                            cout<<amnt*Accessoriesdata[pid]->Getselling_price()<<endl;
                                cout<<"1.CONFIRM"<<endl<<"2.CANCEL"<<endl;
                                int t,key=-1;
                                cin>>t;
                                if(t==1)
                                {
                                   Stockdata[pid]-=amnt;

                                   for(auto i:ProductManagerdata)
                                   {
                                       if(i.second->GetProductID()==pid && i.second->GetProduct_Amount()>=amnt)
                                       {
                                           i.second->SetProduct_Amount(i.second->GetProduct_Amount()-amnt);
                                           if(i.second->GetProduct_Amount()==0)
                                           {
                                               key=i.first;
                                           }
                                           break;
                                       }
                                   }
                                   if(key!=-1)
                                   {
                                      ProductManagerdata.erase(key);
                                   }
                                   updateProductManager();
                                   slsCount++;
                                   Sales *s=new Sales(slsCount,pid,amnt);
                                   Salesman sman;
                                   sman.addInSales(s);
                                   cout<<"------------SUCCESSFULLY SOLD-------------"<<endl;
                                   delete s;

                                }
                                else if(t==2)
                                {
                                    //something will be here
                                }
                            }
                        }
                    }
                }

            }
            updateCountData();
}
char globalAdminPass[50];
char globalSalesPass[50];
void loginPassword(int chooseUsr)
{
    char pass[50];
    int i=0;
    char a;
    for(i=0;;)
    {
        a=getch();

        if(a=='\b' && i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            pass[i]='\0';
            break;
        }
        if((a>='a' && a<='z')||(a>='A' && a<='Z')||(a>='0' && a<='9'))
            {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
    }

    if(chooseUsr==1)
    {
        strcpy(globalAdminPass,pass);
    }
    else if(chooseUsr==2)
    {
        strcpy(globalSalesPass,pass);
    }

}

bool Adminlogin()
{
   system("CLS");
cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
cout<<"LOG IN AS ADMINISTRATOR"<<endl;

cout<<"ENTER USERNAME: ";
string n;
cin>>n;
char p[50];
cout<<"ENTER PASSWORD: ";

loginPassword(1);


cout<<"password debug"<<endl;
if(n.compare(admin.GetuserName())==0 && strcmp(globalAdminPass,admin.Getpassword())==0)
{
    return true;
}
else return false;
}

bool SalesManlogin()
{
    GetSalesmanData();
    system("CLS");
cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
cout<<"LOG IN AS SALESMAN"<<endl;
int cnt=0;
cout<<"ENTER USERNAME: ";
string n;
cin>>n;
char p[50];
cout<<"ENTER PASSWORD: ";
loginPassword(2);
for(auto i:SalesmanData)
{
    if(n.compare(i.second->GetuserName())==0 && strcmp(globalSalesPass,i.second->Getpassword())==0)
    {
        current_Salesman=i.second->GetuserID();
        cnt++;
        break;

    }
}
SalesmanData.clear();
if(cnt==1)
{

    return true;
}
else if(cnt==0)
{
    return false;
}
}

int main()
{



Getadmin();
GetCountData();
GetMedicinedata();
GetEquipmentdata();
GetAccessoriesdata();
GetProductManagerdata();
GetStockdata();
for(;;)
{
    system("CLS");
cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
cout<<"1.ADMINISTRATOR"<<endl<<"2.SALESMAN"<<endl<<"3.EXIT"<<endl;
int usr;
cin>>usr;
if(usr==1)
{
    if(Adminlogin())
    {

    for(;;)
    {
        system("CLS");
   cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl;
   cout<<endl
   <<"1.ADD A NEW PRODUCT"<<endl
   <<"2.DELETE A PRODUCT"<<endl
   <<"3.UPDATE THE PRICING OF A PRODUCT"<<endl
   <<"4.ADD PRODUCTS TO STOCK"<<endl
   <<"5.PRODUCT INFO"<<endl
   <<"6.SALES INFO"<<endl
   <<"7.EXPIRED PRODUCTS"<<endl
   <<"8.CHANGE PASSWORD"<<endl
   <<"9.ADD A NEW SALESMAN"<<endl
   <<"10.SHOW SALESMAN INFO"<<endl
   <<"11.LOGOUT"<<endl;


   int admnKey;
   cin>>admnKey;
   if(admnKey==1)
   {
       //add a new product
       system("CLS");
   cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
   cout<<"ADD A NEW PRODUCT"<<endl;
   cout<<"1.MEDICINE"<<endl<<"2.EQUIPMENT"<<endl<<"3.ACCESSORIES"<<endl;
   int pTyp;
   cin>>pTyp;
       if(pTyp==1)
       {
           //Medicine
           system("CLS");
           cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
           cout<<"ADD A NEW PRODUCT"<<endl;
           cout<<"ENTER THE FOLLOWING INFORMATION"<<endl<<endl;
           int id,m;
           double pp,sp;
           string n,mn,com,cau,des;
           MedicineType mt;

           id=medsCount+1;//setting up the id
           medsCount++;//id should be increased

            getchar();//FOR SOLVING THE NEW LINE PROBLEM OF GETLINE FUNCTION
           cout<<"ENTER PRODUCT NAME: ";
           getline(cin,n);

           cout<<"ENTER MEDICINE NAME: ";
           getline(cin,mn);

           cout<<"ENTER COMPANY NAME: ";
           getline(cin,com);

           cout<<"ENTER DESCRIPTION:(LESS THEN 30 CHARACTERS) ";
           getline(cin,des);

           cout<<"ENTER CAUTION OF THE MEDICINE: ";
           getline(cin,cau);

           cout<<"CHOOSE THE MEDICINE TYPE FROM BELOW"<<endl;
           cout<<"1.LIQUID 2.TABLET 3.CAPSULE 4.SUPPOSITORY 5.DROP 6.INHALER 7.INJECTION"<<endl;
           cin>>m;
           if(m==1) mt=Liquid;
            else if(m==2) mt=Tablet;
            else if(m==3) mt=Capsule;
            else if(m==4) mt=Suppository;
            else if(m==5) mt=Drop;
            else if(m==6) mt=Inhaler;
            else if(m==7) mt=Injection;

            cout<<"ENTER PURCHASE PRICE: ";
            cin>>pp;
            cout<<"ENTER SELLING PRICE: ";
            cin>>sp;

            Meds *mdcn= new Meds(id,n,pp,sp,des,mn,com,cau,mt);

            cout<<endl;
            cout.width(20);
            cout<<" PRODUCT NAME: ";
            cout<<n<<endl;
            cout.width(20);
            cout<<" MEDICINE NAME: ";
            cout<<mn<<endl;
            cout.width(20);
            cout<<" COMPANY NAME: ";
            cout<<com<<endl;
            cout.width(20);
            cout<<" DESCRIPTION: ";
            cout<<des<<endl;
            cout.width(20);
            cout<<" CAUTION: ";
            cout<<cau<<endl;
            cout.width(20);
            cout<<" MEDICINE TYPE: ";
            cout<<mdcn->GetMedicineType()<<endl;
            cout.width(20);
            cout<<" PERCHASE PRICE: ";
            cout<<pp<<endl;
            cout.width(20);
            cout<<" SELLING PRICE: ";
            cout<<sp<<endl;

            cout<<"1.CONFIRM 2.CANCEL"<<endl;
            int lt;
            cin>>lt;
            if(lt==1)
            {

                Medicinedata[mdcn->GetID()]=mdcn;
                Administrator a;
                a.addInMedicine(mdcn);

                updateCountData();
                cout<<"--------PRODUCT ADDED SUCCESSFULLY--------"<<endl;

            }




       }
       else if(pTyp==2)
       {
           //Equipment
           system("CLS");
           cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
           cout<<"ADD A NEW PRODUCT"<<endl;
           cout<<"ENTER THE FOLLOWING INFORMATION"<<endl;
           int id,m;
           double pp,sp;
           string n,com,cau,des;
           equipmentType eqType;

           id=eqpCount+1;//setting up the id
           eqpCount++;//id should be increased

            getchar();//FOR SOLVING THE NEW LINE PROBLEM OF GETLINE FUNCTION
           cout<<"ENTER PRODUCT NAME: ";
           getline(cin,n);

           cout<<"ENTER COMPANY NAME: ";
           getline(cin,com);

           cout<<"ENTER DESCRIPTION:(LESS THEN 30 CHARACTERS) ";
           getline(cin,des);

           cout<<"ENTER CAUTION OF THE EQUIPMENT: ";
           getline(cin,cau);

           cout<<"CHOOSE THE EQUIPMENT TYPE FROM BELOW"<<endl;
           cout<<"1.syringe 2.needle 3.gloves 4.PPE 5.goggles 6.mask 7.scissor 8.blade 9.waterBag"<<endl;
           cin>>m;
           if(m==1) eqType=syringe;
        else if(m==2) eqType=needle;
        else if(m==3) eqType=gloves;
        else if(m==4) eqType=PPE;
        else if(m==5) eqType=goggles;
        else if(m==6) eqType=mask;
        else if(m==7) eqType=scissor;
        else if(m==8) eqType=blade;
        else if(m==9) eqType=waterBag;

            cout<<"ENTER PURCHASE PRICE: ";
            cin>>pp;
            cout<<"ENTER SELLING PRICE: ";
            cin>>sp;

            Equipment *eqp= new Equipment(id,n,pp,sp,des,com,cau,eqType);

            cout<<endl;
            cout.width(20);
            cout<<" PRODUCT NAME: ";
            cout<<n<<endl;
            cout.width(20);
            cout<<" COMPANY NAME: ";
            cout<<com<<endl;
            cout.width(20);
            cout<<" DESCRIPTION: ";
            cout<<des<<endl;
            cout.width(20);
            cout<<" CAUTION: ";
            cout<<cau<<endl;
            cout.width(20);
            cout<<" EQUIPMENT TYPE: ";
            cout<<eqp->GetEquipmentType()<<endl;
            cout.width(20);
            cout<<" PERCHASE PRICE: ";
            cout<<pp<<endl;
            cout.width(20);
            cout<<" SELLING PRICE: ";
            cout<<sp<<endl;

            cout<<"1.CONFIRM 2.CANCEL"<<endl;
            int lt;
            cin>>lt;
            if(lt==1)
            {

            Equipmentdata[eqp->GetID()]=eqp;
            Administrator a;
            a.addInEquipment(eqp);

            updateCountData();
            cout<<"--------PRODUCT ADDED SUCCESSFULLY--------"<<endl;

            }


       }
       else if(pTyp==3)
       {
           //Accessories
           system("CLS");
           cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
           cout<<"ADD A NEW PRODUCT"<<endl;
           cout<<"ENTER THE FOLLOWING INFORMATION"<<endl;
           int id,m;
           double pp,sp;
           string n,com,des;
           AccessoriesType AcType;

           id=accsrsCount+1;//setting up the id
           accsrsCount++;//id should be increased

            getchar();//FOR SOLVING THE NEW LINE PROBLEM OF GETLINE FUNCTION
           cout<<"ENTER PRODUCT NAME: ";
           getline(cin,n);

           cout<<"ENTER COMPANY NAME: ";
           getline(cin,com);

           cout<<"ENTER DESCRIPTION:(LESS THEN 30 CHARACTERS) ";
           getline(cin,des);

           cout<<"CHOOSE THE ACCESSORIES TYPE FROM BELOW"<<endl;
           cout<<"1.Handwash 2.Sanitizer 3.Tissue 4.Shampoo 5.Chocolate"<<endl;
           cin>>m;
           if(m==1) AcType=Handwash;
        else if(m==2) AcType=Sanitizer;
        else if(m==3) AcType=Tissue;
        else if(m==4) AcType=Shampoo;
        else if(m==5) AcType=Chocolate;
            cout<<"ENTER PURCHASE PRICE: ";
            cin>>pp;
            cout<<"ENTER SELLING PRICE: ";
            cin>>sp;
            Accessories *acs= new Accessories(id,n,pp,sp,des,com,AcType);

            cout<<endl;
            cout.width(20);
            cout<<" PRODUCT NAME: ";
            cout<<n<<endl;
            cout.width(20);
            cout<<" COMPANY NAME: ";
            cout<<com<<endl;
            cout.width(20);
            cout<<" DESCRIPTION: ";
            cout<<des<<endl;
            cout.width(20);
            cout<<" ACCESSORIES TYPE: ";
            cout<<acs->GetAccessoriesType()<<endl;
            cout.width(20);
            cout<<" PERCHASE PRICE: ";
            cout<<pp<<endl;
            cout.width(20);
            cout<<" SELLING PRICE: ";
            cout<<sp<<endl;

            cout<<"1.CONFIRM 2.CANCEL"<<endl;
            int lt;
            cin>>lt;
            if(lt==1)
            {


            Accessoriesdata[acs->GetID()]=acs;
            Administrator a;
            a.addInAccessories(acs);

            updateCountData();
            cout<<"--------PRODUCT ADDED SUCCESSFULLY--------"<<endl;

            }

       }
       cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();

   }
   else if(admnKey==2)
   {
       //delete a product
       system("CLS");
           cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
           cout<<"DELETE A PRODUCT"<<endl;

           cout<<endl;
           cout<<"1.MEDICINE"<<endl<<"2.EQUIPMENT"<<endl<<"3.ACCESSORIES"<<endl;
            int pTyp;
            cin>>pTyp;

            if(pTyp!=1 && pTyp!=2 && pTyp!=3){
                cout<<"WRONG KEY"<<endl;
            }
            else
            {
                cout<<"ENTER PRODUCT ID: ";
                int pid;
                cin>>pid;

                if(pTyp==1)
                {
                    if(!Medicinedata.count(pid))
                    {
                        cout<<"NO PRODUCT WITH THIS ID"<<endl;
                    }
                    else
                    {
                        cout<<"PID     PRODUCT NAME        MEDICINE NAME       MTYPE          COMPANY        PPU   SPU"<<endl;
                        cout<<"---     ------------        -------------       -----          -------        ---   ---"<<endl;
                        Medicinedata[pid]->productDetails();
                        cout<<endl;
                        cout<<"1.DELETE"<<" "<<"2.CANCEL"<<endl;
                        int dType;
                        cin>>dType;
                        if(dType==1)
                        {
                            Medicinedata.erase(pid);
                            updateMedicine();
                            //deleting the record from the stock
                            if(Stockdata.count(pid))
                            {
                                Stockdata.erase(pid);
                            }
                            for(int i=0;i<=PMcount;i++)
                            {
                                if(ProductManagerdata.count(i))
                                {
                                    if(ProductManagerdata[i]->GetProductID()==pid)
                                    {
                                        ProductManagerdata.erase(i);
                                    }
                                }
                            }
                            updateProductManager();
                            cout<<"-----------SUCCESSFULLY DELETED-------------"<<endl;

                        }

                    }
                }
                else if(pTyp==2)
                {
                    if(!Equipmentdata.count(pid))
                    {
                        cout<<"NO PRODUCT WITH THIS ID"<<endl;
                    }
                    else{
                    cout<<"PID     PRODUCT NAME        ETYPE          COMPANY        PPU   SPU"<<endl;
                    cout<<"---     ------------        -----          -------        ---   ---"<<endl;
                    Equipmentdata[pid]->productDetails();
                    cout<<endl;
                    cout<<"1.DELETE"<<" "<<"2.CANCEL"<<endl;
                        int dType;
                        cin>>dType;
                        if(dType==1)
                        {
                            Equipmentdata.erase(pid);
                            updateEquipment();
                            //deleting the record from the stock
                            if(Stockdata.count(pid))
                            {
                                Stockdata.erase(pid);
                            }
                            for(int i=0;i<=PMcount;i++)
                            {
                                if(ProductManagerdata.count(i))
                                {
                                    if(ProductManagerdata[i]->GetProductID()==pid)
                                    {
                                        ProductManagerdata.erase(i);
                                    }
                                }
                            }
                            updateProductManager();
                            cout<<"-----------SUCCESSFULLY DELETED-------------"<<endl;

                        }
                    }
                }
                else{
                    if(!Accessoriesdata.count(pid))
                    {
                        cout<<"NO PRODUCT WITH THIS ID"<<endl;
                    }
                    else
                    {
                        cout<<"PID     PRODUCT NAME        ATYPE          COMPANY        PPU   SPU"<<endl;
                        cout<<"---     ------------        -----          -------        ---   ---"<<endl;
                        Accessoriesdata[pid]->productDetails();
                        cout<<endl;
                        cout<<"1.DELETE"<<" "<<"2.CANCEL"<<endl;
                        int dType;
                        cin>>dType;
                        if(dType==1)
                        {
                            Accessoriesdata.erase(pid);
                            updateAccessories();
                            //deleting the record from the stock
                            if(Stockdata.count(pid))
                            {
                                Stockdata.erase(pid);
                            }
                            for(int i=0;i<=PMcount;i++)
                            {
                                if(ProductManagerdata.count(i))
                                {
                                    if(ProductManagerdata[i]->GetProductID()==pid)
                                    {
                                        ProductManagerdata.erase(i);
                                    }
                                }
                            }
                            updateProductManager();
                            cout<<"-----------SUCCESSFULLY DELETED-------------"<<endl;

                        }
                    }
                }

            }
            cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();
   }
   else if(admnKey==3)
   {
       //update the pricing of
       system("CLS");
           cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
            cout<<"UPDATE THE PRICING OF A PRODUCT"<<endl;

            cout<<endl;
           cout<<"1.MEDICINE"<<endl<<"2.EQUIPMENT"<<endl<<"3.ACCESSORIES"<<endl;
            int pTyp;
            cin>>pTyp;

            if(pTyp!=1 && pTyp!=2 && pTyp!=3){
                cout<<"WRONG KEY"<<endl;
            }
            else
            {
                cout<<"ENTER PRODUCT ID: ";
                int pid;
                cin>>pid;
                if(pTyp==1)
                {
                    if(!Medicinedata.count(pid))
                    {
                        cout<<"NO PRODUCT WITH THIS ID"<<endl;
                    }
                    else
                    {
                       cout<<"ENTER THE NEW PURCHASE PRICE: ";
                       double pp;
                       cin>>pp;
                       cout<<"ENTER THE NEW SELLING PRICE: ";
                       double sp;
                       cin>>sp;
                       Medicinedata[pid]->Setpurchase_price(pp);
                       Medicinedata[pid]->Setselling_price(sp);
                       updateMedicine();
                       cout<<"-----------SUCCESSFULLY UPDATED-------------"<<endl;

                    }
                }
                else if(pTyp==2)
                {
                    if(!Equipmentdata.count(pid))
                    {
                        cout<<"NO PRODUCT WITH THIS ID"<<endl;
                    }
                    else{
                        cout<<"ENTER THE NEW PURCHASE PRICE: ";
                       double pp;
                       cin>>pp;
                       cout<<"ENTER THE NEW SELLING PRICE: ";
                       double sp;
                       cin>>sp;
                       Equipmentdata[pid]->Setpurchase_price(pp);
                       Equipmentdata[pid]->Setselling_price(sp);
                       updateEquipment();
                       cout<<"-----------SUCCESSFULLY UPDATED-------------"<<endl;

                    }
                }
                else{
                    if(!Accessoriesdata.count(pid))
                    {
                        cout<<"NO PRODUCT WITH THIS ID"<<endl;
                    }
                    else
                    {
                       cout<<"ENTER THE NEW PURCHASE PRICE: ";
                       double pp;
                       cin>>pp;
                       cout<<"ENTER THE NEW SELLING PRICE: ";
                       double sp;
                       cin>>sp;
                       Accessoriesdata[pid]->Setpurchase_price(pp);
                       Accessoriesdata[pid]->Setselling_price(sp);
                       updateAccessories();
                       cout<<"-----------SUCCESSFULLY UPDATED-------------"<<endl;

                    }
                }

            }
            cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();
   }
   else if(admnKey==4)
   {
       //add product to stock
       system("CLS");
           cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
           cout<<"ADD PRODUCTS TO STOCK"<<endl;

           cout<<endl;
           cout<<"1.MEDICINE"<<endl<<"2.EQUIPMENT"<<endl<<"3.ACCESSORIES"<<endl;
            int pTyp;
            cin>>pTyp;

            if(pTyp!=1 && pTyp!=2 && pTyp!=3){
                cout<<"WRONG KEY"<<endl;
            }
            else
            {
                cout<<"ENTER PRODUCT ID: ";
                int pid;
                cin>>pid;
                if(pTyp==1)
                {
                    if(!Medicinedata.count(pid))
                    {
                        cout<<"NO PRODUCT WITH THIS ID"<<endl;

                    }
                    else
                    {
                        cout<<"PRODUCT AMOUNT: ";
                        int amnt;
                        cin>>amnt;
                        cout<<"EXPIRED DATE:(DD MM YYYY) ";
                        int dd,mm,yy;
                        cin>>dd>>mm>>yy;
                        Date d(dd,mm,yy);
                        ProductManager *p=new ProductManager(pid,amnt,d);
                        ProductManagerdata[PMcount]=p;
                        PMcount++;
                        Administrator a;
                        a.addInProductManager(p);
                        //adding this amount to StockData
                        Stockdata[pid]+=amnt;
                        cout<<"---------SUCCESSFULLY ADDED TO THE STOCK----------"<<endl;


                    }
                }
                else if(pTyp==2)
                {
                    if(!Equipmentdata.count(pid))
                    {
                        cout<<"NO PRODUCT WITH THIS ID"<<endl;

                    }
                    else{
                        cout<<"PRODUCT AMOUNT: ";
                        int amnt;
                        cin>>amnt;
                        cout<<"EXPIRED DATE:(DD MM YYYY) ";
                        int dd,mm,yy;
                        cin>>dd>>mm>>yy;
                        Date d(dd,mm,yy);
                        ProductManager *p=new ProductManager(pid,amnt,d);
                        ProductManagerdata[PMcount]=p;
                        PMcount++;
                        Administrator a;
                        a.addInProductManager(p);
                        //adding this amount to StockData
                        Stockdata[pid]+=amnt;
                        cout<<"---------SUCCESSFULLY ADDED TO THE STOCK----------"<<endl;


                    }
                }
                else{
                    if(!Accessoriesdata.count(pid))
                    {
                        cout<<"NO PRODUCT WITH THIS ID"<<endl;

                    }
                    else
                    {
                        cout<<"PRODUCT AMOUNT: ";
                        int amnt;
                        cin>>amnt;
                        cout<<"EXPIRED DATE:(DD MM YYYY) ";
                        int dd,mm,yy;
                        cin>>dd>>mm>>yy;
                        Date d(dd,mm,yy);
                        ProductManager *p=new ProductManager(pid,amnt,d);
                        ProductManagerdata[PMcount]=p;
                        PMcount++;
                        Administrator a;
                        a.addInProductManager(p);
                        //adding this amount to StockData
                        Stockdata[pid]+=amnt;
                        cout<<"---------SUCCESSFULLY ADDED TO THE STOCK----------"<<endl;

                    }
                }

            }
            cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();

   }
   else if(admnKey==5)
   {
       //product info
        system("CLS");
           cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
           cout<<"PRODUCT INFO"<<endl;
       cout<<"1.SEARCH"<<endl<<"2.SHOW ALL PRODUCTS"<<endl;
       int it;
       cin>>it;
       if(it==1)
       {
           system("CLS");
           cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
           cout<<"PRODUCT INFO"<<endl;
           SearchForProduct();
           cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
       }
       else if(it==2)
       {
       system("CLS");
           cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
           cout<<"PRODUCT INFO"<<endl;
           cout<<"MEDICINES: "<<endl;
           if(Medicinedata.empty())
           {
               cout<<"NO RECORDS"<<endl;

           }
           else
           {
                cout<<"PID     PRODUCT NAME        MEDICINE NAME       MTYPE          COMPANY        PPU   SPU   TOTAL AMOUNT"<<endl;
                cout<<"---     ------------        -------------       -----          -------        ---   ---   ------------"<<endl;
                for(int i=medsID+1;i<=medsCount;i++)
                    {
                        if(Medicinedata.count(i))
                            {
                                Medicinedata[i]->productDetails();
                                cout<<Stockdata[i];
                                cout<<endl;
                            }
                    }
                cout<<endl;
           }

           cout<<"EQUIPMENTS:"<<endl;
           if(Equipmentdata.empty())
           {
              cout<<"NO RECORDS"<<endl;
           }
           else
            {
                cout<<"PID     PRODUCT NAME        ETYPE          COMPANY        PPU   SPU   TOTAL AMOUNT"<<endl;
                cout<<"---     ------------        -----          -------        ---   ---   ------------"<<endl;
                for(int i=eqpID+1;i<=eqpCount;i++)
                    {
                        if(Equipmentdata.count(i))
                        {
                            Equipmentdata[i]->productDetails();
                            cout<<Stockdata[i];
                            cout<<endl;
                        }
                    }
                cout<<endl;
            }
           cout<<"ACCESSORIES:"<<endl;
           if(Accessoriesdata.empty())
           {
               cout<<"NO RECORDS"<<endl;
           }
           else
           {
                cout<<"PID     PRODUCT NAME        ATYPE          COMPANY        PPU   SPU   TOTAL AMOUNT"<<endl;
                cout<<"---     ------------        -----          -------        ---   ---   ------------"<<endl;
                for(int i=accsrsID+1;i<=accsrsCount;i++)
                {
                    if(Accessoriesdata.count(i))
                    {
                        Accessoriesdata[i]->productDetails();
                        cout<<Stockdata[i];
                        cout<<endl;
                    }
                }
                cout<<endl;
           }
           cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();

       }


   }
   else if(admnKey==6)
   {
       //sales info
        system("CLS");
   cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
   cout<<"SALES INFO"<<endl;
       GetSalesdata();
       cout<<"ENTER DATE: (DD MM YYYY) ";
       int dd,mm,yy;
       int cnt=0;
       cin>>dd>>mm>>yy;
       Date d(dd,mm,yy);
       for(auto i:Salesdata)
       {
           if(i.second->GetSalesDate()==d)
           {
               cnt++;
               if(cnt==1)
               {
                   cout<<"SALES ID  PRODUCT ID   PRODUCT NAME        PRODUCT TYPE   SOLD AMOUNT    DATE"<<endl;
                   cout<<"--------  ----------   ------------        ------------   -----------    ----"<<endl;
               }
               cout.setf(ios::left);
               cout.width(10);
               cout<<i.first;
               cout.width(13);
               cout<<i.second->GetproductID();
               cout.width(20);
               if(Medicinedata.count(i.second->GetproductID()))
               {
                   cout<<Medicinedata[i.second->GetproductID()]->Getname();
                   cout.width(15);
                   cout<<Medicinedata[i.second->GetproductID()]->GetproductType();

               }
               else if(Equipmentdata.count(i.second->GetproductID()))
               {
                   cout<<Equipmentdata[i.second->GetproductID()]->Getname();
                   cout.width(15);
                   cout<<Equipmentdata[i.second->GetproductID()]->GetproductType();
               }
               else if(Accessoriesdata.count(i.second->GetproductID()))
               {
                   cout<<Accessoriesdata[i.second->GetproductID()]->Getname();
                   cout.width(15);
                   cout<<Accessoriesdata[i.second->GetproductID()]->GetproductType();
               }
               cout.width(15);
               cout<<i.second->GetsoldAmount();
               cout<<i.second->GetSalesDate().Getday()<<"-"<<i.second->GetSalesDate().Getmonth()<<"-"<<i.second->GetSalesDate().Getyear();
              cout<<endl;
           }
       }
       if(cnt==0)
       {
           cout<<"NO RECORDS"<<endl;
       }
       Salesdata.clear();
       cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();
   }
   else if(admnKey==7)
   {

       //expired product
       system("CLS");
   cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl<<endl;
   cout<<"EXPIRED PRODUCTS"<<endl;
       unordered_map <int,int> storekey;
       int cnt=0;
       for(auto i:ProductManagerdata)
       {
           if(i.second->isExpired())
           {
               storekey[cnt]=i.first;
              cnt++;
              if(cnt==1)
              {
                  cout<<"PRODUCT ID     PRODUCT NAME        AMOUNT    EXP-DATE"<<endl;
                  cout<<"----------     ------------        ------    --------"<<endl;
              }
              cout.setf(ios::left);
              cout.width(15);
              cout<<i.second->GetProductID();
              cout.width(20);
              int pi=i.second->GetProductID();
              if(Medicinedata.count(pi))
              {
                  cout<<Medicinedata[pi]->Getname();
              }
              else if(Equipmentdata.count(pi))
              {
                  cout<<Equipmentdata[pi]->Getname();
              }
              else if(Accessoriesdata.count(pi))
              {
                  cout<<Accessoriesdata[pi]->Getname();
              }
              cout.width(10);
              cout<<i.second->GetProduct_Amount();
              cout<<i.second->Getexp_Date().Getday()<<"-"<<i.second->Getexp_Date().Getmonth()<<"-"<<i.second->Getexp_Date().Getyear();
              cout<<endl;
           }
       }
       if(cnt==0)
       {
           cout<<"NO EXPIRED PRODUCT FOUND"<<endl;
       }
       else if(cnt>0)
       {
           cout<<endl<<"1.DELETE THESE PRODUCTS  2.CANCEL"<<endl;
           int t;
           cin>>t;
           if(t==1)
           {
                for(auto i:storekey)
                {
                    int key=ProductManagerdata[i.second]->GetProductID();
                    int amnt=ProductManagerdata[i.second]->GetProduct_Amount();
                    Stockdata[key]-=amnt;

                    ProductManagerdata.erase(i.second);
                }
                updateProductManager();
                cout<<"----------SUCCESSFULLY DELETED------------"<<endl;
           }

       }
       cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();

   }
   else if(admnKey==8)
   {
       //change pass
       system("CLS");
    cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl;
    cout<<endl;
    cout<<"PASSWORD MUST BE ALPHANUMERIC"<<endl<<endl;
        cout<<"ENTER PREVIOUS PASSWORD: ";
        char p[50];
        loginPassword(1);
        if(strcmp(globalAdminPass,admin.Getpassword())==0)
        {
            char np[50],cp[50];
            cout<<endl<<"ENTER NEW PASSWORD: ";
            //strcpy(np,loginPassword());
            cin>>np;
            cout<<endl<<"CONFIRM PASSWORD: ";
            //strcpy(cp,loginPassword());
            cin>>cp;
            if(strcmp(np,cp)==0)
            {
                admin.Setpassword(np);

                updateAdmin();
                cout<<endl<<"------------SUCCESSFULLY CHANGED--------------"<<endl;
            }
            else
            {
                cout<<endl<<"DOES NOT MATCH"<<endl;
            }
        }
        else
        {
            cout<<endl<<"INVALID PASSWORD"<<endl;

        }

        cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();
   }
   else if(admnKey==9)
   {
       //add new salesman
        GetSalesmanData();
        system("CLS");
    cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl;
    cout<<endl;
    cout<<"ADD A NEW SALESMAN"<<endl;
    string n;
    char p[50],cp[50];
    int dd,mm,yy;
    cout<<"ENTER USERNAME: ";
    cin>>n;
     cout<<"(PASSWORD MUST BE ALPHANUMERIC)"<<endl;
     cout<<"ENTER PASSWORD: ";
     //strcpy(p,loginPassword());
     cin>>p;
     cout<<endl<<"CONFRIM PASSWORD: ";
     //strcpy(cp,loginPassword());
     cin>>cp;
     if(strcmp(p,cp)==0)
     {
         cout<<endl<<"ENTER JOINING DATE: (DD MM YYYY) ";
             cin>>dd>>mm>>yy;
             Salesman *s =new Salesman();
             slsmnCount++;
             updateCountData();
             s->SetuserID(slsmnCount);
             s->SetuserName(n);
             s->SetjoinDate(dd,mm,yy);
             s->Setpassword(p);
             SalesmanData[slsmnCount]=s;
             updateSalesmanData();
             cout<<"-------------SUCCESSFULLY ADDED--------------"<<endl;

     }
     else
     {
         cout<<endl<<"DOES NOT MATCH"<<endl;
     }
     SalesmanData.clear();
     cout<<"PRESS ANY KEY TO GO BACK"<<endl;
    getchar();
    getchar();

   }
   else if(admnKey==10)
   {
       //show salesman info
       GetSalesmanData();
        system("CLS");
    cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl;
    cout<<endl;
    cout<<"SALESMAN INFO"<<endl;
    if(SalesmanData.empty())
    {
        cout<<"NO RECORDS"<<endl;
    }
    else{
        cout<<"SALES ID  NAME           JOIN DATE"<<endl;
        cout<<"--------  ----           ---------"<<endl;
        for(auto i:SalesmanData)
        {
            i.second->userInfo();
            cout<<endl;
        }
        SalesmanData.clear();
    }

    cout<<"PRESS ANY KEY TO GO BACK"<<endl;
    getchar();
    getchar();
   }
   else if(admnKey==11)
   {
       break;
   }
   else{
        cout<<"WRONG KEY"<<endl;
        cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();

    }

    }
}
else
{
    cout<<endl<<"INVALID USERNAME OR PASSWORD"<<endl;
    cout<<"PRESS ANY KEY TO GO BACK"<<endl;
    getchar();
    getchar();
}
}

else if(usr==2)
{
    if(SalesManlogin())
    {

    for(;;)
    {
    system("CLS");
    cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl;
    cout<<endl;
    cout<<"1.SEARCH"<<endl<<"2.SELL"<<endl<<"3.CHANGE PASSWORD"<<endl<<"4.LOGOUT"<<endl;
    int sType;
    cin>>sType;
    if(sType==1)
    {
        system("CLS");
    cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl;
    cout<<endl;
        SearchForProduct();
        cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
    }
    else if(sType==2)
    {
        system("CLS");
    cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl;
    cout<<endl;
        SellProducts();
        cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();
    }
    else if(sType==3)
    {
        GetSalesmanData();
        system("CLS");
    cout<<"--------------------PHARMACY MANAGMENT SYSTEM-----------------------"<<endl;
    cout<<endl;
     cout<<"PASSWORD MUST BE ALPHANUMERIC"<<endl<<endl;
        cout<<"ENTER PREVIOUS PASSWORD: ";
        char p[50];
        loginPassword(1);
        if(strcmp(globalSalesPass,SalesmanData[current_Salesman]->Getpassword())==0)
        {
            char np[50],cp[50];
            cout<<endl<<"ENTER NEW PASSWORD: ";
            //strcpy(np,loginPassword());
            cin>>np;
            cout<<endl<<"CONFIRM PASSWORD: ";
            //strcpy(cp,loginPassword());
            cin>>cp;
            if(strcmp(np,cp)==0)
            {
                SalesmanData[current_Salesman]->Setpassword(np);
                updateSalesmanData();
                cout<<endl<<"------------SUCCESSFULLY CHANGED--------------"<<endl;
            }
            else
            {
                cout<<endl<<"DOES NOT MATCH"<<endl;
            }
        }
        else
        {
            cout<<endl<<"INVALID PASSWORD"<<endl;

        }
        SalesmanData.clear();
        cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();
    }
    else if(sType==4)
    {
        break;
    }
    else{
        cout<<"WRONG KEY"<<endl;
        cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();
    }
    }

    }
    else{
       cout<<endl<<"INVALID USERNAME OR PASSWORD"<<endl;
    cout<<"PRESS ANY KEY TO GO BACK"<<endl;
    getchar();
    getchar();
    }
}
else if(usr==3)
{
    break;
}
else{
    cout<<"WRONG KEY"<<endl;
    cout<<"PRESS ANY KEY TO GO TO MENU"<<endl;
                getchar();
                getchar();
}
}


return 0;


}
