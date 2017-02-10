> 2017年2月8日
>
> 本文章仅为《C++ Primer 中文版》读书笔记，所有版权归原书所有。

### 类型别名

> 是某种类型的同义词

##### 好处

- 可以使复杂的类型名字变得简洁明了、易于理解和使用

##### 定义方法

1. 使用typedef定义
   1. typedef double wages;  // wages是double的同义词
2. 新标准使用了别名声明（alias declaration）来定义类型的别名
   1. using wages = double;  // wages是double的同义词

##### 注意

遇到一条使用了类型别名的声明语句时，不能通过将类型别名替换成它本来的样子来理解语句的含义，这种理解是错误的。例:

```c++
typedef char *pstring;
const pstring cstr = 0;  // cstr是指向char的常量指针
const pstring *ps;  // ps是一个指针，它的对象是指向char的常量指针
```

pstring实际上是指向char的指针，因此const pastring是指向char的常量指针，而非指向常量字符的指针。

### auto类型说明符

C++新标准引入auto类型说明符，用来让编译器替我们去分析表达式所属的类型。通过初始值来推算变量的类型。

- auto定义的变量必须要有初始值
- 可以使用auto在一条语句中声明多个变量，但语句中所有变量的初始基本数据类型必须一致

```C++
// 由val1和val2的相加的结果可以推断出item的类型
auto item = val1 + val2;

auto i = 0, *p = &i;  // 正确：i是整数、p是整形指针
auto sz = 0, pi = 3.14;  // 错误：sz和pi的类型不一致
```

### decltype类型指示符

作用：选择并返回操作数的数据类型，在此过程中，编译器分析表达式并得到它的类型，却不实际计算表达式的值。

```c++
decltype(f()) sum = x;  // sum的类型就是f()的返回类型
```

注意编译器并不实际调用函数f，而是使用当调用发生时f函数的返回值来作为sum的类型。

##### decltype和引用

- 如果decltype使用的表达式不是一个变量，则decltype返回表达式结果对应的类型
- decltype的结果类型与表达式形式密切相关
  - 如果decltype使用的是一个不加括号的变量，则得到的结果就是该变量的类型
  - 如果给变量加上一层或多层括号，编译器就会把它当成是表达式，即得到的结果为引用类型

```c++
// decltype的结果可以使引用类型
int i = 42, *p = &i, &r = i;
decltype(r + 0) b;  // 正确，加法的结果是int，因此b的类型是未初始化的int
decltype(*p) c;     // c是int&，必须初始化

// decltype的表达式如果是加了括号的变量，结果将是引用
decltype((i)) d;  // 错误，d是int&，必须初始化
decltype(i) e;    // 正确，e是一个未初始化的int
```