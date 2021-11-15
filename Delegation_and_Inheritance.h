#include<bits/stdc++.h>
using namespace std;
#ifndef __DandI__
#define __DandI__
//observer
//Delegation(委托)+Inheritance(继承)
class Observer
{
public:
    virtual void update(int value) = 0;//纯虚函数，被继承的类覆写
};
class Subject
{
//委托人
private:
    int m_value;
    vector<Observer*>m_views;
public:
    Subject(int value = 0):m_value(value)
    {
        
    };
    void attach(Observer* obs)
    {
        m_views.push_back(obs);//注册
    }
    void set_val(int value)
    {
        m_value = value;//更新被观察的数值
        notify();//唤醒所有观察者，更新观察的结果
    }
    void notify()
    {
        for(int i = 0;i < m_views.size();i++)
        {
            m_views[i]->update(m_value);
        }
    }
};
//观察者的派生类
class Observer1 : public Observer
{
private:
    int m_div;
public:
    Observer1(Subject* model,int div):m_div(div)
    {
        model->attach(this);
    }
    //覆写虚函数
    void update(int value)
    {
        m_div = 2*value;//以2倍来表示一种观察方式
        show();
    }
    void show()
    {
        cout << "Observer1 " << m_div << endl;
    }
};
class Observer2 : public Observer
{
private:
    int m_mod;
public:
    Observer2(Subject* model,int mod):m_mod(mod)
    {
        model->attach(this);
    }
    void update(int value)
    {
        m_mod = 4*value;//以4倍来表示一种观察方式
        show();
    }
    void show()
    {
        cout << "Observer2 " << m_mod << endl;
    }
};
//composite
//prototype
#endif