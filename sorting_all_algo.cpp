
#include<bits/stdc++.h>
using namespace std;



//Bubble Sort

void bubbleSort(int * arr, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}





//Insertion Sort





//Selection Sort














//Merge Sort














//Quick Sort


class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high){
            int pi = partition(arr,low,high);
            quickSort(arr,low,pi-1);
            quickSort(arr,pi+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int i=low-1;
       int pi = arr[high];
       for(int j=low;j<high;j++){
           if(arr[j]<pi){
               i++;
               swap(arr[i],arr[j]);
           }
       }
       swap(arr[i+1],arr[high]);
       return i+1;
    }
};




//Randomised Quick Sort















//Radix Sort











//Bucket Sort













