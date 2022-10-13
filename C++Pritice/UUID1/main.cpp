//
//  main.cpp
//  UUID1
//
//  Created by 任迅 on 2021/11/23.
//

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Random {
    
public:
    static std::uint32_t getUID(int len = 32)
    {
        string resultStr;
        static std::atomic<std::uint32_t> uid = 0;
        uid++;
        return uid;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << Random::getUID() << std::endl;
    std::cout << Random::getUID() << std::endl;
    std::cout << Random::getUID() << std::endl;
    std::cout << Random::getUID() << std::endl;

    return 0;
}
