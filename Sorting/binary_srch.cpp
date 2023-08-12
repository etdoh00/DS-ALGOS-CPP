#include <iostream>

int binarySearch(int arr[], int n, int key) //O(logn)
{
    int start = 0, end = n-1; //starting and ending indexes
    while (start <= end) 
    {
        int mid = (start+end) /2; // finds mid point
        if (arr[mid] == key) { return mid; } // if found at mid, return index

        if (arr[mid] > key) { end = mid -1;} // if mid is greater than key, move the end down so mid moves down 

        if (arr[mid] < key) { start = mid + 1; } // if mid is less than key, move the start up so mid moves up 
    }
    return -1;
}



int main11() // test
{       int n =6;
        int arr[] ={1,2,3,4,5,6};
        std::cout << "Array : " ;
        for (int i =0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        {
            std::cout << arr[i] << " ";
        }
        int pos =  binarySearch(arr,n,4);
        if (pos == -1) { 
            std::cout << "\nKey not found" << std::endl;} 
            else {
            std::cout << "\nKey found at: " << pos << std::endl;
        }

}