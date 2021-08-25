//
//  main.cpp
//  C++内存分配测试
//
//  Created by 任迅 on 2021/8/4.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    char * p = new char[1];
    while(p) {
        p = new char[999999999];
        if( !(p = new char ))
        {
           cout << "Error: out of memory." <<endl;
           exit(1);
         
        }else {
            cout << "new success." <<endl;

        }
    }
    return 0;
}
