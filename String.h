#include<bits/stdc++.h>
using namespace std;

#ifndef __MYStr__
#define __MYStr__
class String
{
public:
    String(const char* cstr = 0)
    {
        if(cstr)
        {
            m_data = new char[strlen(cstr) + 1];
            strcpy(m_data,cstr);
        }
        else
        {
            m_data = new char[1];
            *m_data = '\0';
        }
    }
    String(const String& str);
    String& operator = (const String& str);
    ~String();
    char* get_c_str() const {return m_data;}
private:
    char* m_data;
    //如果类带有指针(pointer member)，自己写拷贝构造(copy ctor)和拷贝赋值(copy op=)
    //因为不确定字符串大小，所以初始只有一根指针，后来再分配内存
    //内存管理：栈(stack)，堆(heap)
    //static object 其生命在作用域结束之后依然存在，直到整个程序结束
    //new:先分配memory(malloc)，再调用ctor
    //上下cookie
    //delete:先调用dtor，再释放memory
    //String::~String(ps);
    //operator delete(ps);(free(ps))
};
//String :: function()

inline String :: String(const String& str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data,str.m_data);
}
inline String& String :: operator = (const String& str)
{
    if(this == &str)
    {
        return *this;//防止自我赋值
    }
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data,str.m_data);
    return *this;
}
inline String :: ~String()
{
    delete[] m_data;//防止内存泄漏
}
//Global-function()
ostream& operator << (ostream& os,const String& str)
{
    os << str.get_c_str();
    return os;
}
#endif