#include<bits/stdc++.h>
using namespace std;
//数量不定的模板参数,以函数模板为例
void print()
{

}
template<typename T,typename... Types>
void print(const T& firstArg,const Types&... args)
{
    cout << firstArg << endl;
    print(args...);
}
int main()
{
    string str = "nanoha";
    double num = 1.44;
    //print(num,str,bitset<8>(16),45);
    int x = 0;
    int* p = &x;
    int& r = x;
    cout << p << endl;
    cout << *p << endl;
    cout << r << endl;
    int x2 = 5;
    r = x2;
    cout << x << endl;
    return 0;
}