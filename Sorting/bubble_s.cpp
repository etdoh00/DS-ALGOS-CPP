#include <iostream>

void bubble_srt(int arr[], int n) //Big) = 0(N^2)
{
    int count = 0;
    for(count; count < n-1; count++) // iterate over array
    {
        for(int j =0; j < n-2; j++) // compare each element iwth its adjacent
        {
            if(arr[j] > arr[j+1]) { //if the adjacent is larger, swap
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void bubble_optimal(int arr[], int n) //same algorithm as before only wiht an extra conditional to make it O(N) as if its sorted 
{
    for (int count =0; count < n-1; count++)
    {
        bool sorted = true; // taking initally as sorted
        for(int i =0; i < n-1; i++)
        {
            if (arr[i] > arr[i+1]) //if enters this branch then sorted == false
            {
                std::swap(arr[i], arr[i+1]); // this carries out an O(N^2) 
                sorted = false; // sorted is false
            }
        }
        if(sorted == true) { break;} // if sorted then break out of loop, O(N) complexity
    }


}




int main2()
{       int n =6;
        int arr[] ={1,2,3,4,5};
        std::cout << "Before swapping" << std::endl;
        for (int i =0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        {
            std::cout << arr[i] << " ";
        }
        bubble_optimal(arr,n);

        std::cout << "\nAfter swapping" << std::endl;
        for (int i =0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        {
            std::cout << arr[i] << " ";
        }
}