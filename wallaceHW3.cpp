#include <iostream>
#include <vector>
#include <fstream>
#include "Vehicle.h"
#include "Recursion.h"

int main()
{

    //Creating and calling all the different variables I'll use in my main function
    std::vector<Vehicle> vehicleVector;
    Vehicle tempVehicle;
    int tempYear, menuChoice, intTarg, index;
    std::string tempMake;
    std::string tempModel;
    std::string stringTarg;

    std::cout << "Beginning reading in file..." << std::endl;
    std::ifstream myInline;
    myInline.open("vehiclein.txt");//Change this to proper file name before executing
    //Reading while there is no end of file for myInline.
    while(!myInline.eof()) 
    {

        myInline >> tempYear;
		myInline.ignore();
        getline (myInline, tempMake);
        getline (myInline, tempModel);

        tempVehicle.setYear(tempYear);
        tempVehicle.setMake(tempMake);
        tempVehicle.setModel(tempModel);

        vehicleVector.push_back(tempVehicle);

    }
    std::cout << "Finished reading in file..." << std::endl << std::endl;
    myInline.close();//Closing file in

    while(true)
    {

    std::cout << "1. Binary Search Make" << std::endl;
    std::cout << "2. Iteration Search Make" << std::endl;
    std::cout << "3. Binary Search Model" << std::endl;
    std::cout << "4. Iteration Search Model" << std::endl;
    std::cout << "5. Binary Search Year" << std::endl;
    std::cout << "6. Iteration Search Year" << std::endl;
    std::cout << "7. Exit" << std::endl;

    std::cin >> menuChoice;

    switch(menuChoice)
    {

        case 1:
            sortVectorMake(vehicleVector);
            std::cout << "What make would you like to search for: " << std::endl;
            std::cin >> stringTarg;
            index = binSearchRec(vehicleVector, 0, vehicleVector.size(), stringTarg);
            if ( index == -1 )
            { std::cout << "Nothing was found for the search criteria. Make sure to use proper capitaliztion." << std::endl; }
            else { std::cout << vehicleVector[index]; }
        break;

        case 2:
            sortVectorMake(vehicleVector);
            std::cout << "What make would you like to search for: " << std::endl;
            std::cin >> stringTarg;
            index = binSearchRec(vehicleVector, 0, vehicleVector.size(), stringTarg);
            if ( index == -1 )
            { std::cout << "Nothing was found for the search criteria. Make sure to use proper capitaliztion." << std::endl; }
            else { std::cout << vehicleVector[index]; }
        break;

        case 3:
            sortVectorModel(vehicleVector);
            std::cout << "What model would you like to search for: " << std::endl;
            std::cin >> stringTarg;
            index = binSearchRec(vehicleVector, 0, vehicleVector.size(), stringTarg);
            if ( index == -1 )
            { std::cout << "Nothing was found for the search criteria. Make sure to use proper capitaliztion." << std::endl; }
            else { std::cout << vehicleVector[index]; }
        break;

        case 4:
            sortVectorModel(vehicleVector);
            std::cout << "What model would you like to search for: " << std::endl;
            std::cin >> stringTarg;
            index = binSearchRec(vehicleVector, 0, vehicleVector.size(), stringTarg);
            if ( index == -1 )
            { std::cout << "Nothing was found for the search criteria. Make sure to use proper capitaliztion." << std::endl; }
            else { std::cout << vehicleVector[index]; }
        break;

        case 5:
            sortVectorYear(vehicleVector);
            std::cout << "What year would you like to search for: " << std::endl;
            std::cin >> intTarg;
            index = binSearchRec(vehicleVector, 0, vehicleVector.size(), intTarg);
            if ( index == -1 )
            { std::cout << "Nothing was found for the search criteria. Make sure to use proper capitaliztion." << std::endl; }
            else { std::cout << vehicleVector[index]; }
        break;

        case 6:
            sortVectorYear(vehicleVector);
            std::cout << "What year would you like to search for: " << std::endl;
            std::cin >> intTarg;
            index = binSearchRec(vehicleVector, 0, vehicleVector.size(), intTarg);
            if ( index == -1 )
            { std::cout << "Nothing was found for the search criteria. Make sure to use proper capitaliztion." << std::endl; }
            else { std::cout << vehicleVector[index]; }
        break;

        case 7:
        std::cout << "Goodbye!" << std::endl;
            return 0;
        break;
		default:
			std::cout << "You didn't enter a correct parameter: " << std::endl;

    }

    }

    return 0;

}