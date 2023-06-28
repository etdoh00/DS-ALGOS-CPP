#include <iostream>
#include "basic_functions.h"

int main()
{
    // this uses a C style swap function where the values are accessed by reference. The function uses the "&" to view the value at the addresses for a and b. 
    int a = 0, b = 0;
    std::cout << "Please enter two numbers to swap : " << std::endl;
    std::cin >> a >> b;
    std::cout << "Numbers before swapping: " << "\nA: " << a << "\nB:" << b << std::endl;
    swap(a, b);
    std::cout << "Numbers after swapping: " << "\nA: " << a << "\nB:" << b << std::endl;

    int c = 4, d = 5;
    int* pc = &c, *pd = &d;
    //this uses the C++ pointer style version of the swap function. The variables pc and pd are pointers to the addresses of variables c and d.
    //these pointers are then passed into the swap function and swap by using the pointers pointing to the values at the addresses at c and d 
    std::cout << "Numbers before swapping: " << "\nA: " << *pc << "\nB: " << *pd << std::endl;
    swap(*pc, *pd);
    std::cout << "Numbers after swapping: " << "\nA: " << *pc << "\nB: " << *pd << std::endl;

    return 0;
}
