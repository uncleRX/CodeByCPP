//
//  main.cpp
//  指针
//
//  Created by 任迅 on 2021/8/3.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int var1;
    int var2[10] = {1,2,3};
    

//    cout << "var1 变量的地址: "<< &var1 << endl;
//    cout << "var2 变量的地址: "<< &var2 << endl;
//    cout << "地址:" << &var2[0] << endl;

    
    // C++ 中指针
    int var = 20;
    int *ptr = &var;

    
    cout << "var地址:" << &var << endl;

    cout << "地址:" << ptr << endl;
    cout << "值:" << *ptr << endl;
    
    
    int *ptr1;
    
    int *ptr2 = NULL;
    
    cout << "prt1 " << ptr1 << endl;
    cout << "prt2 " << ptr2 << endl;
    
    return 0;
}
