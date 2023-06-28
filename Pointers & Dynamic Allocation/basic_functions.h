#ifndef BASIC_FUNCTIONS_H
#define BASIC_FUNCTIONS_H

//write the functions I aim to develop
//no source code is written, this is for declaring the functions to be created 

/*
Main purposes of using header files include:
> Encapsulation - Allows you to encapsulate related declarations and definitions into a single file
> Declaration Seperation - The files contain the decleration without implementation - prevents exposing implementation
> Reusability - Means you can reuse functions, classes and constants. Preventing code duplication
> Interface Definintion - Can act as a definition for a module or li
*/

int iAdd(int a, int b);
double divideXbyY(double x, double y); //same name but is still correct due to data type
int divideXbyY(int x, int y);
//pointer functions
void swap(int& j, int& k);
void swap_ptr(int* x, int* y);
#endif
