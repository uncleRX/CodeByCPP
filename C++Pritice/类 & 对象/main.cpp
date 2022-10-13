//
//  main.cpp
//  类 & 对象
//
//  Created by 任迅 on 2021/8/3.
//

#include <iostream>
extern "C"
{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
}

#include <map>
#include <list>
#include <queue>
#include <stack>
#include <regex>
#include <array>
#include <set>
#include <mutex>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <atomic>
#include <thread>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <condition_variable>
#include <semaphore.h>
#include <utility>
#include <variant>

using namespace std;

// this 指针来访问自己的地址 ,this 指针是所有成员函数的隐含参数,因此，在成员函数内部，它可以用来指向调用对象。
class Student {
    
public:
    // 静态成员变量
    static string className;
    
    int age;
    
    // 成员函数
    void learn(void);
    
    // 成员函数: 访问成员变量
    void growUp() {
        this -> age++;
        this->age++;
    }
    
    // 构造方法
    Student();
    
    // 带参构造方法
    Student(int);
    
    // 析构函数
    ~Student();
    
    /// 拷贝构造函数
    /// @param st 来源于另外一个对象, 默认编译器会帮我们实现一个
    Student(const Student &st);

    
    /// 友元函数,方便外部访问类的某个没有公开的数据
    /// @param s 拷贝的目标对象
    friend double getWeight(Student s);
    
    // 静态成员函数
    static int modifyName(string newName)
    {
        className = newName;
        cout << "静态成员函数";
        return 0;
    }
    
protected:
    // 受保护成员
    double weight;
    
private:
    // 私有成员

};

string Student::className = "A 级班";

double getWeight(Student s)
{
    cout << "友元函数:" << s.weight;
    return s.weight;
}

Student::Student(const Student &st)
{
    cout << "拷贝构造函数" << endl;
}

Student::Student() {
    cout << "初始化构造函数" << endl;
}

Student::~Student() {
    cout << "释放了 析构函数" << endl;
}

// 初始化字段
Student::Student(int age): age(age) {

}

class SubStudent : Student {
        
};

inline int Max(int x, int y) {
    return (x > y)? x : y;
}

void Student::learn(void) {
    cout << "学习" << endl;
}


class AB : public enable_shared_from_this<AB> {
public:
    virtual void xx() {
        
    }
};

class B : public AB
{
public:
    string name;
    
    virtual void xx()
    {
        
    }
    
    B()
    {
        std::cout << "B" << std::endl;
    }
    
    ~B()
    {
        std::cout << "~B" << this->name << std::endl;
    }
};


class BB : public B
{
public:
    BB()
    {
        std::cout << "BB" << std::endl;
    }
    ~BB()
    {
        std::cout << "~BB" << this->name << std::endl;
    }
};

static vector<shared_ptr<AB>> renderTempHold;
static set<shared_ptr<AB>> renderTempHold1;

class A
{
public:
    string name;
    B b;
    B *bPoint;
    
    
    static void add(shared_ptr<AB> value)
    {
        renderTempHold1.insert(value);
    }
    
    static void clear()
    {
        renderTempHold1.clear();
    }
    
    
    A()
    {
        std::cout << "A" << std::endl;
    }

    void log(B* b)
    {
        this->bPoint = b;
        std::cout << "b name: "<< b->name << std::endl;
    }
    
    void logBpoint()
    {
        std::cout << "logBpoint b name: "<< this->bPoint->name << std::endl;
    }
    
    ~A()
    {
        std::cout << "~A" << std::endl;
    }
};




static A *gl = new A();
int main(int argc, const char * argv[]) {
    
    {
        auto b = make_shared<BB>();
        A::add(b);
    }
    {
        A::clear();
    }
    
    {
        A a;
        a.b.name = "我是临时B";
        gl->log(&(a.b));
        printf("地址: %p \n", &a);
    }
    
    
    {
        auto *b = new B();
        shared_ptr<B> b1 = shared_ptr<B>(b);
    }
    
    printf("占用 %lu个字节 \n", sizeof(A));
    
    {
        A a;
        a.b.name = "xxxxxxxxx";
        printf("地址: %p \n", &a);
    }
    printf("%lu \n", sizeof(int));
    int list[100000];
    printf("地址: %p \n", list);
    printf("地址: %p \n", &list[1]);
    printf("地址: %p \n", &list[2]);
    printf("地址: %p \n", &list[3]);
    printf("地址: %p \n", &list[4]);
    {
        gl->logBpoint();
        gl->logBpoint();
    }
    
//    Student s1 ;
//
//    s1.age = 1;
//    s1.learn();
//
//    Student s2(22) ;
//
//    Student s3 = s2;
//
//    getWeight(s3);
//
//    int maxV = Max(1, 2);
//    cout << maxV << endl;
//
//    s1.className = "B级大班";
//
//    cout << "班级:" << s1.className << endl;
//
//    cout << "班级:" << s2.className << endl;
//
//    Student::modifyName("C级大班");
//    cout << "修改后班级:" << s1.className << endl;

    return 0;
}
