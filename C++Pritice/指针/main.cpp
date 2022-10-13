//
//  main.cpp
//  指针
//
//  Created by 任迅 on 2021/8/3.
//

#include <iostream>

using namespace std;


class B
{
public:
    
    void log()
    {
        std::cout<< "哈哈哈哈哈" << std::endl;
    }
    
    B()
    {
        std::cout<< "B 构造" << std::endl;
    }
    
    ~B()
    {
        std::cout<< "B 析构" << std::endl;
    }
    
    B(const B& b)
    {
        std::cout<< "B 拷贝构造" << std::endl;
    }
    
    B(B& b)
    {
        std::cout<< "B 移动构造" << std::endl;
    }
};

class A
{
public:
    int age;
    B b;
    B* bRef
    
    ~A()
    {
        delete bRef;
        bRef = nullptr;
    }
    
    B get()
    {
        return this->b;
    }
    
//    void set(B b)
//    {
//        this->b = b;
//    }

    void set(B& b)
    {
        this->b = b;
    }
    
    B* getRef()
    {
        return this->bRef;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    {
        B a;
        B b = a;
    }

    
    B* ref = new B();
    A a;
    a.bRef = ref;
    a.get();
    a.getRef();
    
//    {
//        B b;
//        a.set(b);
//    }
    

//    a.b.log();
    
//    std::cout<< a.b << a.get() << std::endl;
//    a.get();
    
    
//    int var1;
//    int var2[10] = {1,2,3};
    

//    cout << "var1 变量的地址: "<< &var1 << endl;
//    cout << "var2 变量的地址: "<< &var2 << endl;
//    cout << "地址:" << &var2[0] << endl;

    
    // C++ 中指针
//    int var = 20;
//    int *ptr = &var;
//
//
//    cout << "var地址:" << &var << endl;
//
//    cout << "地址:" << ptr << endl;
//    cout << "值:" << *ptr << endl;
//
//
//    int *ptr1;
//
//    int *ptr2 = NULL;
//
//    cout << "prt1 " << ptr1 << endl;
//    cout << "prt2 " << ptr2 << endl;
    
    return 0;
}
