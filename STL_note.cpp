//STL六大部件
//容器(Containers)
//分配器(Allocators)
//算法(Algorithms)
//迭代器(Iterators)
//适配器(Adapters)
//仿函式(Functors)
//-------------------------------------------------------
//容器的分类
//Sequence Containers

//Associative Containers
//set:底层红黑树，高度平衡二叉树，自动调整两边，为了避免查找时的最坏情况
//Multiset,Multimap,可以重复
//Unordered Containers:底层HashTable Separate Chaining(一串篮子，每一个篮子都是一个链表)

#include<bits/stdc++.h>
using namespace std;
void test1()
{
    vector<int> vi = {27,210,12,47,109,83};
    cout << count_if(vi.begin(),vi.end(),not1(bind2nd(less<int>(),40))) << endl;
}
int main()
{

    return 0;
}
