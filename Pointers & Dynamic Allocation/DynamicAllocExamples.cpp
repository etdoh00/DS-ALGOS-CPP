#include <iostream>
#include "basic_functions.h"



void printArr(int* arr, int size)
{
	for (int index = 0; index < size; index++)
	{
		std::cout << arr[index] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	//prompt user to define the size of the array
	int size = 0;
	std::cout << "Please enter the size of the array: " << std::endl;
	std::cin >> size;

	//create the array based off the user input,
	//
	int* integerArray = new int[size];
	int* tempIntArray = integerArray;

	for (int populateIndex = 0; populateIndex < size; populateIndex++)
	{
		*tempIntArray++ = rand() % 20;
	}
	
	printArr(integerArray, size);

	//call functions, starting with array 
	
	std::cout << "\nMax functions: " << std::endl;
	std::cout <<"Pointer Max: " << ptrFindMax(integerArray, size) << std::endl;
	std::cout <<"Array Max: " << arrFindMax(integerArray, size) << std::endl;

	//pointer functions
	std::cout << "\nReverse Functions: " << std::endl;
	arrReverseArray(integerArray, size);
	std::cout << "Array Reverse: ";
	printArr(integerArray, size);
	ptrRevArray(integerArray, size);
	std::cout << "Pointer Reverse: ";
	printArr(integerArray, size);

	//delete array after
	delete[] integerArray;
}