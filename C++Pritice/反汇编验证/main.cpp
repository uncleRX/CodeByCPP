//
//  main.cpp
//  反汇编验证
//
//  Created by 任迅 on 2022/6/10.
//

#include <iostream>

using namespace std;

void log()
{
    cout << "log" << endl;
}

void log(int a)
{
    cout << "log int" << a << endl;
}

void log(double a)
{
    cout << "log double" << a << endl;
}

int main(int argc, const char * argv[]) {
    log();
    log(10);
    log(10.0);
    

    return 0;
}
