#include<iostream>
#include"OddFind.h"
#include"common.h"
using namespace std;


int main()
{
    srand(time(0));
    
    cout<<"奇偶数查找"<<endl;
    OddFind find;
    vector<int> vec;

    find.arr_gen(vec,1);
    int ans = find.findOne(vec);
    cout<<"查找到的个数奇数的数为:"<<ans<<endl;
    find.arr_gen(vec,2);
    pair<int,int> res = find.findTwo(vec);
    cout<<"查找到的个数奇数的数为:"<< res.first <<","<<res.second<<endl;
    return 0;
}
