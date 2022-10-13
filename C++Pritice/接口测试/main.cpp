//
//  main.cpp
//  接口测试
//
//  Created by 任迅 on 2021/11/15.
//

#include <iostream>
using namespace std;


class InterfaceA
{
public:
    virtual void log() = 0;
    bool flag;
};

class A : public InterfaceA
{
public:
    void log() override;
    bool flag = false;
};

void A::log()
{
    std::cout<< "log" <<endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    A a;
    a.log();
    
    return 0;
}
