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

std::ostream & operator<< (std::ostream & out, Vehicle& kickout)
{
    out << std::endl << kickout.getYear() << std::endl;
	out << kickout.getMake() << std::endl;
    out << kickout.getModel() << std::endl << std::endl;

	return out;
}