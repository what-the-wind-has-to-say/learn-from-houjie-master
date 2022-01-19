//Separate Chaining
//若链表长度大于bucket的个数，需要打散rehashing,将bucket数目翻倍,选择倍数附近的素数
//hashFcn将data映射为hashcode
//ExtractKey 萃取Key EqualKey Key如何比较
//vector<node*,Alloc>buckets
#include<bits/stdc++.h>
using namespace std;
struct eqstr
{
    bool operator()(const char* s1,const char* s2) const
    {
        return strcmp(s1,s2) == 0;
    }
};
int main()
{
    return 0;
}