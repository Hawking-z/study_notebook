#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__

class BubbleSort
{
public:
    BubbleSort();
    ~BubbleSort();
    void sort(int* arr,int len);
private:
    void swap(int* arr,int i,int j);
};

#endif // __BULLE_SORT_H__

