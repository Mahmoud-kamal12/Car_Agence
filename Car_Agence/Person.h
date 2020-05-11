#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"Car.h"
using namespace std;


class Person
{
private:
    string user_name;
    string password;
public:

    void setuser(string user);
    void setpass(string pass);

    string getuser();
    string getpass();

    void show(string arr[]);
    // ========= To Add Acount To File ======== //
    virtual void addaccount(Person per) {};         // override ==>> Polymorphism 
    
    // =============== to Check User name and password =====//
    virtual bool check(Person p) { return 0; };     // override ==>> Polymorphism       
    
    // ======== To Serarch in file =========== //
    void Search(string searchWord, int& x);
    
    // ====== To Add Carinto File  =========//
    virtual void addCar(Car& car) {};               // override ==>> Polymorphism   
    
    // =========== to delet car from file 
    virtual void DeletCar(string model) {};         // override ==>> Polymorphism 
   
    // ========= to add order to fle "oeder" ===========//
    virtual void Buy(string model, Person Person) {};              // override ==>> Polymorphism 
    
    //========== to update the car informaion ========//
    virtual void updataCar(string model, Car car) {};   // override ==>> Polymorphism 
    
    // ============= to show all cars in file "Cars.txt" =========//
    void showall();

    // ======== To show order list ========== //
    virtual void orderList(Person person) {};                // override ==>> Polymorphism 
};

class Admins : public Person            // inheritance
{
public:
    void addaccount(Person per)override;
    void addCar(Car& car);
    void addCarInfoToFile(Car car);
    void fromCarToTemp(string model, int& x, int& z);
    void fromTempToCar(int& x);
    void DeletCar(string model);
    bool check(Person p);
    void updataCar(string model, Car car);
    void fromCarToTemp(string model, int& x, int& z, Car car);
    bool checkCarFound(string searchWord);


};

class users : public Person       //  inheritance
{
public:
    virtual void addaccount(Person per);
    bool check(Person p);
    void Buy(string model, Person Person);
    void orderList(Person person);
    
};


