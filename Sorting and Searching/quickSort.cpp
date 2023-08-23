#include <iostream>

int partition_array(int arr[], int start, int end) //function finds the pivotr of the array
{
    int pivot_index = arr[end]; // pivot = end of array
    int i = start; 

    for(int j = start; j < end-1; j++)
    {
        if(arr[j] < pivot_index) //check if element is less than pivot to determine which side of the array it belongs
        {
            std::swap(arr[i], arr[j]); //if smaller, swap the values at index and i to determine position around pivot
            i++; // increase i as the values before will be smallest
        }
    }
    std::swap(arr[i],arr[end]); //finally swap pivot to middle of array
    return i;// return index of pivot 
}

void quickSort(int arr[], int start, int end)
{
    if(start >= end) { return;} //base case check for sizes of 0 and 1

    int pivot_index = partition_array(arr, start, end); //find index for pivot 

    quickSort(arr,start,pivot_index-1);// sort recursivley LHS, so from start to elemnt before pivot
    quickSort(arr,pivot_index+1, end); // sort recursivley RHS, so from pivot +1 to end
} // do not sort to "pivot" always before or after or the pivot will be sorted and break algo 

int main()
{//test
    int arr[] = {2,1,3,4,5,7,-2,11,6};
    std::cout << "\n" << std::endl;    
    quickSort(arr,0,8);

    for(int j =0; j < 9; j++)
    {
        std::cout << arr[j] << " ";
    }
}