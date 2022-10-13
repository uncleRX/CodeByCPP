//
//  main.cpp
//  继承
//
//  Created by 任迅 on 2021/8/4.
//

#include <iostream>

using namespace std;    


class BaseAnimal
{
public:
    string asd;
    
    ~BaseAnimal() {
        cout << "BaseAnimal 析构" << endl;
    }
    
    BaseAnimal() {
        cout << "BaseAnimal 构造函数" << endl;
    }
    
    BaseAnimal(int age) {
        cout << "BaseAnimal 带参构造函数" << endl;
    }
    
    BaseAnimal(const BaseAnimal & ani)
    {
        cout << "BaseAnimal 拷贝造函数" << endl;
    }

    void happy() {
        cout << "Happy" << endl;
    }
    
    static void sMethod();
    
};

void BaseAnimal::sMethod()
{
    cout << "sMethod" << endl;
}

class Master {
    
public:
    string name;
};

class Animal : public BaseAnimal
{
public:
    Master *master;
    
    std::shared_ptr<Master> master2;
    
    string nickName;
    string fullName;
    
    int age = 1;
    int width = 1;
    int height = 1;
    
    Animal()
    {
        cout << "Animal 构造函数" << endl;
    }
    
    Animal(int age)
    {
        cout << "Animal 带参构造函数" << endl;
    }

    Animal(const Animal & ani)
    {
        cout << "Animal 拷贝造函数" << endl;
    }

    
    Animal(Animal && ani)
    {
        cout << "右值引用" << endl;
    }

    
    void eat()
    {
        cout << "eat" << endl;
    }
    
    void sleep()
    {
        cout << "sleep" << endl;
    }
    
    ~Animal()
    {
        cout << "Animal 析构" << endl;
    }
    
    Animal(string name, int age, int height) {
        this->nickName = name;
        this->age = age;
        this->height = height;
    }
        
    int getWeight()
    {
        return this->weight;
    }
    
//    void getWeight(int& target)
//    {
//        target = this->weight;
//    }
    
    void getWeight(int&& target)
    {
        target = this->weight;
    }
    
private:
    int weight = 10;
    
};

typedef unique_ptr<Animal> AnimalRef;
typedef shared_ptr<Animal> AnimalShareRef;


class TestPtr
{
    
public:
    Animal ani;
    AnimalRef ref;
    AnimalShareRef shareRef;
    string *strPtr;
    string str;
    
    Animal getAni() {
        return this->ani;
    }
    
    Animal& getConstAni() {
        return this->ani;
    }
    
    string getStr()
    {
        return this->str;
    }
    
    string* getStrPtr()
    {
        return this->strPtr;
    }

    AnimalShareRef getShareRef() {
        return this->shareRef;
    }
    
    AnimalRef& getAnimal()
    {
        return ref;
    }
    
//    void setAnimal(AnimalRef *a)
//    {
//        this->ref = move(a);
//    }
};


int main(int argc, const char * argv[]) {
    {
        Animal a1;
        Animal a2 = std::move(a1);
        
        Animal a3;
        Animal a4 = a3;
    }

    {
        Master *ms = new Master();
        ms->name = "主人";

        std::shared_ptr<Master> ms2 = make_shared<Master>();
        ms2->name = "主人2";

        AnimalShareRef a = make_shared<Animal>();
        a->master = ms;
        a->master2 = ms2;
        a->fullName = "狗a";
        Animal *aPoint = a.get();

        AnimalShareRef b = make_shared<Animal>(*aPoint);
        a->fullName = "狗a修改";
        printf("========");
    }
    
    {
        Master *ms = new Master();
        ms->name = "主人";
        
        Animal a;
        a.master = ms;
        a.fullName = "狗a";
        Animal b(a);
        printf("========");
    }

    
    
    
//
//    BaseAnimal ba;
//    ba.sMethod();

//    cout<< "weight 1: " << an.getWeight() <<endl;
//    
//    const char * ar;
//    char *b = "b";
//    ar = b;
    
//    const int a = 1;
//    int const b = 1;
//
//    int& b = a;
//    int weight = 0;
//
//
//    cout<< "weight 2: " << weight <<endl;

//    cout<< an.name << endl;
//    Animal(<#string name#>, int age, <#int height#>)
    
//    TestPtr ptr;
//    ptr.getConstAni();
    
//    Animal a;
//    Animal &b = a;
//    Animal &c = b ;
//

    
//    TestPtr ptr;
//
//    Animal *a = new Animal();
//
//    ptr.setAnimal(a);
    
//    AnimalRef aRef = ptr.getAnimal();
//    aRef->name = "我是aRef";
    
    
    
//    Animal a = Animal();
//    a.name = "a";
//    Animal& b = a;
//    cout << "name" << b.name << endl;
    
//    Animal* a1 = new Animal();
//    unique_ptr<Animal> aRef(a1);
//    unique_ptr<Animal> bRef;
//    bRef = move(aRef);
//
//    shared_ptr<Animal> sRef1(a1);
//    shared_ptr<Animal> sRef2 = sRef1;
//
//    cout<< "sRef1.useCount: " << sRef1.use_count() << endl;
//    cout<< "sRef2.useCount: " << sRef2.use_count() << endl;
//
//    Animal* b1 = new Animal();
//    AnimalRef b1Ref(b1);

//    cout << aRef->name << endl;
//    Animal c = a;
//    cout << c.name << endl;
    
    return 0;
}
