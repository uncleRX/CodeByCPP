//
//  main.cpp
//  C++模板
//
//  Created by 任迅 on 2021/8/4.
//

#include <iostream>
#include <vector>

using namespace std;


// 函数模板
template <typename T>
T add(T a, T b) {
    return a + b;
}

// 类模板
template <class E>
class Stack
{
public:
    void push(E const& elem) {
        cout << "入栈:" << elem << endl;
    }
    
    void pop() {
        cout << "出栈" << endl;
    }
private:
    vector<E> elems;
};



int main(int argc, const char * argv[]) {
    
//    cout << add(1, 2) << endl;
//    cout << add(2.0, 1.43) << endl;
    
    Stack<int> intStack;
    Stack<string> strStack;

    
    intStack.push(4);
    strStack.push("哈哈哈");
    
    

    return 0;
}
