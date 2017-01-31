> 2017年1月30日 周一
>
> 本文章仅为《C++ Primer 中文版》读书笔记，所有版权归原书所有。

### 一个简单的C++程序

```c++
#include<iostream>
using namespace std;

int main()
{
    return 0;
}
```

函数定义包括：

- 返回类型（return type）
- 函数名（function name）
- 形参列表（parameter list）
- 函数体（function body）

main函数比较特殊，返回值必须为int类型，大多数系统中，main函数的返回值用来只是状态，返回0表示成功，非0的函数值由系统定义，通常用来指示错误类型。

> mian函数虽然称之为c/c++等语言的入口，但是操作系统装载程序后，首先运行的并不是main函数的第一行代码，而是某些别的代码，这些代码负责准备好main函数执行所需要的环境，并且负责调用main函数。在main函数返回之后，它会记录main函数的返回值，调用atexit注册的函数，然后结束进程。

### 输入、输出

C++语言本身并没有提供任何的输入输出语句。而是使用了一个全面的标准库来提供IO机制。例如iostream库，包含两个基本类型，istream（输入流）和ostream（输出流）。

> 术语**流（stream）**的意思是：随着时间的推移，字符是顺序生成和消耗的。

##### 标准输入输出对象

- cin 标准输入
- cout 标准输出
- cerr、clog 标准错误，输出警告和错误信息

##### demo

```c++
#include<iostream>
using namespace std;

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1 + v2 << std::endl;
    return 0;
}
```

1. include<iostream> 用于告知编译器我们想使用iostream库。
2. <<（输出运算符），接受两个运算对象，左侧对象必须为ostream对象，右侧运算对象是要打印的值。此运算符将给定的值写到给定的istream对象中。计算结果就是给定的ostream对象。
3. endl，是一个被称为操纵符（manipulator）的特殊值。表示结束当前行。并将于设备关联的缓冲区（buffer）中的内容刷到设备中。
4. ::（作用域运算符），std::cout即指出我们想使用定义在命名空间std中的名字cout。命名空间可以使我们避免不经意的名字定义冲突。
5. \>>（输入运算符），接受一个istream对象作为其左侧运算对象，接受一个对象作为其右侧运算对象。从给定的istream读入数据，并存在给定对象中。返回其左侧运算对象作为计算结果。

> 缓冲刷新操作可以保证到目前为止程序所产生的所有输出都真正写入到输入流中，而不是仅停留在内存中等待输入流。

### 控制流（流程控制）

- while语句：反复执行一段代码，直到给定条件为假为止
- for语句：也用来反复执行一段代码，但形式上略有不同
- if...else...语句：用来支持条件执行



