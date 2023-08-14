#include <iostream>

int powers(int x, int n) //using recursion to calculate powers of a number x^y = x*x^y-1
{///pow(x,n) = pow(x,n-1)*x -> recursive case

    //Base Case 
    if(n == 0) { return 1;} //x^0 = 1

    //recursive case
    int smallOut = powers(x,n-1);

    //calculation
    return smallOut * x;
}


int main()
{
    int x =0;
    int n =0;
    std::cout << "Enter number and its power: " <<std::endl;
    std::cin >> x >> n;

    
    std::cout << x <<" to the power of " << n << " is: " << powers(x,n);
}