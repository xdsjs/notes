/*************************************************************************
	> File Name: 3-2-3.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  2/11 16:34:34 2017
 ************************************************************************/

#include<iostream>
#include<cctype>
using namespace std;

int main()
{
    string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;
    for(auto c : s)
        if(ispunct(c))
            ++punct_cnt;
    cout << punct_cnt << " punctuation characters in " << s << endl;
    return 0;
}

