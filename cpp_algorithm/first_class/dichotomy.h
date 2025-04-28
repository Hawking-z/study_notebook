#ifndef __DICHOTOMY_H__
#define __DICHOTOMY_H__


// 二分法及其拓展
class Dichotomy
{
public:
    Dichotomy();
    ~Dichotomy();
    bool search1(int* arr,int len,int num);
    int search2(int* arr,int len,int num);
    int local_minimum(int* arr,int len);
};



#endif