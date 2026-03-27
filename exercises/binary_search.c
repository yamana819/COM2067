#include <stdio.h>
#define SIZE 10


int binary_search(int [],int,int);

int main()
{
    int arr[SIZE]={1,3,5,6,11,17,19,20,21,25};
    int target=17;
    int size=sizeof(arr)/sizeof(arr[0]);
    int position=binary_search(arr,17,size);
    if (position!=-1) printf("The value found at position %d.",position);
    else printf("Value not found.");
}

int binary_search(int arr[],int target,int size)
{
    int low=0;
    int high=size-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]==target) return mid;
        else if (target>arr[mid]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}