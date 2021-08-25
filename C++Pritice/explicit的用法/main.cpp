//
//  main.cpp
//  explicit的用法
//  explicit 是避免构造函数的参数自动转换为类对象的标识符
//  Created by 任迅 on 2021/8/6.
//

#include <iostream>
using namespace std;

class A
{
public:
    int age;
    // 而且构造函数的参数只能有一个,c才能这么写
    explicit A(int a)
    {
        cout << "创建类成功了!:" << a << endl;
    }
};


int main(int argc, const char * argv[]) {

//    A a = 10;
    A a = A(11);
    cout << a.age << endl;
    
    //定义成这样的好处,在需要隐式转化的时候编译器会自动地帮我们转换
    string str = "hello";
    string str2 = string()
    return 0;
}
