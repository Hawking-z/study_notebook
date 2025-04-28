#ifndef __SELECT_SORT_H__
#define __SELECT_SORT_H__

class SelectSort
{
public:
    SelectSort();
    ~SelectSort();
    void sort(int *arr, int len);
private:
    void swap(int *arr, int i,int j);
  
};



#endif // __SELECT_SORT_H__