#include "SelectSort.h"

SelectSort::SelectSort()
{
}

SelectSort::~SelectSort()
{
}

void SelectSort::sort(int *arr, int len)
{
    if (arr == nullptr || len <2)
    {
        return;
    }
    for (int i = 0; i < len; i++)
    {
        int min = i;
        for (int j = i; j < len; j++)
        {
            // if (arr[j] < arr[min])
            // {
            //     min = j;
            // }
            min = arr[j] < arr[min] ? j : min;
        }
        swap(arr, i, min);
    }
}

void SelectSort::swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

