#include "Car.h"

void Car::setModel(string model)
{
	Model = model;
}

void Car::setMake(string make)
{
	Make = make;
}

void Car::setEngine_Capacity(int engine_capacity)
{
	Engine_Capacity = engine_capacity;
}

void Car::setFuel_Tank_Capacity(int fuel_tank_capacity)
{
	Fuel_Tank_Capacity = fuel_tank_capacity;
}

void Car::setCylinders(int cylinders)
{
	Cylinders = cylinders;
}

void Car::setHorsepower(int horsepower)
{
	Horsepower = horsepower;

}

void Car::setTop_Speed(int top_Speed)
{
	Top_Speed = top_Speed;
}

void Car::setFuel_Type(string fuel_type)
{
	Fuel_Type = fuel_type;
}

void Car::setDrive_Type(string drive_type)
{
	Drive_Type = drive_type;
}

void Car::setFuel_Economy(float fuel_Economy)
{
	Fuel_Economy = fuel_Economy;
}

void Car::setLength(float length)
{
	Length = length;
}

void Car::setWidth(float width)
{
	Width = width;
}

void Car::setHeight(float height)
{
	Height = height;
}

string Car::getModel()
{
	return Model;
}

string Car::getMake()
{
	return Make;
}

int Car::getEngine_Capacity()
{
	return Engine_Capacity;
}

int Car::getFuel_Tank_Capacity()
{
	return Fuel_Tank_Capacity;
}

int Car::getCylinders()
{
	return Cylinders;
}

int Car::getHorsepower()
{
	return Horsepower;
}

int Car::getTop_Speed()
{
	return Top_Speed;
}

string Car::getFuel_Type()
{
	return Fuel_Type;
}

string Car::getDrive_Type()
{
	return Drive_Type;
}

float Car::getFuel_Economy()
{
	return Fuel_Economy;
}

float Car::getLength()
{
	return Length;
}

float Car::getWidth()
{
	return Width;
}

float Car::getHeight()
{
	return Height;
}


