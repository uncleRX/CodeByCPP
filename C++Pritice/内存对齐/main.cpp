//
//  main.cpp
//  内存对齐
//
//  Created by 任迅 on 2022/8/5.
//

#include <iostream>

// C++ 11
// alignas关键字用来设置内存中对齐方式，最小是8字节对齐，可以是16，32，64，128等。 一般是8 的倍数 跨平台好使

struct alignas(32) Student1 {
//    int age; // 4 Byte
    char name;
    int age;
};

struct Student2 {
    char name;
    char name1;

//    int age; // 4 Byte
    double height; // 8 Byte
};

class A {
    
public:
    int age;
    
    A()
    {
        
    }
    
    ~A()
    {
        std::cout << " ~A" << std::endl;
    }
};

int main(int argc, const char * argv[]) {
//    std::cout << "char:" << sizeof(char) << std::endl;
//    std::cout << "int:" << sizeof(int) << std::endl;
//    std::cout << "unsigned int:" << sizeof(unsigned int) << std::endl;
//    std::cout << "long int:" << sizeof(long int) << std::endl;
//    std::cout << "float:" << sizeof(float) << std::endl;
//    std::cout << "double:" << sizeof(double) << std::endl;
    
//    std::cout << "Student1:" << sizeof(Student1) << std::endl;
//    std::cout << "Student2:" << sizeof(Student2) << std::endl;
    
    float dd[10];
    std::cout << "dd:" << sizeof(dd) << std::endl;

    float *ee = new float[10];
    std::cout << "ee:" << sizeof(ee) << std::endl;
    std::cout << "*ee:" << sizeof(*ee) << std::endl;
    std::cout << "&(*ee):" << sizeof(&(*ee)) << std::endl;
    std::cout << "&(*ee):" << sizeof(*(&ee)) << std::endl;
    
    std::cout << "----------" << std::endl;
    
    

    {
        A a;
        std::cout << "----------" << sizeof(a) << std::endl;
        A a2;
        A a3;
        A a4;

        A list1[4] = {a, a2, a3, a4};
        std::cout << "----------" << sizeof(list1) << std::endl;
        
        int list2[10] = {};

        std::cout << "----------" << sizeof(list2) << std::endl;
    }


    
    return 0;
}
