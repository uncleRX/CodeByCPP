//
//  main.cpp
//  C++ 信号处理
//
//  Created by 任迅 on 2021/8/4.
//

#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

// 信号是由操作系统传给进程的中断

int signalHander(int signum) {
    exit(signum);
}

void signalHandler(int signum)
{
    cout << "Interrupt signal (" << signum << ") received.\n";
    // 清理并关闭
    // 终止程序
   exit(signum);
}

int main(int argc, const char * argv[]) {

    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);
    int i = 0;
    while(++i)
    {
         cout << "Going to sleep...." << endl;
         sleep(1);
        if (i == 3)
        {
            raise(SIGINT);
        }
    }
    return 0;
}
