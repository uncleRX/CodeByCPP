//
//  main.cpp
//  C++ Vector
//
//  Created by 任迅 on 2021/8/5.
//

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


typedef struct testEmplace
{
    testEmplace()
    {
        std::cout << "create testEmplace" << std::endl;
    }
    
    testEmplace(int a)
    {
        std::cout << "create testEmplace" << std::endl;
    }
    
    testEmplace(const testEmplace& scr)
    {
        std::cout << "copy testEmplace" << std::endl;
    }
    
    testEmplace(testEmplace& scr)
    {
        std::cout << "move testEmplace" << std::endl;
    }
    
    ~testEmplace()
    {
        std::cout << "destroy testEmplace" << std::endl;
    }
    
    testEmplace& operator = (const testEmplace& rht)
    {
        testEmplace a;
        cout << " operator =() testEmplace" << std::endl;
        return a;
    }
    

}testEmplace;


void printVector(vector<int> obj);

int main(int argc, const char * argv[]) {
    

//    // 什么是vectot
//    vector<int>obj; // 创建一个向量存储容器 int
//    for (int i = 0; i < 10; i++)
//    {
//        obj.push_back(i);
//        cout << "添加元素" <<obj[i] << "," ;
//
//    }
//    for (int i = (obj.size() - 1); i > 5; i--) {
//        obj.pop_back();
//    }
//    cout<<"\n"<<endl;
    
//    printVector(obj);

    // 清除容器中所有的数据
//    obj.clear();
//
//    cout<<"清除后"<<endl;

//    printVector(obj);
    
//    sort(obj.begin(), obj.end());
//    printVector(obj);
    
//    reverse(obj.begin(),obj.end());//从大到小
//    printVector(obj);
    
    // 使用迭代器:
//    vector<int>:: iterator it;
//    for(it = obj.begin(); it != obj.end(); it++)
//    {
//        cout << "迭代器:" << *it << " ";
//    }
//
//
//    for(auto a = obj.begin(); a != obj.end(); a++)
//    {
//        cout << "auto:迭代器:" << *a << " ";
//    }
    
    // 测试emplace
    vector<testEmplace> test;
    test.resize(2);
    
    std::cout << "#########push_back" << std::endl;
    test.push_back(1);//拷贝构造
    std::cout << "###########emplace_back" << std::endl;
    test.emplace_back(1);//移动构造
    
    std::cout << "xxxxxxxxxx" << std::endl;
    
    
    
    
    vector<testEmplace*> test1;
    testEmplace* a = new testEmplace();
    test1.emplace_back(a);
    test1.emplace_back(a);
    test1.emplace_back(a);
    test1.emplace_back(a);
    test1.emplace_back(a);
    test1.emplace_back(a);


//    testEmplace a;//构造
//    test.push_back(a);//拷贝构造
//    std::cout << "==============" << std::endl;
//
//    testEmplace b;//构造
//    test.push_back(std::move(b));//移动构造
//    std::cout << "==============" << std::endl;
//
//    test.emplace_back();//原地构造
//     std::cout << "==============" << std::endl;
//
//    testEmplace c;//构造
//    test.emplace_back(c);//拷贝构造
//    std::cout << "==============" << std::endl;
//
//    testEmplace d;//构造
//    test.emplace_back(std::move(d));//移动构造
    
    
    for (const auto &v : test)
    {
        test.pop_back();
    }
    
    return 0;
}


void printVector(vector<int> obj)
{
    for (int i = 0; i < obj.size(); i++) {
        cout << obj[i] << ",";
    }
}
