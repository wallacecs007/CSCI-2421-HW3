#include "Recursion.h"
#include <iostream>
#include <fstream>
//#include "Vehicle.h"



//Uses a bubble sort method to compare the makes of the cars
//And orders them to prepare for a binary serach
void sortVectorMake(std::vector<Vehicle>& myArray)
{

    //Creating a temporary vehicle class member to hold the 
    //Item that is being swapped if one needs to be swapped
    Vehicle temp;

    //I'm going to sort these through the use of a bubble sort
    //This is required in order for the binary search to be of
    //affect


    //Using a series of for loops to test and order the variables
    for( int i = 0; i < myArray.size(); i++ )
    {
        //This for loop runs until array.size() - 1 as the last variable will not
        //Have anything to be tested aginst if if goes for the entirety of the size
        for ( int j = 0; j < myArray.size() - 1; j++ )
        {
            //The if statement to check if the two 
            if( myArray[j].getMake() > myArray[j+1].getMake() )
            {
                //Performing the swap of the elements inside the arrays
                temp = myArray[j];
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            }//end if
        }//end nested for
    }//end outer for

}//end sortVectorMake()

void sortVectorModel(std::vector<Vehicle>& myArray)
{

    Vehicle temp;

    //I'm going to sort these through the use of a bubble sort
    //This is required in order for the binary search to be of
    //affect

    for( int i = 0; i < myArray.size(); i++ )
    {
        for ( int j = 0; j < myArray.size() - 1; j++ )
        {
            if( myArray[j].getModel() > myArray[j+1].getModel() )
            {
                temp = myArray[j];
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            }
        }
    }

}

void sortVectorYear(std::vector<Vehicle>& myArray)
{

    Vehicle temp;

    //I'm going to sort these through the use of a bubble sort
    //This is required in order for the binary search to be of
    //affect

    for( int i = 0; i < myArray.size(); i++ )
    {
        for ( int j = 0; j < myArray.size() - 1; j++ )
        {
            if( myArray[j].getYear() > myArray[j+1].getYear() )
            {
                temp = myArray[j];
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            }
        }
    }

}

//This is the binary search for either make or model
//I made it so that the function could search for either
//Only downside is that if you try to search for make and enter a model
//instead it still will return what's associated with the model
int binSearchRec(std::vector<Vehicle> myArray, int first, 
                            int last, std::string target)
{

    //This was taken from the book page 69
    //Reference within the problem assigned
    int index;

    if( first > last )
    { index = -1; }
    else
    {
        //The true part of the recursion beings here
        //Checking to see if the item has been found
        //If not continues to search through recursion
        int mid = first + ((last - first) / 2);
        if ( target == myArray[mid].getMake() || target == myArray[mid].getModel() )
        { index = mid; }
        else if( target < myArray[mid].getMake() || target < myArray[mid].getModel() )
        { index = binSearchRec(myArray, first, mid - 1, target); }
        else
        { index = binSearchRec(myArray, mid + 1, last, target); }
    }

    return index;

}

int binSearchRec(std::vector<Vehicle> myArray, int first, 
                            int last, int target)
{

    //This was taken from the book page 69
    //Reference within the problem assigned
    int index;

    if( first >= last )
    { index = -1; }
    else
    {
        //The true part of the recursion beings here
        //Checking to see if the item has been found
        //If not continues to search through recursion
        int mid = first + ((last - first) / 2);
        if ( target == myArray[mid].getYear() )
        { index = mid; }
        else if( target < myArray[mid].getYear() )
        { index = binSearchRec(myArray, first, mid - 1, target); }
        else
        { index = binSearchRec(myArray, mid + 1, last, target); }
    }

    return index;

}

//This does a iteration search for the model/make of the vehicle
int binarySearchIter(std::vector<Vehicle> myArray, std::string target)
{
    
    int index = -1;

    //This for loop loops through the array searching for the target and
    //Then returning the index for it. If it is not found it returns -1
    for ( int i = 0; i < myArray.size(); i++)
    {

        if ( myArray[i].getModel() == target || myArray[i].getMake() == target )
        { index = i; return index;}

    }

    return index;

}

//This does a iteration search for the year of the vehicle
int binarySearchIter(std::vector<Vehicle> myArray, int target)
{
    
    int index = -1;

    //This for loop loops through the array searching for the target and
    //Then returning the index for it. If it is not found it returns -1
    for ( int i = 0; i < myArray.size(); i++)
    {

        if ( myArray[i].getYear() == target )
        { index = i; return index;}

    }

    return index;

}

