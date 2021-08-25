//
//  main.cpp
//  C++Pritice
//
//  Created by 任迅 on 2021/8/3.
//

#include <iostream>
#include "数组.hpp"

using namespace std;

extern void m_array();

void autoVariate() {
    auto f = 3.14;
    cout << typeid(f).name() << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    autoVariate();
    
        
    int my_array[5] = {1, 2, 3, 4, 5};
    // 每个数组元素乘于 2
    for (int &x : my_array)
    {
        x *= 2;
        cout << x << endl;
    }
    // auto 类型也是 C++11 新标准中的，用来自动获取变量的类型
    for (auto &x : my_array) {
        x *= 2;
        cout << x << endl;
    }
    
    cout << my_array[0] << endl;
    
    // 函数
    char c[] = "123";
    char s[] = "456";
    auto cs = strcat(c, s);
    cout << cs << endl;
    
    
    m_array();

    
    return 0;
}



