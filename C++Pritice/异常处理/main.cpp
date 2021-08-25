//
//  main.cpp
//  异常处理
//
//  Created by 任迅 on 2021/8/4.
//

#include <iostream>

using namespace std;

int setAge(int a, int b)
{
    if (a < 0) {
        throw "年龄不能小于0";
    }
    return a + b;
}

int main(int argc, const char * argv[])
{
    setAge(1,2);
    try {
        setAge(-1,-2);
    } catch(const char* msg) {
        cout << msg << endl;
    }
    return 0;
}
