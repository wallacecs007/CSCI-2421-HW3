#ifndef RECURSION_H
#define RECURSION_H

#include <vector>
#include "Vehicle.h"

using namespace std;

void sortVectorMake(std::vector<Vehicle>& myArray);

void sortVectorModel(std::vector<Vehicle>& myArray);

void sortVectorYear(std::vector<Vehicle>& myArray);

int binSearchRec(std::vector<Vehicle> myArray, int first, 
                            int last, std::string Target);

int binSearchRec(std::vector<Vehicle> myArray, int first,
                            int last, int Target);

int binarySearchIter(std::vector<Vehicle> myArray, std::string target);

int binarySearchIter(std::vector<Vehicle> myArray, int target);

#endif