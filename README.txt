========================================================================================

Assignment: Homework Three CSCI 2421

Program Description: This program was created with the purpose of reading in
car's and some of their describing features, make, model, and year, then storing
them into an array of a class "Vehicle." Then multiple different functions were
to be coded which would sort the features of the vehicle from smallest to largest
in reference to their binary which then can be passed to a binary search function.
Also to be coded, was a funciton that would reiterate throughout the vector looking
for the desired model, make, or year. There is a sort function for each of the
variables of the vehicle to order them properly. I did this through a bubble sort
method.

IDES/Test Editors: Visual Studio Code, Atom, Visual Studios

Status: Compiled on CSEGrid, and works with every test I've performed.

Issues Encountered:

    V0.1.0: I completed the psuedocode and wrote out the logic for the program

    V0.1.1: Wrote the basic header files for the program creating the classes
    and designing the functions more in depth

    V0.1.2: Finished writing the codes outline and wrote the file reading function
    However had an issue with not being able to read past white space after 
    reading in the year into an int.

    V0.1.3: Fixed the issue with the reading in, program is compiling but functions
    are throwing an error when it comes to returning the index.

    V0.1.4: Fixed returning index error, was a user typo setting index verses checking
    the index value

    V0.1.5: Found issues with out of range year search. Vector range would be over
    reached. Solved by adding in a second check on the index value.

    V0.2.0: Finished optimizing functions, more could be done to make O notation faster
    but for the time being the functionalities all work.

Upcoming:

    V0.2.1: Optimize O notation 
========================================================================================