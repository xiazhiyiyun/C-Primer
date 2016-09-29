#C++11 auto

##写在开始的话
本文主要是在学习过程中整理的相关知识和笔记，鉴于本人菜鸟的属性，文章中大多都是老生常谈的基础问题。有书本的知识，也有网上的相关知识，如借鉴了他人的博客知识，会附上参考文献，如若无意中侵权，请联系本人删除。

##auto

###C++98 auto
在C++98标准中就存在着auto关键字，C++98标准中auto关键字用于自动变量的声明，但在默认情况下即使不声明auto，函数内部的变量也是具有自动存储期的。因此由于使用极少且多余，在C++11中已删除这一用法。
```c++
void fun()
{
    int i        = 10;//自动变量，函数块结束后，i便不存在
    auto j       = 10;//自动变量，函数块结束后，j便不存在
    static int k = 10;//静态变量，即使函数块结束后，k仍然是存在的，再次进入该函数块后，便可访问其值。
}
```

###C++11 auto
C++11新标准引入了auto类型说明符，采用它可以让编译器帮助我们分析表达式所属的类型。自C++11以来，auto关键字用于两种情况：声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符。

###auto自动推断类型
auto可以在声明变量时根据变量初始值的类型自动为此变量选择匹配的类型。显然，auto定义的变量必须含有初始值。

**auto声明变量**
```c++
auto s("hello");  //const char*
auto i  = 10;    //i 为int类型
auto f  = 3.14;  //f 为double类型
auto z  = new auto(9); // int*
```
使用auto可以在一条语句中声明多个变量，而由于一条声明语句中直接有一个基本数据类型，所以语句中所有基本数据类型都必须一样。而&，*只是从属于某个声明符，不是基础数据类型的一部分。
```c++
auto i  = 0，*p = &i； //基本数据类型为int，i为int类型，p为指向int类型的指针
auto x1 = 5, x2 = 5.0; //错误，x1和x2的类型不一致。
```

当然，初始值可以为表达式，此时编译器根据表达式的结果推断出auto的类型

**auto与表达式**
```c++
auto item = val1 + val2; //由val1和val2相加的结果推断出item的类型
```

但是，这么简单的变量声明类型，不建议用auto关键字，这样会降低程序的可读性。而是应更清晰地直接写出其类型。

auto关键字更适用于类型冗长复杂、变量使用范围专一时，使程序更清晰易读

**auto用于类型冗长复杂的变量类型**
```c++
std::vector<int> vec;

std::vector<int>::iterator::it = vec.begin(); 
auto it                        = vec.begin(); //类型同上

std::vector<int>::iterator::it = vec.begin();
const auto                     = vec.begin(); //类型同上
```

**复合常量，引用和auto**
使用auto关键字做类型自动推导时，依次施加以下规则：

    首先，如果初始化表达式是引用，首先去除引用；
    上一步后，如果剩下的初始化表达式有顶层的const且/或volatile限定符，去除掉。

当引用作为初始值时，真正参与初始化的是引用对象的值。此时auto推断出的类型是引用对象的类型。如下：
```c++
int i  = 1;
int &r = i;
auto k = i; //int类型，非引用
```
auto忽略初始化表达式的const或volatile的属性。如下：
```c++
const int ci    = 1;
auto j          = c1;   //j 为int 类型，忽略ci的顶层const属性。
```
但是，在初始值为指向常量的指针的时候，会保留常量的const属性。若想要具有顶层的const属性，应该显示指明。
```c++
const int ci = 1;
auto p       = &ci; //p 为指针且对象为整形常量，即(const int *),保留了底层const
const ci1    = ci; //ci1 为const int类型
```
希望声明引用类型，则auto关键字还带上&号。此时声明引用类型，并且执行const剥除（const-stripping）

```c++
const int ci = 1;
auto r1      = ci; //r1 为int类型
auto &r      = ci; //r 类型为const int的对象ci的引用，
```
这是因为如果不抑制const剥除，则得到了一个非常量引用型变量，指向了const变量，这显然是不可接受的。

**auto与数组**
初始化表达式为数组，auto关键字推导的类型为指针。这是因为数组名在初始化表达式中自动隐式转换为首元素地址的右值。
但auto关键字加上引用，则auto定义变量的类型为数组的类型。
```c++
int a[6];  
auto j  = a;  // j 为int*类型
auto& k = a; // k 为int[6]类型
```
**auto用于模板函数**

在模板函数定义时，如果变量的类型依赖于模板参数，使用auto关键字使得在编译期确定这些类型，如：
```c++
template <class T, class U>void Multiply(T t, U u)
{
    auto v = t * u;
    std::cout<<v;
}
```

模板函数的返回类型如果也是依赖于从模板参数推导，
```c++
template <typename _Tx, typename _Ty>
auto multiply(_Tx v1, _Ty v2) -> decltype( _Tx * _Ty )
{
 return v1*v2;
}
auto result = multiply(101, 1.414); // 结果类型是double
```
**使用auto保存ambda表达式类型的变量声明**
```c++
auto ptr = [](double x){return x*x;};//类型为std::function<double(double)>函数对象
```
**除此之外的注意事项**
1.函数和模板参数不能被声明为auto，因为这样显然会破坏c++编译器的函数匹配。
```c++
void fun(auto parameter){} // 函数参数类型不可为auto  
  
template<auto T> // 模板参数类型不可为auto  
void Fun(T t){}  
```
2.定义在堆上的变量，使用了auto的表达式必须被初始化，auto是从初始值来退短出变量类型的。
```c++
auto int i = new int(9); //int *类型
auto int j = new int();  //Wrong！
```
3.**auto是一个占位符**，并不是一个他自己的类型，因此不能用于类型转换或其他一些操作，如sizeof和typeid

##Reference
[维基百科 Auto C++](https://zh.wikipedia.org/wiki/Auto_(C%2B%2B))
[C++11新特性——auto的使用](http://blog.csdn.net/huang_xw/article/details/8760403)
[C++11特性：auto关键字](http://www.cnblogs.com/QG-whz/p/4951177.html)