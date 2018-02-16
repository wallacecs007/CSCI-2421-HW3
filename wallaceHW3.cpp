#include <iostream>
#include <vector>
#include <fstream>
#include "Vehicle.h"
#include "Recursion.h"

int main()
{

    //Creating and calling all the different variables I'll use in my main function
    std::vector<Vehicle> vehicleVector;
    
    readFileIn(vehicleVector);

    runSearch(vehicleVector);

}