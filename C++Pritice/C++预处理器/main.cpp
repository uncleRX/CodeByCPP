//
//  main.cpp
//  C++预处理器
//
//  Created by 任迅 on 2021/8/4.
//

#include <iostream>

using namespace std;

#define Development "1"

#ifdef Development
    #define ENV "Debug"
//elif else  + 条件
#else
    #define ENV "Release"
#endif

#define M_Max(a, b) (a > b? a : b)

// 嵌套宏
//#define M_OPERATOR(a) (M_Max(a, 0))++

int main(int argc, const char * argv[]) {
    
    cout << M_Max(1, 2) << endl;
    
    cout << "当前环境:" << ENV << endl;
    
//    cout << M_OPERATOR(1) << endl;

    return 0;
}
