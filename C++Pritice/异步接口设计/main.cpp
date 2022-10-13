//
//  main.cpp
//  异步接口设计
//
//  Created by 任迅 on 2021/12/9.
//

#include <iostream>

typedef void(*p_name)(int v);

void AsyncFunc(int result)
{
    printf("%d",result);
}

void getNum(int a,void(*p_name)(int))
{
    printf("%d",a);
    p_name(2);
}

int main(int argc, const char * argv[]) {
    
    getNum(1, AsyncFunc);
    return 0;
}


