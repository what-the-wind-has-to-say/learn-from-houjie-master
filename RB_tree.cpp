//Red-Black tree 高度平衡二叉搜索树
#include<bits/stdc++.h>
using namespace std;
template<class T>
struct Less
{
    bool operator()(const T&x,const T&y) const
    {
        return x < y;
    }
};
//set 和 map 均包含一个rb_tree
int main()
{
    _Rb_tree<int,int,_Identity<int>,Less<int>>mytree;
    mytree._M_insert_unique(3);
    mytree._M_insert_unique(8);
    mytree._M_insert_unique(5);
    mytree._M_insert_unique(9);
    mytree._M_insert_unique(13);
    mytree._M_insert_unique(3);
    cout << mytree.empty() << endl;
    cout << mytree.size() << endl;
    cout << mytree.count(3) << endl;
    vector<int>vec = {4,2,56,77,3};
    sort(vec.begin(),vec.end(),Less<int>());
    for(int i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}