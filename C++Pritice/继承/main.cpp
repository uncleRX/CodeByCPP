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
    void happy() {
        cout << "Happy" << endl;
    }
};

class Animal
{
public:
    void eat() {
        cout << "eat" << endl;
    }
    
    void sleep() {
        cout << "sleep" << endl;
    }
    
protected:
    string name = "皮特";
    
private:
    int age;
    int width;
    int height;
    
};

class Dog : public Animal,  public BaseAnimal {
    
public:
    void bark() {
        cout << "狗叫" << this->name << endl;
    }
};


int main(int argc, const char * argv[]) {
    
    
    Dog d;
    d.eat();
    d.bark();
    d.happy();
    return 0;
}
