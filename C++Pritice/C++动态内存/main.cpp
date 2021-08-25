//
//  main.cpp
//  C++动态内存
//
//  Created by 任迅 on 2021/8/4.
//

#include <iostream>

using namespace std;


class Box
{
public:
    Box() {
        cout << "调用构造函数！" <<endl;
    }
    
    ~Box() {
        cout << "调用析构函数！" <<endl;
    }
};

int main(int argc, const char * argv[]) {

    int *pPtr = NULL;
    pPtr = new int; // new 不只是分配了内存，它还创建了对象。
    *pPtr = 100;
    cout << "值" << *pPtr << endl;
    delete pPtr;
    
    // 数组的动态内存分配
    char *pvalue = NULL; // 初始化为 null 的指针
    pvalue = new char[20]; // 为变量请求内存
    delete [] pvalue; // 释放pvalue 所指向的数组
    
    
        Box* myBoxArray = new Box[4];
   
     delete [] myBoxArray; // 删除数组
    Box myBoxArray1;
    
    return 0;
}
