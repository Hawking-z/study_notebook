#include<iostream>
using namespace std;
#include"common.h"
#include "SmallSum.h"

void print_arr(int* arr,int len)
{
    for(int i = 0 ;i<len;i++)
    {
        cout<<arr[i]<<'\t';
    }
    cout<<endl;
}

int main()
{
    cout << "小和算法测试!"<<endl;

    srand(time(0));
   
    int arr[ARR_LEN] ;
    for(int i = 0;i<ARR_LEN;i++)
    {   
        arr[i] = rand()%MAX_NUM + 1;
    }

    print_arr(arr,ARR_LEN);
    SmallSum calc;
    int small_sum = calc.small_sum(arr,ARR_LEN);
    cout<<"小和求和为:"<<small_sum<<endl;
    
    calc.merge_sort(arr,0,ARR_LEN-1);
    print_arr(arr,ARR_LEN);

}