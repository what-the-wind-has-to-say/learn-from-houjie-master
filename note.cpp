//继承，虚函数，多态
//将Base类的指针存入容器,new的时候,new子类
//通过指针调用虚函数，向上转型，即可完成动态绑定
//vptr(虚指针),vtbl(虚表)

//const 修饰变量(data members 不得变动)
//const 修饰成员函数(函数体内保证不更改 data members)

//(charT)return type function() const
//(reference)return type function() 可以共存
//同时存在时,const对象只能调用const成员函数,non-const对象只能调用非const版本
//举例共享字符串，4个string，之存在一份，被共享,当需要改动的时候调用非const,重新复制一份,不需要改动的时候调用const，只读
//copy on write
//菜鸟的class就没有const

//array new 一定搭配 array delete