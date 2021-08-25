//
//  main.cpp
//  Union的使用
//
//  Created by 任迅 on 2021/8/10.
//

#include <iostream>
using namespace std;


union CellSelectState {
    bool isSelect;
    bool isDisable;
    char qq;
    char zz;
    int num;

};

int main(int argc, const char * argv[]) {

    CellSelectState state;

    state.isSelect = true;
    state.qq = 'q';
    state.zz = 'z';
    state.num = 1;

    cout << "bool isSelect: " << state.isSelect << endl;
    cout << "bool disable: " <<state.isDisable << endl;
    cout << "qq: " << state.qq << endl;
    cout << "zz: " << state.zz << endl;
    cout << "num: " << state.num << endl;

    return 0;
}
