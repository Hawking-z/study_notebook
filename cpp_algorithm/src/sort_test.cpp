#include<iostream>
#include "common.h"
#include "SelectSort.h"
#include "BubbleSort.h"
#include "InsertSort.cpp"
#include "dichotomy.h"
#include "RecursionMax.h"
#include "MergeSort.h"

using namespace std;

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
    cout << "排序算法测试!"<<endl;

    srand(time(0));
   
    int arr[ARR_LEN] ;
    for(int i = 0;i<ARR_LEN;i++)
    {   
        arr[i] = rand()%MAX_NUM + 1;
    }

    cout<<"数组中的最大值为:"<<recursion_max(arr,0,ARR_LEN-1)<<endl;


    int temp[ARR_LEN];
    copy(begin(arr),end(arr),begin(temp));
    cout<<"排序前："<<endl;
    print_arr(arr,ARR_LEN);

    SelectSort select_sort;
    select_sort.sort(arr,ARR_LEN);
    cout<<"选择排序后："<<endl;
    print_arr(arr,ARR_LEN);
    copy(begin(temp),end(temp),begin(arr));

    BubbleSort bulle_sort;
    bulle_sort.sort(arr,ARR_LEN);
    cout<<"冒泡排序后:"<<endl;
    print_arr(arr,ARR_LEN);
    copy(begin(temp),end(temp),begin(arr));

    InsertSort insert_sort;
    insert_sort.sort(arr,ARR_LEN);
    cout<<"插入排序后:"<<endl;
    print_arr(arr,ARR_LEN);
    copy(begin(temp),end(temp),begin(arr));

    cout<<"归并排序后："<<endl;
    merge_sort(arr,0,ARR_LEN-1);
    print_arr(arr,ARR_LEN);


    // // 二分查找
    // Dichotomy b;
    // int search_num = rand()%MAX_NUM + 1;
    // cout << "查找数组中是否有"<<search_num<<":"<<b.search1(arr,ARR_LEN,search_num)<<endl;
    // int pos = b.search2(arr,ARR_LEN,search_num);
    // int one_hot[ARR_LEN] = {0};
    // one_hot[pos] = 1;
    // print_arr(one_hot,ARR_LEN);
    // cout << ">="<<search_num<<"最左侧的位置"<<":" <<pos<<",数字为"<<arr[pos]<<endl;

    // copy(begin(temp),end(temp),begin(arr));
    // one_hot[pos] = 0;
    // pos = b.local_minimum(arr,ARR_LEN);
    // if(pos !=-1) one_hot[pos] = 1;
    // cout<<pos<<endl;
    // print_arr(one_hot,ARR_LEN);
    
    return 0;
}