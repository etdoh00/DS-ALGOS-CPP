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
// the function manipulates the values held in the address locations of j and k, 
// so temp = to the value at the address of j, 
// since j's value is now held by temp, it's value is now equal to the value at the address of k
// then finally the value at k is swapped to the value at the address held by temp which == j
void swap(int& j, int& k)
{
    int temp = j;
    j = k;
    k = temp;

}
//C++ style pointer swapping
// this function takes two integers and swaps the values being pointed to by a and b
// so temp is pointing to the value held by a, 
// the value being pointed to by a is now assigned by the value poinitng to b, 
// then the value of b is assigned by the value pointed to by temp, which == a
void swap_ptr(int* a, int* b) 
{
    int* temp = a;
    a = b;
    b = temp;

}

//function finds the max element in a given array,
//uses array, similar implementation in any other langauge 
int arrFindMax(int* pointerIndex, int arrSize)
{   //assign the first element the lowest value, if its bigger than the rest it wont change
    int maxValue = pointerIndex[0];
    for (int index = 0; index < arrSize; index++) {
        if (pointerIndex[index] > maxValue) { // if its smaller then the value > max, will be assigned max
            maxValue = pointerIndex[index];
        }
    }
    return maxValue;
}

//pointer arithmetic version of findingMAX
int ptrFindMax(int* pointerIndex, int arrSize)
{
    int maxValue = *pointerIndex; // using the inherit nature of pointers, the max value can be assgined 
                                  // by dereferencing pointerIndex as it will be pointing to the start of the array upon assignment]
                                  // thus making it the same as maxValue = pointerIndex[0]
    while (--arrSize > 0)
    {
        pointerIndex++;
        if (*pointerIndex > maxValue)
        {
            maxValue = *pointerIndex;
        }
    }
    return maxValue;
}

int* arrReverseArray(int* pointerIndex, int size)
{   //assign the first element 0, the last element size -1, due to 0 indexing
    int firstElement = 0, lastElement = size - 1; 
    int midPoint = size/2; // only need to travel to the mid point as the mid point will either not be swapped
                            // or elements (size/2) and (size/2)+1 will swap themselves
    for (int index = 0; index < midPoint; index++)
    {
        int temp = pointerIndex[firstElement]; // similar to swapping the values above, a temp value needs to 
                                              // be assigned the element that will be first over written so its is not lost
        pointerIndex[firstElement] = pointerIndex[lastElement];
        pointerIndex[lastElement] = temp;
        firstElement++, 
        lastElement--; // index the elements
                                        //[ first++ =====> MID <===== last--]
    }
    return pointerIndex;
}

int* ptrRevArray(int* pointerIndex, int size)
{
    int* firstElement = pointerIndex; // using properties of pointers, this points to the first
    int* lastElement = pointerIndex + size - 1; // this points to last, using "0" + size - 1, to get element size -1 
    int midPoint = (size / 2);
    while (midPoint-- > 0) // if size = 6, midpoint =3. Whilst 3 --> 2 --> --> 1 carry out the following:
    {
        int temp = *firstElement; // temp = first element, done by dereferencing the first index
        *firstElement++ = *lastElement; // value at first element = last, increase the index of the first element 
        *lastElement-- = temp; // value at last = temp (first), decrease index for next iteration 
    }                           //same as [ first++ =====> MID <===== last--], just less steps
                                // so after each iteration the index of the first element increases, so its switching
                                // wiht the values at the end, which are decrementing at the end of each iteration 
    return pointerIndex; // return array 


}