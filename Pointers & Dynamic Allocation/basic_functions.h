#ifndef BASIC_FUNCTIONS_H
#define BASIC_FUNCTIONS_H

//write the functions I aim to develop
//no source code is written, this is for declaring the functions to be created 
//The header file allows me to write the skeleton code for the function i will like to implement in the future. You will see how these functions are pulled in at the top of the cpp files
// I like to use header files as I can early define a function and reuse it without having to rewrite it or duplicate code.

/*
Main purposes of using header files include:
> Encapsulation - Allows you to encapsulate related declarations and definitions into a single file
> Declaration Seperation - The files contain the decleration without implementation - prevents exposing implementation
> Reusability - Means you can reuse functions, classes and constants. Preventing code duplication
> Interface Definintion - Can act as a definition for a module or li
*/

//the following functions have been completed in the basic_functions.cpp file, which provides their definition. I can then call these functions as if they were already built in. 
//adds two numbers
int iAdd(int a, int b);
//divides two numbers with double precision 
double divideXbyY(double x, double y); //same name but is still correct due to data type
//divides two integers 
int divideXbyY(int x, int y);
//pointer functions

//C style pass by reference function, using memory addresses
void swap(int& j, int& k);
//C++ style pointer formulation, uses the values pointed by x and y
void swap_ptr(int* x, int* y);
#endif
