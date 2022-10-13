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


struct fb_info {
    atomic_int count;
    int node;  /*一个FrameBuffer设备的次设备号*/
    int flags;
    struct mutex lock;        /* Lock for open/release/ioctl funcs */
    struct mutex mm_lock;
    
    struct Books m_book;
    Books m_book1;
};


typedef struct Name
{
    char *value;
}Names;

int main(int argc, const char * argv[]) {
    fb_info info;
    info.m_book.book_id = 1;
    info.m_book1.book_id = 1;


    Books book1;
    Books book2;
    
    strcpy(book1.title, "标题");
    Names name;
    strcpy(name.value, "c");

    cout << "name.Value: " << name.value << endl;
    return 0;
}
