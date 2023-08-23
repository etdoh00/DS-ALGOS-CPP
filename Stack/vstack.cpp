#include <iostream>
#include <vector>
class vStack { //vector implementation of stack 
    int capacity;
    std::vector<int>* vec;
    int nextIndex;

    public:
    vStack()
    {
    capacity = 4;
    vec = new std::vector<int>(capacity);
    nextIndex =0;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int item) //funciton defied the LIFO abstraction of stack when using "push_back"
    {
        vec->insert(vec->begin()+nextIndex, item); // insert element at position (0+index) to get correct positon
        nextIndex++;//increase index
    } //using push_back meant FIFO - first in first out

    void pop()
    {
        if(isEmpty()) { std::cout << "Stack is empty" << std::endl;
        return;}

        //nextIndex--;
        vec->pop_back(); //remove element at the start
        nextIndex--; //decrase index
        
    }

    int top()
    {
        if(isEmpty()) { std::cout << "Stack is empty" << " ";
        return -1;}

        return vec->at(nextIndex-1); //return element at index-1
    }
};


int main()
{
    vStack array_s;

    array_s.push(10);
    array_s.push(20);
    array_s.push(30);
    array_s.push(40);
    array_s.push(50); 

    std::cout << array_s.top() << std::endl; // out: 50, now as stack can dynamically allocate memory
    array_s.pop();
    std::cout << "Size: " << array_s.size() << std::endl;// out: 4

    std::cout << array_s.top() << std::endl;// out: 40
    array_s.pop();
    std::cout << "Size: " << array_s.size() << std::endl;// out: 3

    std::cout << "0 for not  empty: " <<array_s.isEmpty() << std::endl; //out: 0 -> false

    while (!array_s.isEmpty())
    {
        array_s.pop();
    }
    
    std::cout << "1 for empty: " << array_s.isEmpty() << std::endl; //out: 1 -> true
}