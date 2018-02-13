#include <iostream> 
#include "Vehicle.h"

Vehicle::Vehicle()
{
    year = 0;
    make = "";
    model = "";
}

Vehicle::Vehicle(int _year, std::string _make, std::string _model)
{
    year = _year;
    make = _make;
    model = _model;
}