#include<bits/stdc++.h>
using namespace std;
#ifndef __CDocument__
#define __CDocument__
//composition
class C_composition
{
public:
    C_composition()
    {
        cout << "C_composition ctor" << endl;
    }
    ~C_composition()
    {
        cout << "C_composition dtor" << endl;
    }
};
//Base
class CDocument
{
public:
    C_composition c;
    CDocument()
    {
        cout << "CDocument ctor" << endl;
    }
    ~CDocument()
    {
        cout << "CDocument dtor" << endl;
    }
    void OnFileOpen()
    {
        cout << "dialog..." << endl;
        cout << "check file status..." << endl;
        cout << "open file..." << endl;
        Serialize();
        cout << "close file..." << endl;
        cout << "update all views..." << endl;
    }
    virtual void Serialize(){};//虚函数
};
//Derived
class CMyDoc : public CDocument
{
public:
    CMyDoc()
    {
        cout << "CMyDoc ctor" << endl;
    }
    ~CMyDoc()
    {
        cout << "CMyDoc dtor" << endl;
    }
    virtual void Serialize()
    {
        //只有应用程序本身才知道如何读取自己的文件(格式)
        cout << "CMyDoc::Serialize()" << endl;
    }
};
#endif