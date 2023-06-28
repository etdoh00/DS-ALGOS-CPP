#include <iostream>
#include "basic_functions.h"

int main()
{
    int a = 0, b = 0;
    std::cout << "Please enter two numbers to swap : " << std::endl;
    std::cin >> a >> b;
    std::cout << "Numbers before swapping: " << "\nA: " << a << "\nB:" << b << std::endl;
    swap(a, b);
    std::cout << "Numbers after swapping: " << "\nA: " << a << "\nB:" << b << std::endl;

    int c = 4, d = 5;
    int* pc = &c, *pd = &d;
    std::cout << "Numbers before swapping: " << "\nA: " << *pc << "\nB: " << *pd << std::endl;
    swap(*pc, *pd);
    std::cout << "Numbers after swapping: " << "\nA: " << *pc << "\nB: " << *pd << std::endl;

    return 0;
}