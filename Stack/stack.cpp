#include <iostream>
class Stack //array based implementation -> does not have dynamic sizing so there will be a size limit once initialised
{
    int* arr;
    int nextIndex;
    int capacity;
    
    public: 
    Stack() //stack with no user inpt to determine size - set to 4
    {
        capacity = 4;
        arr = new int[capacity];
        nextIndex = 0; 
    }
    Stack(int cap) //stack with user input, uses dynamic array to fill stack size
    {
    capacity = cap;
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

    void push(int item)
    {
        if(nextIndex >= capacity) { std::cout << "Stack is full" << std::endl; 
        return;} //prevent stack overflow
        
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
    
    Stack array_s(4);

    array_s.push(10);
    array_s.push(20);
    array_s.push(30);
    array_s.push(40);
    array_s.push(50); //out: Stack is full

    std::cout << array_s.top() << std::endl; // out: 40
    array_s.pop();
    std::cout << array_s.size() << std::endl;// out: 3

    std::cout << array_s.top() << std::endl;// out: 30
    array_s.pop();
    std::cout << array_s.size() << std::endl;// out: 2

    std::cout << array_s.isEmpty() << std::endl; //out: 0 -> false


    std::cout <<"\n Stack s2:" << std::endl;
    Stack array_s2(10);

    for(int i =0; i < 10; i++)
    {
        array_s2.push(rand() % 20);
    }

    std::cout << array_s2.top() << std::endl; // out: 4
    //array_s2.pop();
    std::cout << array_s2.top() << std::endl; // out: 2
    std::cout << array_s2.size() << std::endl;//9 since one element has been popped

    //print output of whole stack:
    std::cout << "Content of Stack s2" << std::endl;
    while (!array_s2.isEmpty())
    {
        std::cout << array_s2.top() << std::endl;
        array_s2.pop();
    }
}


