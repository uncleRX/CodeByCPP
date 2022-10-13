//
//  main.cpp
//  探索赋值
//
//  Created by 任迅 on 2021/11/9.
//

#include <iostream>

using namespace std;


class A {
public:
    int age = -1;
    std::string name;
    
    void log() {
        cout << "基类 age is: " << age << ", name is: " << name << endl;
    }
    
    A() {
        cout << "基类: 构造" <<endl;
    }
    
    A(const A& sp)
    {
        this->name = "基类重写";
        cout << "基类: 拷贝构造:" << sp.name <<endl;
    }
    
    A& operator=(A& b)
    {
        cout << "基类: ===重写" << "左边:" << this->age << ", 右边" << b.age <<endl;
        this->age = 111;
        return *this;
    }
};

class B : public A {
public:
    int bAge = -1;
  
    void log() {
        cout << "age is: " << age << ", name is: " << name << endl;
    }
    
    B() {
        cout << "构造" <<endl;
    }
    
    B(const B& sp) : A(sp)
    {
        cout << "拷贝构造:" << sp.name <<endl;
    }
    
    B& operator=(B& b)
    {
        cout << "===重写" << "左边:" << this->age << ", 右边" << b.age <<endl;
        if (&b == this) {
            return *this;
        }
        A::operator=(b);
        this->bAge = this->age + 1;
        return *this;
    }
};

class ClassA
{
public:
    B b1;
    std::shared_ptr<B> b2;
    B* b3 = nullptr;
    
    // 设置成员变量的值
    void SetValue(int i, int j, std::string name = "")
    {
        m_nValue1 = i;
        m_nValue2 = j;
        this->name = name;
    }
    void ShowValue()
    {
        cout << "m_nValue1 is: " << m_nValue1 << ", m_nValue2 is: " << m_nValue2  << "name:" << name << endl;
    }
        
private:
    int m_nValue1;
    int m_nValue2;
    std::string name;
};
 
int main()
{
    B a;
    B b;
    b = a;
    

    // 声明对象obj1和obj2
    ClassA obj1;
    obj1.b1.name = "我是b1";
    obj1.b1.age = 1;
    
    obj1.b2 = std::make_shared<B>();
    obj1.b2->name = "我是b2";
    obj1.b2->age = 2;
    
    obj1.b3 = new B();
    obj1.b3->name = "我是b3";
    obj1.b3->age = 3;
    
    ClassA obj2 = obj1;
    
    obj1.b1.name = "我是b1修改";
    obj1.b1.age = 1;

    obj1.b2->name = "我是b2修改";
    obj1.b2->age = 2;

    obj1.b3->name = "我是b3修改";
    obj1.b3->age = 3;

    obj1.b1.log();
    obj1.b2->log();
    obj1.b3->log();
    cout << "=================" << endl;
    obj2.b1.log();
    obj2.b2->log();
    obj2.b3->log();
 
    cout << "end" << endl;
    
    ClassA *o1ref = &obj1;
    ClassA *o2 = o1ref;
    
    return 0;
}

