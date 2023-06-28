//include header file where functions are declared
// write the source code for the functions 

#include "basic_functions.h"
//all very basic code -- for demonstration purposes not complexity
int iAdd(int x, int y)
{
    return x + y; // = x + y 
}

double divideXbyY(double x, double y)
{
    return x / y; // = x / y (double)
}

int divideXbyY(int x, int y)
{
    return x / y; // = x / y (int)
}
//pass by reference - using C style 
// the function references the values i  and j at their memory locations and swaps
void swap(int& j, int& k)
{
    int temp = j;
    j = k;
    k = temp;

}
//C++ style pointer swapping
// this uses pointers, where the values being pointed to by a and b are swapped
void swap_ptr(int* a, int* b) 
{
    int* temp = a;
    a = b;
    b = temp;

}