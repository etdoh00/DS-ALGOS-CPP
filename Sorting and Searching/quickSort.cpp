#include <iostream>

int partition_array(int arr[], int start, int end)
{
    int pivot_index = arr[end];
    int i = start;

    for(int j = start; j < end-1; j++)
    {
        if(arr[j] < pivot_index)
        {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i],arr[end]);
    return i;
}

void quickSort(int arr[], int start, int end)
{
    if(start >= end) { return;}

    int pivot_index = partition_array(arr, start, end);

    quickSort(arr,start,pivot_index-1);
    quickSort(arr,pivot_index+1, end);
}

int main()
{
    int arr[] = {2,1,3,4,5,7,-2,11,6};
    std::cout << "\n" << std::endl;    
    quickSort(arr,0,8);

    for(int j =0; j < 9; j++)
    {
        std::cout << arr[j] << " ";
    }
}