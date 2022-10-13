//
//  main.cpp
//  const
//
//  Created by 任迅 on 2021/9/22.
//

#include <iostream>
using namespace std;


void swap(int &a, int& b)
{
    int tem = a;
    a = b;
    b = tem;
}


void swap(int *a, int* b)
{
    int tem = *a;
    *a = *b;
    *b = tem;
}


void fill(int *a, int* b)
{
    int tmp1[] = {0, 1};
    int tmp2[] = {1, 2};

    a = (int *)malloc(sizeof(int) * 2);
    b = (int *)malloc(sizeof(int) * 2);
    memcpy(a, tmp1, sizeof(int) * 2);
    memcpy(b, tmp2, sizeof(int) * 2);
}

class B {
public:
    int index = 0;
};

class Base {
    
public:
    virtual B* getObject() const = 0;
};

class A : public Base
{
public:
    
    virtual B* getObject() const
    {
        return new B();
    }
    
private:
    B mObj;
};

class C : public A
{
public:
    
    B* getObject() const override
    {
        B* b = new B();
        b->index = 3;
        return b;
    }
    
private:
    B mObj;
};



int main(int argc, const char * argv[]) {
    
    
    A * a = new C();
    B* result = a->getObject();
    
    std::cout << result->index << std::endl;
    
    
    
    

    int list1[] = {};
    int list2[] = {};
    
    fill(list1, list2);
    
    int value1 = 10;
    int value2 = 20;
    
    const int * f = &value1;
    f = &value2;

    const int *b = &value1;
    b = &value2;
    
    std::cout << "b : " << *b << std::endl;
    
    // 1
//    const int a = 10;
//    a = 20;

    
//    int const a = 10;

    
//
//    const int a = 10;
//    a = 20;
//
    
   
    return 0;
}
