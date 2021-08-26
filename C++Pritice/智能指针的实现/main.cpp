//
//  main.cpp
//  智能指针的实现
//
//  Created by 任迅 on 2021/8/25.
//

#include <iostream>
#include <mutex>

using namespace std;

// 实现一个线程安全的智能指针

// 1. 引用计数基类

class Sp_counter
{
private:
    size_t *_count;
    mutex mt;
    
public:
    Sp_counter() {
        cout << "父类构造, 分配counter内存" << endl;
        _count = new size_t(0);
    }
    
    virtual ~Sp_counter()
    {
        if (_count && !(*_count))
        {
            cout << "父类析构" << endl;
            cout << "释放 count内存"<< endl;
            delete _count;
            _count = NULL;
        }
    }
    
    // 重载赋值符号.
    Sp_counter& operator=(Sp_counter &spc)
    {
        cout << "父类重载 = " << endl;
        cout << "释放 counter内存 " << endl;
        delete _count;
        this->_count = spc._count;
        return *this;
    }
    
    Sp_counter& GetCounter()
    {
        return *this;
    }
    
    size_t GET_Reference()
    {
        return *_count;
    }
    
    // 自增
    virtual void Increase()
    {
        mt.lock();
        (*_count)++;
        mt.unlock();
    }
    
    // 自减
    virtual void Decrease()
    {
        mt.lock();
        (*_count)++;
        mt.unlock();
    }
};


// 智能指针
template <typename T>
class smart_pointer : public Sp_counter
{
private:
    T *_ptr;
public:
    smart_pointer(T* ptr = NULL);
    ~smart_pointer();
    smart_pointer(smart_pointer<T> &);
    smart_pointer<T>& operator=(smart_pointer<T> &);
    T &operator*();
    T *operator->(void);
    size_t use_count();
};

// 带参数的构造函数
template <typename T>
inline smart_pointer<T>::smart_pointer(T *ptr)
{
    if (ptr)
    {
        cout << "子类默认构造" << endl;
        _ptr = ptr;
        // 自增
        this->Increase();
    }
}

// 子类析构函数
template <typename T>
smart_pointer<T>::~smart_pointer()
{
    // 指针非空才析构
    if (this->_ptr)
    {
        if (this->GET_Reference())
        {
            this->Decrease();
        }else
        {
            cout << "count为0 ,释放对象" << endl;
            delete _ptr;
            _ptr = NULL;
        }
    }
}

// 获取对自己引用的数量
template<typename T>
size_t smart_pointer<T>::use_count()
{
    return this->GET_Reference();
}

// 拷贝构造函数
template <typename T>
inline smart_pointer<T>::smart_pointer(smart_pointer<T> &sp)
{
    cout << "子类拷贝构造" << endl;
    // 防止对自己的拷贝
    if (this != &sp)
    {
        this->_ptr = sp._ptr;
        this->GetCounter() = sp.GetCounter();
        this->Increase();
    }
}

// 赋值构造
template <typename T>
smart_pointer<T> &smart_pointer<T>::operator=(smart_pointer<T> &sp)
{
    // 防止自己对自己的赋值及指向相同内存单元的赋值
    if (&sp == this)
    {
        return *this;
    }
    if (this->_ptr && this->_ptr != sp._ptr)
    {
        // 等号 左边引用计数 - 1 , 右边引用计数 +1
        this->Decrease();
        if(this->GET_Reference() == 0)
        {
            cout<< "引用计数为0,主动调用析构"<<endl;
            this->~smart_pointer();
        }
        this->_ptr = sp._ptr;
        this->GetCounter() = sp.GetCounter();
        this->Increase();
    }
    
    return  *this;
}

// 重载 *(解引用) ->运算符
template <typename T>
inline T &smart_pointer<T>::operator*() {
    return *(this->_ptr);
}

template <typename T>
inline T *smart_pointer<T>::operator->(void) {
    return this->_ptr;
}


class Body
{
public:
    string name;
    Body() {
        cout<< "Body 无参构造" << endl;
    }
    
    Body(Body& sp) {
        cout<< "来源: " << sp.name << endl;
        cout<< "Body 拷贝构造" << endl;
    }
    
    ~Body() {
        
        cout<< "Body 析构 name:" << name << endl;
    }
};

int main(int argc, const char * argv[]) {
    /** normal construction
    Body a;
    Body b;

    a.name = "a";
    b.name = "b";

    b = a;
    printf("%p", &a);
    printf("%p", &b);
     */
//    Body *b1 = new Body();
//    b1->name = "b1";
//
//    Body *b2 = new Body();
//    b2->name = "b2";
    


    int *a = new int(10);
    int *b = new int(20);
    cout << "-----------默认构造测试-------------" << endl;
    smart_pointer<int> sp(a);
    cout << "sp.use_count:" << sp.use_count() << endl;
    cout << "----------------------------------" << endl;
    
    {
        cout << "-----------拷贝构造测试-------------" << endl;
        smart_pointer<int> sp1(sp);
        smart_pointer<int> sp2(sp1);
        cout << "sp1.use_count:" << sp1.use_count() << endl;
        cout << "sp2.use_count:" << sp2.use_count() << endl;
    }
    cout << "sp.use_count:" << sp.use_count() << endl;
    
    return 0;
}
