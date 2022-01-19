#include<bits/stdc++.h>
using namespace std;
//底层实现原理，分段，串接
//buffer，缓冲区，分段连续
//vector<T*>map,串接的指针,T**，扩充时copy到中段来
//deque的迭代器iterator为一个class，内部cur,first,last,node指针
//node标识map指针,first,last标识buffer的范围,cur指向当前元素
//一个deque 4*4*2 + 4*2 = 40个字节
//insert函数会判断插入的代价，选择搬移前端或者后端
//重要的是对于迭代器iterator进行操作符重载
//a deque object
//_M_map 控制中心
//_M_map_size buffer的大小
//_M_start 迭代器
//_M_finish 迭代器
int main()
{
    deque<int>dq;
}
//stack queue内含一个deque，封锁掉deque的部分功能即可实现
//stack和queue都不允许遍历，也不提供迭代器iterator
//queue还可以选择list作为底层结构
//stack还可以选择vector作为底层结构