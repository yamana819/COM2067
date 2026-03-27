#include <stdio.h>
#define SIZE 10

int interpolation_search(int [],int,int);

int main()
{
    int arr[SIZE]={1,3,5,6,11,17,19,20,21,25};
    int target=21;
    int size=sizeof(arr)/sizeof(arr[0]);
    int position=interpolation_search(arr,size,target);
    if (position!=-1) printf("The value found at position %d.",position);
    else printf("Value not found.");
}

int interpolation_search(int arr[],int size,int target)
{
    int low=0;
    int high=size-1;
    while (low<=high)
    {
        int mid=low+(high-low)*((target-arr[low])/(arr[high]-arr[low]));
        if (arr[mid]==target) return mid;
        else if (target>arr[mid]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}