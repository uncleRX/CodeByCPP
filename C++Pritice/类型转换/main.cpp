//
//  main.cpp
//  类型转换
//
//  Created by 任迅 on 2021/9/7.
//

#include <iostream>
#include <memory>

class A {
public:
    int a = 10;
};

class B : public A {
    int b = 90;
};

class C {
    
};


void testPoint(A *dst)
{
    printf("里面 %p \n", dst);
    A *tem = new A();
    (*dst) = *tem;
    printf("里面tem: %p \n", dst);
}

void testPoint1(A **dst)
{
    A *tem = new A();
    *dst = tem;
}

typedef std::shared_ptr<B> BRef;
typedef std::shared_ptr<A> ARef;


int main(int argc, const char * argv[]) {

    B* b = new B();
    A* a = static_cast<A*>(b);
    
    ARef aRef = std::make_shared<A>();
    BRef bRef = std::static_pointer_cast<B>(aRef);
    
    ARef a1 = std::make_shared<B>();
    BRef b1 = std::static_pointer_cast<B>(a1);
    
    A* dst = nullptr;
    testPoint(dst);
    
    A* dst1 = new A();
    printf("外面%p \n", dst1);
    dst1->a = 1;
    testPoint(dst1);
    printf("外面 %p\n", dst1);

    return 0;
}
