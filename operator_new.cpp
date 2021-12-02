#include<bits/stdc++.h>
using namespace std;
class Foo
{
public:
    int _id;
    long _data;
    string _str;
    Foo(int id):_id(id)
    {
        cout << "ctor.this = " << this << " id = " << _id <<endl;
    }
    Foo():_id(0)
    {
        cout <<"default ctor.this = " << this << " id = " << _id <<endl;
    }
    //virtual void virtual_function();
    ~Foo()
    {
        cout << "dctor.this = " << this << " id = " << _id << endl;
    }
    static void* operator new(size_t size);
    static void operator delete(void* pdead,size_t size);
    static void* operator new[](size_t size);
    static void operator delete[](void* pdead,size_t size);
};
void* Foo :: operator new(size_t size)
{
    Foo*p = (Foo*)malloc(size);
    cout << size << endl;
    return p;
}
void Foo :: operator delete(void* pdead,size_t size)
{
    cout << size << endl;
    free(pdead);
}
void* Foo :: operator new[](size_t size)
{
    Foo*p = (Foo*)malloc(size);
    cout << size << endl;
    return p;
}
void Foo :: operator delete[](void* pdead,size_t size)
{
    cout << size << endl;
    free(pdead);
}
int main()
{
/*     Foo* pf = new Foo;
    delete pf;
    Foo* pf1 = new Foo[5];
    delete [] pf1; */
    Foo* pf = new Foo(5);
    delete pf;
    return 0;
}