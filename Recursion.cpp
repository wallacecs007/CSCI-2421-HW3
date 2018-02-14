#include "Recursion.h"
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

    if( first > last )
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

int binarySearchIter(std::vector<Vehicle> myArray, std::string target)
{
    
    int index = -1;

    for ( int i = 0; i < myArray.size(); i++)
    {

        if ( myArray[i].getModel() == target || myArray[i].getMake() == target )
        { index = i; return index;}

    }

    return index;

}

int binarySearchIter(std::vector<Vehicle> myArray, int target)
{
    
    int index = -1;

    for ( int i = 0; i < myArray.size(); i++)
    {

        if ( myArray[i].getYear() == target )
        { index = i; return index;}

    }

    return index;

}