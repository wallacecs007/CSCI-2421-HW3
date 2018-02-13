#include <vector>
#include "Vehicle.h"

void sortVectorMake(std::vector<Vehicle>& myArray);

void sortVectorModel(std::vector<Vehicle>& myArray);

int binSearchRec(std::vector<Vehicle> myArray, int first, 
                            int last, std::string Target);

int binarySearhIter(std::vector<Vehicle> myArray, std::string target);