#include "BubbleSort.h"

BubbleSort::BubbleSort()
{
}

BubbleSort::~BubbleSort()
{
}

void BubbleSort::sort(int *arr, int len)
{
    if(arr == nullptr || len <2)
        return;
    for(int i = 0 ;i <len ;i++)
    {
        for(int j = 0 ;j<len-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr,j,j+1);
            }
        }
    }

}

void BubbleSort::swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}