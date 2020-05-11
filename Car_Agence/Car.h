#pragma once
#include<iostream>
#include<string>
using namespace std;
class Car
{
protected:
	int Engine_Capacity, Fuel_Tank_Capacity, Cylinders, Horsepower, Top_Speed;
	string Drive_Type, Fuel_Type, Model, Make, model;;
	float Fuel_Economy, Length, Width, Height;
public:
	void setModel(string model);
	void setMake(string make);
	void setEngine_Capacity(int engine_capacity);
	void setFuel_Tank_Capacity(int fuel_tank_capacity);
	void setCylinders(int cylinders);
	void setHorsepower(int horsepower);
	void setTop_Speed(int top_Speed);
	void setFuel_Type(string fuel_type);
	void setDrive_Type(string drive_type);
	void setFuel_Economy(float fuel_Economy);
	void setLength(float length);
	void setWidth(float width);
	void setHeight(float height);

	string getModel();
	string getMake();

	int getEngine_Capacity();

	int getFuel_Tank_Capacity();

	int getCylinders();

	int getHorsepower();

	int getTop_Speed();

	string getFuel_Type();

	string getDrive_Type();

	float getFuel_Economy();

	float getLength();

	float getWidth();

	float getHeight();




};
