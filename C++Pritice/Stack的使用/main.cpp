//
//  main.cpp
//  Stack的
//  stack是一种简单而常用的数据结构，stl库中提供了现成的实现方案。
//  Created by 任迅 on 2021/8/9.
//

#include <iostream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[])
{
    stack<int> s1;
    stack<int> s2;
    
    s2.push(6);


    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.swap(s2);
    
    cout << s1.top() << endl;
    cout << s2.top() << endl;

    return 0;
}
