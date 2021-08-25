//
//  main.cpp
//  补充 C++友元类
//
//  Created by 任迅 on 2021/8/6.
//

#include <iostream>
using namespace std;

class A
{
public:
    friend void printAge(A obj);
    
    ~A() {
        cout << "A释放了" << endl;
    }
    
    A() {
        
    }
    A(const A &obj) {
        cout << "A拷贝构造函数" << endl;
    }
private:
    int age;
    friend class B;

};

class B {
public:
    A a;
    A* aptr;
    void modifyAge(int age);
    void modifyPtrAge(int age);
    ~B() {
        delete aptr;
        cout << "B释放了" << endl;
    }
};

void printAge(A obj)
{
    cout << "age: " << obj.age << endl;
}

void B::modifyAge(int age)
{
    this->a.age = age;
}

void B::modifyPtrAge(int age)
{
    this->aptr->age = age;
}

int main(int argc, const char * argv[]) {

    // 非指针
//    A a;
//    B b;
//    b.a = a;
//    b.modifyAge(3);
//    printAge(b.a);
//
    // 指针 , 想实现OC里那种持有对象的话,并保持修改统一,必须用指针的方式
    A* aPtr = new A;
    B* bPtr = new B;
    
    bPtr->a = *aPtr;
    bPtr->aptr = aPtr;

    bPtr->modifyAge(4);
    bPtr->modifyPtrAge(66);
    
    printAge(*aPtr);
    aPtr = NULL;
    
    delete aPtr;
    delete bPtr;
    return 0;
}
