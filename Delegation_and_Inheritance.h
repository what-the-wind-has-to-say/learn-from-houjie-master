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
//让未来派生的子类自己创造一个原型(静态对象)，让框架(父类可以看到)可以看到
//框架配合虚函数
enum imageType
{
    LSAT,SPOT
};//定义一个枚举类型，只能等于LSAT或者SPOT
//Base
class Image
{
private:
    static vector<Image*>_prototypes;
    static int _nextSlot;
public:
    virtual void draw() = 0;//打印出这是子类的第几个对象
    static Image *findAndClone(imageType type);
    //用静态的子类原型调用父类的函数进行克隆
    protected:
        virtual imageType returnType() = 0;//得到Type名称
        virtual Image* clone() = 0;//要求子类能够以原型克隆自己
        static void addPrototype(Image* image)
        {
            _prototypes.push_back(image);
            _nextSlot = _prototypes.size();
        }
};
vector<Image*> Image::_prototypes;//类外初始化
int Image:: _nextSlot;
Image* Image::findAndClone(imageType type)
{
    for(int i = 0;i < _nextSlot;i++)
    {
        if(_prototypes[i]->returnType() == type)
        {
            return _prototypes[i]->clone();
        }
    }
}
//子类1
class LandSatImage: public Image
{
private:
    static LandSatImage _landSatImage;//静态的自己
    LandSatImage()
    {
        addPrototype(this);
    }
    int _id;
    static int _count;
public:
    imageType returnType()
    {
        return LSAT;
    }
    void draw()
    {
        cout << "LandSatImage::draw" << _id << endl;
    }
    Image* clone()
    {
        return new LandSatImage(1);
    }
protected:
    LandSatImage(int dummy)
    {
        _id = _count++;
    }
};
LandSatImage LandSatImage :: _landSatImage;
int LandSatImage :: _count = 1;
//子类2
class SpotImage: public Image
{
private:
    static SpotImage _spotImage;
    int _id;
    static int _count;
    SpotImage()
    {
        addPrototype(this);
    }
public:
    imageType returnType()
    {
        return SPOT;
    }
    void draw()
    {
        cout << "SpotImage::draw" << _id << endl;
    }
    Image* clone()
    {
        return new SpotImage(1);
    }
protected:
    SpotImage(int dummy)
    {
        _id = _count++;
    }
};
int SpotImage::_count = 1;
SpotImage SpotImage::_spotImage;
#endif