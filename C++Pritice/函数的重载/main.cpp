//
//  main.cpp
//  函数的重载
//
//  Created by 任迅 on 2021/8/4.
//

#include <iostream>
using namespace std;

// 重载函数
int add(int a, int b)
{
    return a + b;
}

double add(double a, double b, double c)
{
    return a + b + c;
}


// 重载运算符

class Man
{
public:
    int age;
    
    int operator+(const Man& b)
    {
        int age = this->age + b.age;
        return age;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << add(1, 2) << endl;
    cout << add(2.0, 2.1, 3.011) << endl;
    
    Man m1, m2;
    m1.age = 1;
    m2.age = 2;
    cout << "重载运算符号:" <<m1 + m2 << endl;
    return 0;
}
