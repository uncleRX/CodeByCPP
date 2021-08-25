//
//  数组.cpp
//  C++Pritice
//
//  Created by 任迅 on 2021/8/3.
//

#include "数组.hpp"
#include <iostream>
using namespace std;


void m_array() {
    // 声明
    double balance1[10];
    double balance2[5] = {1, 2, 3, 4, 5};
    double balance3[] = {1, 2, 3, 4, 5};
    // 获取
    double salary = balance3[2];
    
    for (double value : balance3) {
        cout << value << endl;
    }
    
}
