/*************************************************************************
	> File Name: 1-4-4.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  1/30 20:05:53 2017
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int currVal = 0, val = 0; // currVal是正在统计的数，将新读入的数值存入val
    // 读取第一个数，并保证确实有数据可以处理
    if (std::cin >> currVal) {
        int cnt = 1;     // 保存我们正在处理的当前值的个数
        while (std::cin >> val) {  // 读取剩余的数
            if (currVal == val)
                cnt++; // 如果值相同，将cnt加一
            else {
                std::cout << currVal << " occurs " << cnt << " times " << std::endl;
                currVal = val; // 记住新值
                cnt = 1;
            }
        }
        // 记住打印最后一个值的个数
        std::cout << currVal << " occurs " << cnt << " times " << std::endl;
    }
    return 0;
}
