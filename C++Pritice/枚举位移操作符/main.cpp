//
//  main.cpp
//  枚举位移操作符
//
//  Created by 任迅 on 2021/8/9.
//

#include <iostream>
using namespace std;

enum Direction
{
    DirectionTopTop = 1 << 0, // 4Byte, 32bit, 最多可以描述 2147483647  二进制  11 111111 111111 111111 111111 111111
    DirectionTopLeft = 1 << 1, //
    DirectionTopBottom = 1 << 2,
    DirectionTopRight = 1 << 3
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Direction dir = DirectionTopLeft;
    cout << "top: " << DirectionTopTop << endl;
    cout << "left: " << DirectionTopLeft << endl;
    cout << "bottom: " << DirectionTopBottom << endl;
    cout << "right: " << DirectionTopRight << endl;
    
    cout << "dir & DirectionTopTop = " << (dir&DirectionTopTop) << endl;
    cout << "dir & DirectionTopLeft = " << (dir&DirectionTopLeft) << endl;
    cout << "dir & DirectionTopBottom = " << (dir&DirectionTopBottom) << endl;
    cout << "dir & DirectionTopRight = " << (dir&DirectionTopRight) << endl;
    
    if (dir & DirectionTopTop) {
        cout << "DirectionTopTop" << endl;
    }
    if (dir & DirectionTopLeft) {
        cout << "DirectionTopLeft" << endl;
    }
    if (dir & DirectionTopBottom) {
        cout << "DirectionTopBottom" << endl;
    }
    if (dir & DirectionTopRight) {
        cout << "DirectionTopRight" << endl;
    }
    
    dir = (Direction)(DirectionTopTop | DirectionTopLeft | DirectionTopRight);
//    cout << dir << endl;
    
    
    return 0;
}
