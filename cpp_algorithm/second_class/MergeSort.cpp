#include "MergeSort.h"
#include <vector>
#include <iostream>
using namespace std;


void merge(int arr[],int L,int middle,int R)
{   

    vector<int> temp;
    
    temp.reserve(R-L+1);
    int p_left = L;
    int p_right = middle+1;
    
    while(p_left<=middle && p_right <= R)
    {
        temp.push_back(arr[p_left]< arr[p_right]? arr[p_left++]:arr[p_right++]);
    }
    while(p_left<=middle)
    {
        temp.push_back(arr[p_left++]);
    }
    while(p_right<=R)
    {
        temp.push_back(arr[p_right++]);
    }
    
    for(int i = L;i<=R;i++)
    {
        arr[i] = temp[i-L];
    }
}

void merge_sort(int arr[], int L,int R)
{
    if(L == R)
        return;
    int middle = L + ((R - L)>>1);
    merge_sort(arr,L,middle);
    merge_sort(arr,middle+1,R);
    merge(arr,L,middle,R);
}


