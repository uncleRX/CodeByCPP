//
//  main.cpp
//  类 & 对象
//
//  Created by 任迅 on 2021/8/3.
//

#include <iostream>

using namespace std;

// this 指针来访问自己的地址 ,this 指针是所有成员函数的隐含参数,因此，在成员函数内部，它可以用来指向调用对象。
class Student {
    
public:
    // 静态成员变量
    static string className;
    
    int age;
    
    // 成员函数
    void learn(void);
    
    // 成员函数: 访问成员变量
    void growUp() {
        this -> age++;
        this->age++;
    }
    
    // 构造方法
    Student();
    
    // 带参构造方法
    Student(int);
    
    // 析构函数
    ~Student();
    
    /// 拷贝构造函数
    /// @param st 来源于另外一个对象, 默认编译器会帮我们实现一个
    Student(const Student &st);

    
    /// 友元函数,方便外部访问类的某个没有公开的数据
    /// @param s 拷贝的目标对象
    friend double getWeight(Student s);
    
    // 静态成员函数
    static int modifyName(string newName)
    {
        className = newName;
        cout << "静态成员函数";
        return 0;
    }
    
protected:
    // 受保护成员
    double weight;
    
private:
    // 私有成员

};

string Student::className = "A 级班";

double getWeight(Student s)
{
    cout << "友元函数:" << s.weight;
    return s.weight;
}

Student::Student(const Student &st)
{
    cout << "拷贝构造函数" << endl;
}

Student::Student() {
    cout << "初始化构造函数" << endl;
}

Student::~Student() {
    cout << "释放了 析构函数" << endl;
}

// 初始化字段
Student::Student(int age): age(age) {

}

class SubStudent : Student {
        
};

inline int Max(int x, int y) {
    return (x > y)? x : y;
}

void Student::learn(void) {
    cout << "学习" << endl;
}


int main(int argc, const char * argv[]) {
    
    Student s1 ;

    s1.age = 1;
    s1.learn();
    
    Student s2(22) ;

    Student s3 = s2;
    
    getWeight(s3);
    
    int maxV = Max(1, 2);
    cout << maxV << endl;
    
    s1.className = "B级大班";
    
    cout << "班级:" << s1.className << endl;
    
    cout << "班级:" << s2.className << endl;

    Student::modifyName("C级大班");
    cout << "修改后班级:" << s1.className << endl;

    return 0;
}
