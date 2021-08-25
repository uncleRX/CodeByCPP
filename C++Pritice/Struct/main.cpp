//
//  main.cpp
//  Struct
//
//  Created by 任迅 on 2021/8/3.
//

#include <iostream>
using namespace std;

struct Books
{
    char title[50];
    char aurhor[50];
    char subject[100];
    int book_id;
};

typedef struct Name
{
    char *value;
}Names;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Books book1;
    Books book2;
    
    strcpy(book1.title, "标题");
    Names name;
    strcpy(name.value, "c");

    cout << "name.Value: " << name.value << endl;
    return 0;
}
