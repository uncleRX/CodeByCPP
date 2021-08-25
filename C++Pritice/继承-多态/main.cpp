//
//  main.cpp
//  继承-多态
//
//  Created by 任迅 on 2021/8/4.
//

#include <iostream>
#include <math.h>
using namespace std;


class Test {
    
public:
    ~Test() {
        cout << "Test 释放" << endl;
    }
};

class Animal
{
public:
    
    int age;
    int width;
    int height;
    string name;
    Test *aa;
    
    ~Animal() {
        cout << "Animal 释放" << endl;
    }
    
    void eat() {
        cout << "eat" << endl;
    }
    
    void sleep() {
        cout << "sleep" << endl;
    }
    
    // 加上 virtual 之后编译器看的是指针内容, 而不是直接看的类型
    // 不要静态链接到该函数
    virtual void hahaha() {
        cout << "Animal: hhaha" << endl;
    }
    
    // 如果派生类需要重写,那么在基类就不能给出一个具体的实现,这时候可以用纯虚函数
    // = 0 告诉编译器函数没有主体
    virtual void virtualFunction() = 0;

};

Animal::Animal() noexcept : age(0), width(0), height(0), name(""), aa(nullptr) {
    
}



class Dog : public Animal {
public:
    
    void bark() {
        cout << "狗叫" << endl;
    }
    
    void hahaha() {
        cout << "Dog: hhaha" << endl;
    }
    
    void virtualFunction() {
        cout << "Dog: virtualFunction" << endl;

    }
};

class Cat : public Animal {
public:
    void hahaha() {
        cout << "Cat: hhaha" << endl;
    }
    
    void virtualFunction() {
        cout << "Cat: virtualFunction" << endl;

    }
};

int main(int argc, const char * argv[]) {
    Animal();

    Cat c1;
//    Dog d1;
    
    c1.name = "新名字";
    cout << "c1.name" << c1.name << endl;
    

    // 静态链接 - 函数调用在程序执行前就准备好了。有时候这也被称为早绑定
//    Animal *ptr;
//    ptr = &c1;
//    ptr->hahaha();
//
//    ptr = &d1;
//    ptr->hahaha();
//
//    ptr->virtualFunction();
    
    return 0;
}
