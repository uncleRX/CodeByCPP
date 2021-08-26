//
//  main.cpp
//  继承
//
//  Created by 任迅 on 2021/8/4.
//

#include <iostream>

using namespace std;    


class BaseAnimal
{
public:
    
    ~BaseAnimal() {
        cout << "BaseAnimal 析构" << endl;
    }
    
    BaseAnimal() {
        cout << "BaseAnimal 构造函数" << endl;
    }
    
    BaseAnimal(BaseAnimal& sp) {
        cout << "BaseAnimal 拷贝函数" << endl;
    }

    void happy() {
        cout << "Happy" << endl;
    }
};

class Animal : public BaseAnimal
{
public:
    void eat() {
        cout << "eat" << endl;
    }
    
    void sleep() {
        cout << "sleep" << endl;
    }
    
    ~Animal() {
        cout << "Animal 析构" << endl;
    }
    
    Animal() {
        cout << "Animal 构造函数" << endl;
    }
    
    Animal(const Animal& sp) {
        cout << "Animal 拷贝函数" << endl;
    }

    string name = "皮特";
    
private:
    int age;
    int width;
    int height;
    
};

int main(int argc, const char * argv[]) {
//    Animal a = Animal();
//    a.name = "a";
//    Animal& b = a;
//    cout << "name" << b.name << endl;
    
    Animal* a1 = new Animal();
//    unique_ptr<Animal> aRef(a1);
//    unique_ptr<Animal> bRef;
//    bRef = move(aRef);
    
    shared_ptr<Animal> sRef1(a1);
    shared_ptr<Animal> sRef2 = sRef1;
    
    cout<< "sRef1.useCount: " << sRef1.use_count() << endl;
    cout<< "sRef2.useCount: " << sRef2.use_count() << endl;

//    cout << aRef->name << endl;
//    Animal c = a;
//    cout << c.name << endl;
    
    return 0;
}
