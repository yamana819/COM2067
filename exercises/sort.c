#include <stdio.h>
#define SIZE 10 


void bubble_sort(int [],int);
void insertion_sort(int [],int);
void selection_sort(int [],int);
int find_smallest(int [],int,int);

int main()
{
    int arr[SIZE]={1,3,2,5,4,9,2,2,8,11};
    selection_sort(arr,SIZE);
    for (int i=0;i<SIZE;i++)
    {
        printf("%d ",arr[i]);
    }
}

void bubble_sort(int arr[],int size)
{
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void insertion_sort(int arr[],int size)
{
    int i,j,temp;
    for (i=1;i<size;i++)
    {
        temp=arr[i];
        j=i-1;
        while (temp<arr[j] && (j>=0))
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void selection_sort(int arr[],int size)
{
    int k,pos,temp;
    for (k=0;k<size;k++)
    {
        pos=find_smallest(arr,k,size);
        temp=arr[k];
        arr[k]=arr[pos];
        arr[pos]=temp;
    }
}

int find_smallest(int arr[],int k,int size)
{
    int i,pos=k,min=arr[k];
    for (i=k+1;i<size;i++)
    {
        if (arr[i]<min)
        {
            min=arr[i];
            pos=i;
        }
    }
    return pos;
}