//
//  main.cpp
//  测试recursive_mutex
//
//  Created by 任迅 on 2022/2/21.
//

#include <iostream>

using namespace std;

static recursive_mutex m{};

static int value = 0;

void addValue()
{
    value += 1;
//    printf("+ %d \n", value);
}

void subValue()
{
    value -= 1;
//    printf("- %d \n", value);
}

void* log_func(void* args)
{
    m.lock();
    int index =*(int*)args;
    printf("====异步开始: %d \n", index);
    for (int i = 0; i < 100; i++) {
        addValue();
        subValue();
        printf("====异步 %d \n", i);
    }
    printf("====异步结束: %d \n", index);
    m.unlock();
    return 0;
}

void* test(void * p)
{
    m.lock();
    for (int i = 0; i < 10; i++) {
        printf("@@开始: %d \n", i);
        pthread_t id1;
        int ret = pthread_create(&id1, NULL, log_func, &i);
        if (ret != 0)
        {
           cout << "pthread_create error: error_code=" << ret << endl;
        }
        printf("@@结束: %d \n", i);
    }
    m.unlock();
    return 0;
}


int main(int argc, const char * argv[]) {
    
    test(NULL);
    pthread_exit(NULL);
    return 0;
}
