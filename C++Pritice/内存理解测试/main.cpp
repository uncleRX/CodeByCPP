//
//  main.cpp
//  内存理解测试
//
//  Created by 任迅 on 2021/8/6.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    char str1[] = "abc";
    char str2[] = "abc";
    const char str3[] = "abc";
    const char str4[] = "abc";
    const char *str5 = "abc";
    const char *str6 = "abc";
    char *str7 = "abc";
    char *str8 = "abc";
    
    cout << (str1 == str2) << endl;
    cout << (str3 == str4) << endl;
    cout << (str5 == str6) << endl;
    cout << (str7 == str8) << endl;

    return 0;
}
