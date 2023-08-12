#include <iostream>
#include <vector>
int linear_srch (int arr[], int key, int n)
{
    
    for(int i =0; i < n-1; i++) //simple algorithiom wiht O(N) --> slow for large datasets as it will need to run to n-1 as a worst case scenario , best case is 1
    {
        if (key == arr[i])
        {
            return i;
        }        
    }
    return -1;
}



int main5()
{       int n =6;
        int arr[] ={4,22,23,34,15};
        std::cout << "Array : " ;
        for (int i =0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        {
            std::cout << arr[i] << " ";
        }
        int pos =  linear_srch(arr,4,n);
        if (pos == -1) { 
            std::cout << "\nKey not found" << std::endl;} 
            else {
            std::cout << "\nKey found at: " << pos << std::endl;
        }

}