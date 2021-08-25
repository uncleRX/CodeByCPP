//
//  main.cpp
//  继承构造测试
//
//  Created by 任迅 on 2021/8/4.
//

#include <iostream>
#include <math.h>
using namespace std;

class Test {
public:
    string name;
    ~Test() {
        cout << "Test 释放" << endl;
    }
};


class BaseAnimal
{
public:
    Test* aa;
    
    BaseAnimal() : aa(nullptr) {
        
    }
    
    void log() {
        this->aa;
    }
    
    ~BaseAnimal() {
        cout << "BaseAnimal 释放" << endl;
        if (this->aa != nullptr) {
            cout << "BaseAnimal delete" << endl;
            delete this->aa;
        }
    }
};


class Animal : public BaseAnimal
{
public:
    
    int age;
    int width;
    Animal(int age, int width) noexcept : age(age), width(width) {
        
    }
    ~Animal() {
        cout << "Animal 释放" << endl;
    }
};


int main(int argc, const char * argv[]) {
    Animal a = Animal(19, 10);
    a.log();
//    a.aa = new Test();
//    a.aa->name = "名字";
//    cout << "name:" << a.aa->name << endl;
    return 0;
}
