#include <iostream>

int main_bug()
{
    //there is a pointer bug in this code:
    int* bug_pi = NULL;
    int bug_count = 3;
    while (bug_count-- > 0) {
        int i = bug_count + 1;
        bug_pi = &i;
    }
    std::cout << *bug_pi << std::endl;

    /* in the code above the pointer "pi" is pointing to a
    variable i, which is destroyed in each iteration of the loop.
    This means that the pointer will be pointing to a memory address
    that no longer exists. This can cause undefined behaviour and may lead
    to errors.

    The correct approach:
    */
    int* fixed_pi = nullptr;
    int fixed_count = 3;
    int i = 0;
    while (fixed_count-- > 0) {
        i = fixed_count + 1;
        fixed_pi = &i;
    }
    std::cout << *fixed_pi << std::endl;
    /*
     With the "i" variable declared outside the loop, it remains in scope until
     the end of the block. So its address will be stored properly
    */
    return 0;

}

int main_basic_pointer()
{
    //Declaration 
    int i = 10; // i: int variable = 10

    //Variable = i 
    // address = 0x001122ab - not a real address
    //content = 0a(10) - representing computer memory 

    int* pi = &i;
    //&  point to the address of i 
    std::cout << *pi << std::endl;

    //variable pi
    //address = 0x001c4e2e 
    //content = address 0x001122ab -> 0a(10), so *pi = i = 10
    *pi = 20; // equivalent to i = 20 
              // can also do *pi +=10, *pi*=10


    std::cout << *pi << " " << i << std::endl;
    //accesses i by using the pointer, notice how both values are now = 20
    std::cout << pi << std::endl;
    //prints the memory address, hexidecimal, 
    //the pointer needs to be dereferenced, as seen in "*pi"


 //Dangerous Pointer
   // int* bad_pi;
   // *bad_pi = 16;
    /* This operation is incredibly dangerous and most compilers will prohibit
   as the pointer is not initialised, it can be pointing at any random address and
   can overwrite it wiht "16". I tested in vscode and will not build
   */
    int* good_pi = NULL;
    std::cout << good_pi << std::endl;
    //executing this will print the address 000000 -> does not exist inside many physical 
    //memory systems, so will not crash OS. This is safe to do. There are many ways to write this:
    good_pi = nullptr;
    good_pi = 0;
    //all are valid, 0 == NULL
    return 0;
}