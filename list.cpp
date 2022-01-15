#include<bits/stdc++.h>
using namespace std;
//所有的容器除了vector array 之外 iterator 都必须是一个class smart pointer
int main()
{
    cout << sizeof(char) << endl;
    cout << sizeof(char*) << endl;
    int i = 6;
    ++++i;//说明整数的operator++返回的是reference,list的iterator向整数致敬
    cout << i << endl;
    return 0;
}
//前闭后开区间
