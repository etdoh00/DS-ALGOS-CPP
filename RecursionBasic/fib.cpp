#include <iostream>

int fib(int num)
{
    //base case
    if(num ==0) { return 0;}
    if(num ==1) { return 1;}
    //recursive case
    int smallOut1 = fib(num-1);
    int smallOut2 = fib(num-2);

    return smallOut1+smallOut2; 
}



int main_fib()
{   
    int num =0;
    std::cout << "Enter upper bound of fib sequence: " <<std::endl;
    std::cin >> num;

    
    std::cout << "Fib for: " << num << " is: " << fib(num);

}