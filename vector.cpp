#include<bits/stdc++.h>
using namespace std;
//vector含有三个指针，因此大小为12个字节(32位)
//start,finish,end_of_storage
//内存不够时，2倍扩充，寻找一块新的内存，拷贝，杀掉原内存
//当算法algorithm需要知道iterator迭代器的特性的时候，需要使用traits
//traits萃取机进行萃取，知道iterator的5个特征
//萃取机(traits)中使用了偏特化,为了区分iterator是类或者是一个指针的情况
int main()
{
    vector<int>vec;
}