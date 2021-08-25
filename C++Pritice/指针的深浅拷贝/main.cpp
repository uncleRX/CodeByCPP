//
//  main.cpp
//  指针的深浅拷贝
//
//  Created by 任迅 on 2021/8/19.
//

#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
};

int main(int argc, const char * argv[]) {
    
    int i;
    float f;
    int *iPtr;
    cout << i << endl;
    cout << f << endl;
    cout << iPtr << endl;

    
    // 浅拷贝
    // 注意:在进行指针复制时，需要清楚知道自己所写的代码的全部细节，以确定何时可以使用浅拷贝，何时必须使用深拷贝，否则可能会引发内存的多次释放问题
    Person *p1 = new Person;
    p1->age = 18;
    Person *p2 = p1;
    cout << p1->age << p2->age << endl;
    p1->age = 16;
    cout << p1->age << p2->age << endl;
//    p1[7];
    // 深拷贝
    Person *p3 = nullptr;
//    memccpy(p3, p2, <#int __c#>, size_t __n)
    
  
    return 0;
}
