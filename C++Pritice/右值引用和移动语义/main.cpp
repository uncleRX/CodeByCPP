//
//  main.cpp
//  右值引用
//
//  Created by 任迅 on 2021/8/19.
//

#include <iostream>


void addNum(int &a)
{
    a = a + 1;
}


class A
{
public:
    int value;
};

class B
{
public:
    A a;
};


void add(A** v)
{
    *v = new A();
    (*v)->value = 66;
}

void add(A*& v)
{
    v = new A();
    v->value = 77;
}

int main(int argc, const char * argv[]) {
    
    A* o = nullptr;
    add(&o);
    std::cout<<o->value<<std::endl;
    
    A* o1 = nullptr;
    add(o1);
    std::cout<<o1->value<<std::endl;
    
    A* o2 = nullptr;
//    add
    std::cout<<o1->value<<std::endl;
    

    int a;
    int b;
    a = 1;
    b = 4;
    
    // 左值引用
    int& ra = a;
    
    // 右值引用
    int &&rb = 3;
    
    rb = 4;
    
    addNum(a);
    std::cout<<a<<std::endl;

    std::cout<<ra<<std::endl;
    std::cout<<rb<<std::endl;
    
    return 0;
}

