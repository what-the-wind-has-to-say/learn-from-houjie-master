//allocator的allocate函数实际底层调用了malloc分配内存
//deallocate调用free释放内存
//malloc会带有额外的开销，因此需要减少malloc的次数
//由于直接调用分配器在归还内存时需要知道曾经分配内存大小
//因此不会直接调用分配器，而是通过容器调用
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec(10);
    int* p = allocator<int>().allocate(512);
    allocator<int>().deallocate(p,512);
    cout << 0 << endl;
    return 0;
}