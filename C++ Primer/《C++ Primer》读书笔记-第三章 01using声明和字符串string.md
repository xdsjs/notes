> 2017年2月10日
>
> 本文章仅为《C++ Primer 中文版》读书笔记，所有版权归原书所有。

### using

使用using声明可以替代作用域操作符（::）

声明形式：using namespace::name; // 一旦声明了此语句，就可以直接访问命名空间中的名字。

```c++
#include <iostream>
using std::cin;

int main() 
{
  int i;
  cin >> i;  // 正确，cin和std::cin含义相同
  cout << i; // 错误，没有对应using说明，必须使用完整名字
  std::cout << i;  // 正确
  return 0;
}
```

- 按照规定，每个using声明引入命名空间中的一个成员
- 头文件不应包含using声明

### string字符串

##### 定义和初始化string对象

```c++
string s1;           // 默认初始化，s1是一个空字符串
string s2 = s1;      // s2是s1的副本
string s2(s1);       // 相当于string s2 = s1;s2是s1的副本
string s3 = "hiya";  // s3是该字符串字面值的副本
string s3("hiya");   // 相当于string s3 = "hiya";s3是字面值"hiya"的副本
string s4(10, 'c');  // s4的内容是cccccccccc
```

- 拷贝初始化：指的是使用等号（=）来初始化一个变量，编译器把等号右侧的初始值拷贝到新创建的对象中去
- 直接初始化：与拷贝初始化相反，不适用等号。

##### 读取string对象

1. 使用cin读取字符串，string对象会自动忽略开头的空白（即空格符、换行符、制表符等）并从真正的第一个字符开始读起，直到遇见下一处空白为止。
2. 如果希望保留输入时的空白字符，应该使用getline代替>>运算符。参数是一个输入流和一个string对象，函数从给定的输入流中读入内容，直到遇到换行符为止（换行符也读进来了）。然后把读取的内容存到string对象中（注意不存换行符）。即只要一遇到换行符就结束读取操作并返回结果。

> 出发getline函数返回的换行符实际上被丢弃掉了，得到的string对象中并不包括该换行符

##### 字符串比较规则

1. 如果两个string对象的长度不同，且较短string对象与较长string对象相比在每个位置的字符都相同，则认为较短的string小于较长的string对象。
2. 如果两个string对象在某些对应位置上不一致，则string对象的比较结果实际上是string对象中第一对相异字符的比较结果。

##### 基本操作

- 两个string对象相加得到一个新的string对象，实际上是把左侧和右侧的运算结果拼接起来
- 字面值与string相加，

##### 处理字符串中的字符

有时需要处理string对象中的特定字符，关于改变某个字符特性，可以使用cctype头文件。具体查看原书P82 表3.3。

可以使用基于范围的for语句获取每个字符

```c++
string s("Hello World");
// punct_cnt的类型和s.size()的返回类型是一样的
decltype(s.size()) punct_cnt = 0;
// 统计s中标点符号的数量
for(auto c : s)
  if(ispunct(c))
    ++punct_cnt;
cout << punct_cnt << " punctuation characters in " << s << endl;
```

当处理一部分字符时，可以使用下标运算符（[]），接受参数是string::size_tyoe类型的值。