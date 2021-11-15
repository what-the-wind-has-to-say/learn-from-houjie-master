#include<bits/stdc++.h>
using namespace std;
//guard
#ifndef __Complex_
#define __Complex__
class Complex
{
public:
    Complex(double r = 0,double i = 0):re(r),im(i){};
    double real () const { return re; }
    double imag () const { return im; }
    Complex& operator += (const Complex& r);
    //不带指针的类一般不用写析构函数
    //构造函数写进private,单例模式
    //不改变数据内容的成员函数，加上const
    //为了后续创建的const对象能够调用const成员函数
    //pass by value vs pass by reference (to const)
    //return by value vs return by reference
    //相同class的各个objects互为friend(友元)
    //成员函数隐藏一个this指针
    //传入参数加const表示在接下来的一个局部作用域内，其值不能被改变
private:
    double re,im;
    friend Complex& __doapl(Complex* ths,const Complex& r);
};
//函数
inline double imag(const Complex& x)
{
    return x.imag();
}
inline double real(const Complex& x)
{
    return x.real();
}
//非成员函数的重载(考虑到复数会与常数相加)
//2个参数，相加
inline Complex operator + (const Complex& x,const Complex& y)
{
    //不可以return by reference，因为，返回的必定是local object
    //temp object，临时对象
    return Complex(real(x) + real(y),
                    imag(x) + imag(y));
}
inline Complex operator + (const Complex& x,double y)
{
    return Complex(real(x) + y,imag(x));
}
inline Complex operator + (double x,const Complex& y)
{
    return Complex(x + real(y),imag(y));
}
inline Complex operator - (const Complex& x,const Complex& y)
{
    return Complex(real(x) - real(y),imag(x) - imag(y));
}
inline Complex operator - (const Complex& x,double y)
{
    return Complex(real(x) - y,imag(x));
}
inline Complex operator - (double x,const Complex& y)
{
    return Complex(x - real(y),imag(y));
}
inline bool operator == (const Complex& x,const Complex& y)
{
    return real(x) == real(y) && imag(x) == imag(y);
}
inline bool operator == (const Complex& x,double y)
{
    return real(x) == y && imag(x) == 0;
}
inline bool operator == (double x,const Complex& y)
{
    return x == real(y) && imag(y) == 0;
}
//1个参数，取正，取反
inline Complex operator + (const Complex& x)
{
    return x;
}
inline Complex operator - (const Complex& x)
{
    return Complex(-real(x),-imag(x));
}
//成员函数的重载
inline Complex& __doapl(Complex* ths,const Complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
    //自由取得friend的private成员
}
inline Complex& Complex :: operator += (const Complex& r)
{
    return __doapl(this,r);
}
//共轭复数
Complex conj (const Complex& x)
{
    return Complex(real(x),-imag(x));
}
//重载输出运算符
ostream& operator << (ostream& os,const Complex& x)
{
    return os << real(x) << " + " << imag(x) << 'i';
    //为了满足连续输出，函数返回类型不能为void
}
#endif