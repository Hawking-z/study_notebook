#ifndef __ODD_FIND_H__
#define __ODD_FIND_H__
#include <vector>
#include <utility>
using namespace std;

class OddFind
{
public:
    OddFind();
    ~OddFind();
    int findOne(vector<int> &vec);
    pair<int,int> findTwo(vector<int> &vec);
    void arr_gen(vector<int> &vec,int num);

};


#endif