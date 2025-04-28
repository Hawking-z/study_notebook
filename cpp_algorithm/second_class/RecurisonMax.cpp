#include "RecursionMax.h"
#include "algorithm"

int recursion_max(int arr[], int L,int R)
{
    if(L == R)
        return arr[L];
    int middle = L + ((R-L) >>1);
    int left_max = recursion_max(arr,L,middle);
    int right_max = recursion_max(arr,middle+1,R);
    return std::max(left_max,right_max);
}

