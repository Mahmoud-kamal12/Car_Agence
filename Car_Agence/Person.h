#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"Car.h"
using namespace std;

class Person            // base class (parent)
{
private:        //access specifiers
    string user_name;
    string password;
public:         //access specifiers

    void setuser(string user);
    void setpass(string pass);

    string getuser();
    string getpass();

    // ========= To Add Acount To File ======== //
    virtual void addaccount() = 0;         // override ==>> Polymorphism 
    
    // =============== to Check User name and password =====//
    virtual bool check() = 0;     // override ==>> Polymorphism       
    
    // ======== To Serarch in file =========== //
    void Search(string searchWord, int& x) ;
    
    // ============= to show  cars in file "Cars.txt" =========//
    void show(string arr[]);
};

class Admins : public Person            //inheritance(derived class or child) 
{
public:
    void addaccount()override;
    void addCar(Car& car);
    void addCarInfoToFile(Car car);
    void fromCarToTemp(string model, int& x, int& z);
    void fromTempToCar(int& x);
    void DeletCar(string model);
    bool check()override;
    void updataCar(string model, Car car);
    void fromCarToTemp(string model, int& x, int& z, Car car);
    bool checkCarFound(string searchWord);
};

class users : public Person       //  inheritance (derived class or child ) 
{
public:
    virtual void addaccount( )override;

    bool check()override;
    // ========= to add order to fle "oeder.txt" ===========//
    void Buy(string model);
    // ======== To show order list ========== //
    void orderList();
    
};