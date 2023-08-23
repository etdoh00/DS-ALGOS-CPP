#include <iostream>
class DStack //array based implementation
{
    int* arr;
    int nextIndex;
    int capacity;
    
    public: 
    DStack() //stack with no user inpt to determine size - set to 4
    {
        capacity = 4;
        arr = new int[capacity];
        nextIndex = 0; 
    }
     int size() //return size of stack
    {
        return nextIndex; //index will = size
    }

    bool isEmpty() // return boolean if stack is empty or not
    {
     return nextIndex == 0; //true if nextindex is 0, other wise its false
    }

    void push(int item) //this push function has dynamic allocation incase the stack is full
    {
        if(nextIndex >= capacity)  // if index is out of bounds for array
        {
         int* temparr = new int[capacity*2]; //create a new temporary array
         for(int i =0; i < capacity; i++)
         {
            temparr[i] = arr[i]; //copy values from old array to temp
         }
         delete[] arr; //free heap memory of old array 
         arr = temparr; // point arr toward temp array
         capacity *=2; //double the capapcity
        }
        
        arr[nextIndex] = item; //make element at next item = item
        nextIndex++; //increase the index
    }

    void pop()
    {
        if(isEmpty()) { std::cout << "Stack is empty" << std::endl; 
        return; } //prevent stack underflow
        
        nextIndex--; //decrase index
    }

    int top()
    {
        if(isEmpty()) { std::cout << "Stack is empty" << std::endl; 
        return -1;} //check if stack is empty

        return arr[nextIndex-1];
    }
};

int main()
{
    
    DStack array_s;

    array_s.push(10);
    array_s.push(20);
    array_s.push(30);
    array_s.push(40);
    array_s.push(50); 

    std::cout << array_s.top() << std::endl; // out: 50, now as stack can dynamically allocate memory
    array_s.pop();
    std::cout << array_s.size() << std::endl;// out: 4

    std::cout << array_s.top() << std::endl;// out: 40
    array_s.pop();
    std::cout << array_s.size() << std::endl;// out: 3

    std::cout << array_s.isEmpty() << std::endl; //out: 0 -> false

    while (!array_s.isEmpty())
    {
        array_s.pop();
    }
    
    std::cout << array_s.isEmpty() << std::endl; //out: 1 -> true
}
 