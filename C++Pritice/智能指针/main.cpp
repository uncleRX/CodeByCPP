//
//  main.cpp
//  智能指针
//
//  Created by 任迅 on 2021/8/6.
//

#include <iostream>

using namespace std;

/*
 STL提供四种智能指针：auto_ptr、unique_ptr、shared_ptr和weak_ptr
 其中auto_ptr是C++98提供的解决方案，C++11以后均已摒弃。所有代码在gcc 8.1上编译。
 */

// auto_ptr 的类模板原型

//template <typename T>
//class Auto_ptr
//{
//
//public:
//    // 显示构造函数
//    explicit Auto_ptr();
//
//    ~Auto_ptr()
//    {
//        // 析构函数中删除ptr
//        delete _M_ptr;
//    }
//
//private:
//    T* _M_ptr;
//
//};

// 设计一个二叉树

class Node {
    int value;
    
public:
    // 左节点
    shared_ptr<Node> leftPtr;
    
    // 右节点
    shared_ptr<Node> rightPt;
    
    // 父节点 (注意循环引用,造成内存泄漏)
    weak_ptr<Node> parentPtr;

    Node(int va) : value(va)
    {
        cout << "Constructor" << endl;
    }

    ~Node()
    {
        cout << "Destructor" << endl;
    }
};

void testNode()
{
    shared_ptr<Node> ptr = make_shared<Node>(2);
    ptr->leftPtr = make_shared<Node>(1);
    ptr->rightPt = make_shared<Node>(3);
    ptr->leftPtr->parentPtr = ptr;
    ptr->rightPt->parentPtr = ptr;
    cout << "指针的使用数量:" << ptr.use_count() << endl;
}



class A
{
public:
    ~A()
    {
        cout << "A: 析构函数" << endl;
    }
};


// 临时右值
unique_ptr<string> temUnique(const char* s)
{
    unique_ptr<string> temp(new string(s));
    return temp;
}

int main(int argc, const char * argv[]) {


    // 防止内存泄漏的智能指针,它独享被管理对象的所有权
    unique_ptr<string> p1(new string("我是p1的值"));
    unique_ptr<string> p2;
    
    // 悬挂指针??
//    p1 = p2;
    unique_ptr<string> p3;
    // 当unique_ptr为临时右值时,是可以直接赋值的.
    // temUnique()返回临时指针时，p接管了原本归返回的unique_ptr所拥有的对象，而返回的unique_ptr被销毁
    p3 = temUnique("我是p3的值");
    cout << *p3 << endl;
    
    // 转让所有权
    p2 = move(p1);
    if (p2 != nullptr)
    {
        cout << *p2 << "地址为: " << p2 << endl;
    }
    
    /*
     shared_ptr基于"引用计数"模型实现，允许多个shared_ptr智能指针指向同一个动态对象，并维护一个共享引用计数器，当拷贝或赋值一个shared_ptr时计数器加一，被销毁时（如一个局部shared_ptr指针离开其作用域）计数器递减，当计数器变为0时，shared_ptr自动释放自己所管理的对象。有点像OC的对象里维护的弱引用标结构
     */
    // 初始化: make_shared是最安全的指针初始化方式
    string s = "p";
    shared_ptr<string> sPtr = make_shared<string>(s);
    
    // 裸指针初始化多个share_ptr
    string a = "a";
    shared_ptr<string> a1Ptr = make_shared<string>(a);
    shared_ptr<string> a2Ptr = make_shared<string>(a);
    
    a2Ptr = a1Ptr;
    cout << *a1Ptr << endl;
    cout << *a2Ptr << endl;
    
    *a1Ptr = "a修改";
    cout << *a1Ptr << endl;
    cout << *a2Ptr << endl;
    cout << "使用shared_ptr数量:" << a2Ptr.use_count() << endl;
    
    // 引入 weak_ptr的使用 , 用于解决shared_ptr循环引用导致的内存泄漏问题, 辅助 shared_ptr 使用
    weak_ptr<string> weakPtr(a1Ptr);
    cout << "引入 weak_ptr 之后, 使用shared_ptr数量:" << a2Ptr.use_count() << endl;

    auto *p0 = new string("hello");
    shared_ptr<string> a3Ptr(p0);
    cout << *a3Ptr << endl;

    // 测试二叉树
    testNode();
    
    return 0;
}
