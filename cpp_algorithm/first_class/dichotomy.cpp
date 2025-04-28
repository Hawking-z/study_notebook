#include"dichotomy.h"
#include<iostream>
using namespace std;
Dichotomy::Dichotomy()
{

}
Dichotomy::~Dichotomy()
{

}
bool Dichotomy::search1(int* arr,int len,int num)
{
    if(arr[0]> num || arr[len-1]<num)
        return false;
    int L = 0;
    int R = len;
    int middle = (R+L)/2;
    while(L<=R)
    {
        middle = (R+L)/2;
        if(arr[middle] == num)
            return true;
        else if(arr[middle]<num)
        {
            L = middle+1;
            
        }
        else{
            R = middle-1;
        }      
    }
    return false;
}
// 找到大于等于num的最左边的位置
int Dichotomy::search2(int* arr,int len,int num)
{
    int L = 0;
    int R = len-1;
    int middle = (L+R) /2 ;
    while (L<=R)
    {
        middle = (L+R) /2 ;
        if(arr[middle]>= num)
        {
            R = middle - 1;
        }else{
            L = middle + 1;
        }
    }
    return L;
}

int Dichotomy::local_minimum(int* arr,int len)
{
    if(arr[0]<=arr[1]) return 0;
    if(arr[len-1]<=arr[len-2]) return len-1;
    int L = 1;
    int R = len-2;
    int middle = (R+L)/2;
    while(L<=R)
    {
        middle = (R+L)/2;
        if(arr[middle-1]>=arr[middle] && arr[middle]<=arr[middle+1])
            return middle;
        else if(arr[middle]>arr[middle-1])
        {
            R = middle -1;
        }else
        {
            L = middle + 1;
        }
    }
    return -1;

}