void readFileIn(vector<Vehicle> &vehicleVector)
{

    //Creating and declaring all the variables needed to read in the
    //.txt file. This includes a temporary vehicle object, and some temporary
    //Strings and ints
    int tempYear;
    std::string tempMake, tempModel;
    Vehicle tempVehicle; 

    std::cout << "Beginning reading in file..." << std::endl;
    std::ifstream myInline;
    myInline.open("vehiclein.txt");//Change this to proper file name before executing
    //Reading while there is no end of file for myInline.
    while(!myInline.eof()) 
    {

        myInline >> tempYear;
		myInline.ignore();//Needed this to ignore the whitespace after reading in the int to prevent infinite loop
        getline (myInline, tempMake);
        getline (myInline, tempModel);

        //Setting the temp vehicles values
        tempVehicle.setYear(tempYear);
        tempVehicle.setMake(tempMake);
        tempVehicle.setModel(tempModel);

        vehicleVector.push_back(tempVehicle);//Pushing the temp vehicle into the vector

    }
    std::cout << "Finished reading in file..." << std::endl << std::endl;
    myInline.close();//Closing file in

}

void runSearch(vector<Vehicle> & vehicleVector)
{

    int menuChoice, intTarg, index;
    std::string stringTarg;

    bool keepRunning = true; // Using this to break off the while loop when the user selects exit

    //Creating a loop to run the program until the user wants to quit
    while(keepRunning == true)
    {

    std::cout << "1. Binary Search Make" << std::endl;
    std::cout << "2. Iteration Search Make" << std::endl;
    std::cout << "3. Binary Search Model" << std::endl;
    std::cout << "4. Iteration Search Model" << std::endl;
    std::cout << "5. Binary Search Year" << std::endl;
    std::cout << "6. Iteration Search Year" << std::endl;
    std::cout << "7. Exit" << std::endl;

    std::cin >> menuChoice;

    //Simple switch statement (looks more compelx than it is) to handle the choice of the user and call
    //The necessary functions and take user input.
    switch(menuChoice)
    {

        case 1:
            sortVectorMake(vehicleVector);
            std::cout << "What make would you like to search for: " << std::endl;
            std::cin >> stringTarg;
            index = binSearchRec(vehicleVector, 0, vehicleVector.size(), stringTarg);
            if ( index == -1 )
            { std::cout << "Nothing was found for the search criteria. Make sure to use proper capitaliztion." << std::endl << std::endl; }
            else { std::cout << vehicleVector[index]; }
        break;

        case 2:
            sortVectorMake(vehicleVector);
            std::cout << "What make would you like to search for: " << std::endl;
            std::cin >> stringTarg;
            index = binSearchRec(vehicleVector, 0, vehicleVector.size(), stringTarg);
            if ( index == -1 )
            { std::cout << "Nothing was found for the search criteria. Make sure to use proper capitaliztion." << std::endl << std::endl; }
            else { std::cout << vehicleVector[index]; }
        break;

        case 3:
            sortVectorModel(vehicleVector);
            std::cout << "What model would you like to search for: " << std::endl;
            std::cin >> stringTarg;
            index = binSearchRec(vehicleVector, 0, vehicleVector.size(), stringTarg);
            if ( index == -1 )
            { std::cout << "Nothing was found for the search criteria. Make sure to use proper capitaliztion." << std::endl << std::endl; }
            else { std::cout << vehicleVector[index]; }
        break;

        case 4:
            sortVectorModel(vehicleVector);
            std::cout << "What model would you like to search for: " << std::endl;
            std::cin >> stringTarg;
            index = binSearchRec(vehicleVector, 0, vehicleVector.size(), stringTarg);
            if ( index == -1 )
            { std::cout << "Nothing was found for the search criteria. Make sure to use proper capitaliztion." << std::endl << std::endl; }
            else { std::cout << vehicleVector[index]; }
        break;

        case 5:
            sortVectorYear(vehicleVector);
            std::cout << "What year would you like to search for: " << std::endl;
            std::cin >> intTarg;
            index = binSearchRec(vehicleVector, 0, vehicleVector.size(), intTarg);
            if ( index == -1 )
            { std::cout << "Nothing was found for the search criteria. Make sure to use proper capitaliztion." << std::endl << std::endl; }
            else { std::cout << vehicleVector[index]; }
        break;

        case 6:
            sortVectorYear(vehicleVector);
            std::cout << "What year would you like to search for: " << std::endl;
            std::cin >> intTarg;
            index = binSearchRec(vehicleVector, 0, vehicleVector.size(), intTarg);
            if ( index == -1 )
            { std::cout << "Nothing was found for the search criteria. Make sure to use proper capitaliztion." << std::endl << std::endl; }
            else { std::cout << vehicleVector[index]; }
        break;

        case 7:
            std::cout << "Goodbye!" << std::endl;
            //Insert something to break the while loops
            //This is what I'm inserting to break the while loop:
            keepRunning = false;
        break;
		default:
			std::cout << "You didn't enter a correct parameter: " << std::endl << std::endl;

    }

    }

}