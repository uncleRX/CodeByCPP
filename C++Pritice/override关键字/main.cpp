//
//  main.cpp
//  override关键字
//
//  Created by 任迅 on 2021/10/12.
//

#include <iostream>


#define ZHUQUE_IMP_PLATFORM
class Person
{
public:
    
    virtual void eat() = 0;
    
    virtual void say()
    {
        
    }
    void name()
    {
        
    }
};

class Student : public Person
{
public:
    void eat() override;
    void say() override;
    void name()
    {
        //
    }
};

void Student::eat()
{
    std::cout<< "吃食堂" << std::endl;
}

void Student::say()
{
    std::cout<< "学生读" << std::endl;
}


class RandomString {
    
public:
//    std::string getRandomStr(int len = 32)
//    {
//        char s[32] = {0};
//        int i,lstr;
//        char ss[2] = {0};
//        lstr = strlen(this->mStr);//计算字符串长度
//        srand((unsigned int)time((time_t *)NULL));
//        for(i = 1; i <= len; i++){
//            sprintf(ss,"%c",mStr[(rand()%lstr)]);
//            strcat(s,ss);
//        }
//        return s;
//    }
    
    static std::string getRandomStr(int len = 32)
    {
        static char *mStr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char s[32] = {0};
        int i,lstr;
        char ss[2] = {0};
        size_t = strlen(mStr);//计算字符串长度
        srand((unsigned int)time((time_t *)NULL));
        for(i = 1; i <= len; i++){
            sprintf(ss,"%c",mStr[(rand()%lstr)]);
            strcat(s,ss);
        }
        return s;
    }
    
private:
//    char *mStr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
};



int main(int argc, const char * argv[]) {
    
    std::string uuid = RandomString::getRandomStr();
    std::cout<< uuid << std::endl;

//
//    Student s1;
//    s1.eat();
//
//    Student* s2 = nullptr;
//    if (s2 != nullptr)
//    {
//        s2->say();
//    }
    
    return 0;
}
