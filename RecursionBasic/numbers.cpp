#include <iostream>

void print(int num)
{///Base case
    if (num ==0) { return;}

//Recursive case
    print(num-1);

    std::cout << num<<std::endl;
}

int main()
{
    print(5);
}