//
//  main.cpp
//  互斥锁mutex
//
//  Created by 任迅 on 2021/8/9.
//

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

// 基本流程
void base()
{
    // 1. 初始化互斥锁
    pthread_mutex_t mute = PTHREAD_MUTEX_INITIALIZER;
    //  动态初始化互斥锁
    pthread_mutex_init(&mute, NULL);
    // 加锁
    pthread_mutex_lock(&mute);
    // 解锁
    pthread_mutex_unlock(&mute);
    // 销毁互斥锁
    pthread_mutex_destroy(&mute);
    
    
    // 2. 条件变量
    // 初始化条件变量
    pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
    // 加锁
    pthread_mutex_lock(&mute);
    // 发送信号量, 跟wait函数不在同一个线程中
    pthread_cond_signal(&cond);
    // 阻塞线程，等待条件变量，同时解锁互斥量
    pthread_cond_wait(&cond, &mute);
    // 解锁
    pthread_mutex_unlock(&mute);
    // 销毁互斥锁
    pthread_mutex_destroy(&mute);
    // 销毁条件变量
    pthread_cond_destroy(&cond);
}

pthread_mutex_t mutex1;

void* print_msg(void *arg)
{
    // code
    pthread_mutex_lock(&mutex1);
    for (int i = 0; i < 15; i++) {
        cout << "output:" << i << endl;
        usleep(100);
    }
    pthread_mutex_unlock(&mutex1);
    return 0;
}


int main(int argc, const char * argv[]) {
    
    pthread_t id1;
    pthread_t id2;
    pthread_mutex_init(&mutex1, NULL);
    pthread_create(&id1, NULL, print_msg, NULL);
    pthread_create(&id2, NULL, print_msg, NULL);
    // 函数pthread_join用来等待一个线程的结束,线程间同步的操作
    pthread_join(id1, NULL);
    //函数pthread_join用来等待一个线程的结束,线程间同步的操作
    pthread_join(id2, NULL);
    pthread_mutex_destroy(&mutex1);
    return 0;
}
