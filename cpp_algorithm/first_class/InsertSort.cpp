#include "InsertSort.h"


InsertSort::InsertSort()
{

}

InsertSort::~InsertSort()
{

}

void InsertSort::sort(int* arr,int len)
{
    for(int i = 1;i<len;i++)
    {
        for(int j = i;j > 0 && arr[j]<arr[j-1];j--)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr,j,j-1);
            }
        }
    }
}

void InsertSort::swap(int* arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}