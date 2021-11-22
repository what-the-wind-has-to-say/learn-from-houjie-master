#include<bits/stdc++.h>
using namespace std;
class Fraction
{
private:
    double m_numerator;//分子
    double m_denominator;//分母
public:
    Fraction(double num,double den):m_numerator(num),m_denominator(den){};
    //conversion function 转换函数
    operator double() const
    {
        return (double)(m_numerator/m_denominator);
    }
};
class Fraction2
{
private:
    double m_numerator;//分子
    double m_denominator;//分母
public:
    //non-explicit one argument constructor
    //避免隐式转换
    explicit Fraction2(double num,double den = 1):m_numerator(num),m_denominator(den){};
    Fraction2 operator + (const Fraction2& f)
    {
        double den = this->m_denominator*f.m_denominator;
        return Fraction2(this->m_numerator*f.m_denominator + this->m_denominator*f.m_numerator,den);
    }
    operator double()
    {
        return this->m_numerator/this->m_denominator;
    }
    void show()
    {
        cout << double(m_numerator)/double(m_denominator) << endl;
    }
};
int main()
{
    Fraction f(6,5);
    double d = 4 + f;
    cout << d << endl;
    Fraction2 f2(3,4);
/*     Fraction2 f3 = f2 + 4;
    f3.show(); */
    double d2 = f2 + 4;
    cout << d2 << endl;
    return 0;
}