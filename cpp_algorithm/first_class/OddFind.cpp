#include "OddFind.h"
#include<unordered_map>
#include<iostream>
#include<algorithm>

OddFind::OddFind()
{

}
OddFind::~OddFind()
{

}
int OddFind::findOne(vector<int> &vec)
{
    int num = 0;
    for(auto it = vec.begin();it!=vec.end();it++)
    {
        num^=*it;
    }
    return num;
}

pair<int,int> OddFind::findTwo(vector<int> &vec)
{
    int eor = 0;
    for(auto it = vec.begin();it!=vec.end();it++)
    {
        eor^=*it;
    }

    // 提取数字中最右边的1
    // int num = eor & (-eor);
    int num = eor & (~eor + 1);
    
    int eor_ = 0;
    for(auto it = vec.begin();it!= vec.end();it++)
    {
        if(((*it) & num) == num)
        {
            eor_ ^= *it;
        }
    }

    return make_pair(eor_,eor^eor_);
    
}

void OddFind::arr_gen(vector<int> &vec, int num)
{  
    srand(time(0));
    unordered_map<int,int> random_map;
    while(random_map.size()<num)
    {
        int rand_num = rand()%20+1;
        int odd = (rand()%3)*2+1;
        random_map.insert(make_pair(rand_num,odd));
    }
    cout<<endl;
    for(int i = 0;i<10;i++)
    {
        int rand_num = rand()%20+1;
        int even = (rand()%3+1)*2;
        random_map.insert(make_pair(rand_num,even));
    }
    vec.clear();
    for(auto it = random_map.begin();it!=random_map.end();it++)
    {   
        cout<<"key:"<<it->first<<" value:"<<it->second<<endl;
        for(int j = 0;j<it->second;j++)
        {
            vec.push_back(it->first);
        }
    }
    random_shuffle(vec.begin(),vec.end());
    for(auto it = vec.begin();it!=vec.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}