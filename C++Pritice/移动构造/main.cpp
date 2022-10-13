//
//  main.cpp
//  移动构造
//
//  Created by 任迅 on 2022/3/1.
//

#include <iostream>

class A {

public:
    int x;
    
    A()
    {
        std::cout << "构造\n";
    }

    A(int x)
    {
        std::cout << "构造\n";
    }
    
    A(A &scp)
    {
        std::cout << "拷贝构造\n";
    }
    
    A(A &&scp)
    {
        std::cout << "移动构造\n";
    }
    
    ~A()
    {
        std::cout << "析构\n";
    }
    
    A& operator=(A &spc)
    {
        std::cout << "A重载 = " << std::endl;
        return *this;
    }

};

A getObject()
{
    return A(1);
}

int main(int argc, const char * argv[]) {
  
//    A a;
//    A b = a;
//    A c = std::move(b);
    
    int x = 10 % 0;
    
    int x1 = 0 % 10;

    
    return 0;
}
