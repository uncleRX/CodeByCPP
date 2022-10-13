//
//  main.cpp
//  内存溢出测试
//
//  Created by 任迅 on 2022/1/21.
//

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>

//struct MyStruct
//{
//    uint8_t a[0x10000];
//    MyStruct() : a{} {}
//};
//
//void fun(int n)
//{
//    if (n > 0x20)
//    {
//        return;
//    }
//    MyStruct s;
//    std::cout << "address: " << std::hex << (int64_t)(&s) << std::endl;
//    fun(n+ 1);
//}

class Vec2 {
public:
    int x{0};
    int y{0};
};

void read(std::vector<Vec2>& list)
{
    std::vector<Vec2>tem;
    Vec2 a{1,2};
    tem.emplace_back(a);
    
    list = tem;
    list[0].x = 2;
    
    std::cout << "list: " << list[0].x << std::endl;
    std::cout << "tem: " << tem[0].x << std::endl;
}

int main()
{
//    fun(0);
    
//    unsigned long oneMSize = 1 * 1024 * 1024 / 4;
//    std::vector<float> a;
//    a.resize(oneMSize * 1100);
//
//
//    std::cout << a[400] << std::endl;
    
    std::cout << sizeof("你") << std::endl;
    std::cout << sizeof("a") << std::endl;
    std::cout << sizeof("☀️") << std::endl;
    std::cout << sizeof("😊") << std::endl;

    std::vector<Vec2>list;
    read(list);
//    std::cout << list[0].x << std::endl;
    return 0;
}
