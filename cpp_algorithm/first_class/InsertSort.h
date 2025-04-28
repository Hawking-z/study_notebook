#ifndef __INSERTSORT_H__
#define __INSERTSORT_H__

class InsertSort
{
public:
    InsertSort();
    ~InsertSort();
    void sort(int* arr,int len);
private:
    void swap(int* arr,int i,int j);
};



#endif