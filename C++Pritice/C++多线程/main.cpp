//
//  main.cpp
//  C++多线程
//
//  Created by 任迅 on 2021/8/5.
//

#include <iostream>
#include <pthread/pthread.h>

using namespace std;

#define NUM_THREADS 5

static std::mutex mutex1;


void* say_hello(void* args)
{
    cout << "hello thread!" << endl;
    return 0;
}

void* printHello(void *threadid)
{
    int tid = *(int*)threadid;
    mutex1.lock();

    cout << "我是线程: " << tid << endl;
    mutex1.unlock();
    pthread_exit(NULL);
}

int main(int argc, const char * argv[]) {
    pthread_t threads[NUM_THREADS];
    int indexes[NUM_THREADS];// 用数组来保存i的值
    for (int i = 0; i < NUM_THREADS; ++i) {
        indexes[i] = i; // 先保存i的值
        mutex1.lock();
        cout << "创建线程: " << i << endl;
        int ret = pthread_create(&threads[i], NULL,
                                 printHello, (void *)&(indexes[i]));
        if (ret != 0) {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
        mutex1.unlock();
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
    return 0;
}
