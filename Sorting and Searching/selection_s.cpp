#include <iostream>

void selection_srt(int arr[], int n) // BigO = O(n^2)
{
  for(int i =0 ; i < n-2; i++) { //search for each element, up to n-2 as n-1 will not have a right side comparison 
    int smallest_index = i; // smallest index variable 
    for(int j = i +1; j < n-1; j++) { // right hand comparison for each element of arr[i]
        if(arr[j] < arr[smallest_index]) {
            smallest_index = j; // swap the indexes of elements
        }
    }
    std::swap(arr[i], arr[smallest_index]); // swap the values at the index of each value 
  }
}





int main1()
{       int n =6;
        int arr[] ={4,2,6,8,4,2};
        std::cout << "Before swapping" << std::endl;
        for (int i =0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        {
            std::cout << arr[i] << " ";
        }
        selection_srt(arr,n);

        std::cout << "\nAfter swapping" << std::endl;
        for (int i =0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        {
            std::cout << arr[i] << " ";
        }
}