#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

//Creating a vehicle class with some basic information for a vehicle object

class Vehicle
{

private:
    int year;
    std::string make;
    std::string model;

public:
    Vehicle(); //Default constructor for class Vehicle
    //~Vehicle(); //Creating a destructor for class Vehicle
    Vehicle(int _year, std::string _make, std::string _model);

    void setYear(int _year) { year = _year; }
    int getYear() { return year; }
    void setMake(std::string _make) { make = _make; }
    std::string getMake() { return make; }
    void setModel(std::string _model) { model = _model; }
    std::string getModel() { return model; }

    friend std::ostream & operator<< (std::ostream & out, Vehicle& kickout);

};



#endif