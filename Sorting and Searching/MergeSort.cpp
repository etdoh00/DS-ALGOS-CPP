#include <iostream>
void mergeSlow(int arr[], int x[], int y[], int start, int end) // still o(n) but needs two seperate arrays and more loops - slower and greater space complexzity
{
    int mid = (start+end)/2; //mid point 
    int k = start; //main array index
    int i = start; //left array index
    int j = mid; // right array index

    while(i <= mid && j <= end)
    {
       if(x[i] < y[j]) //if left is smaller than right, insert left
       { 
        arr[k] = x[i];
        k++; //increment the indexes
        i++;
       } else {
        arr[k] = y[j]; // if right is smaller than left, insert right
        k++;//increase indexes
        y++;//
       }
    }

    while(i <=mid) //fill in reminaing values of left array if any
    {
        arr[k] = x[i];
        k++;
        i++;
    }
    while(j <= end) //fill in reminaing values of right array if any
    {
        arr[k] = y[j];
        k++;
        j++;
    }
}

void slowMergeSort(int arr[], int start, int end)
{
    int mid = (start+end)/2;
    int x[100]; // temp array values
    int y[100];
    for(int i =start; i<=mid; i++)
    {
        x[i] = arr[i]; //left hand array 
    }
    for(int j = mid+1; j <= end; j++)
    {
        y[j] = arr[j]; //right hand array 
    }

    slowMergeSort(x,start,mid); //sort left
    slowMergeSort(y,mid+1,end); //sort right

    mergeSlow(arr,x,y,start,end); // merge
}



void fastMerge(int* a, int start, int end) // fastest response - O(n)
{
    int mid = (start+end)/2; //mid point for array
   
    int k = start; //start for main array
    int i = start; // start for left array
    int j = mid+1; // start point for right array 
   
   
    int temp[100]; //create a temporary array 

    while(i <= mid &&  j <= end) {
        if(a[i] < a[j]) //check if left < right, if true, insert element
        {
            temp[k++] = a[i++]; // same as above only in  one line -> insert a[i] in temp[k] and increment
        } else {
            temp[k++] = a[j++];// same only inserting j if i is bigger
        }
    }
    while (i <= mid)
    {
        temp[k++] = a[i++]; /// insert left over elements from left
    }
    while(j <= end)
    {
        temp[k++] = a[j++]; /// insert left over elements from right 
    }
    
    for(int z =start; z <= end; z++)
    {
        a[z] = temp[z]; // paste results to original array 
    }

}

void fastMergeSort(int arr[], int start, int end)
{
    if(start>=end) { return;} //base case 

    int mid = (start+end)/2; // mid points 

    fastMergeSort(arr,start,mid); //sort left
    fastMergeSort(arr,mid+1,end); // sort right

    fastMerge(arr,start,end); //merge arrays

}

int main_merge()
{
    int arr[] = {2,5,7,3,1,7,4,45};
    fastMergeSort(arr,0,7);
    for(int i =0; i < 8; i++)
    {
        std::cout << arr[i] << " ";
    }
}

