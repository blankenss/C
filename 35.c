#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
本章将讲解 C 中的动态内存管理。C 语言为内存的分配和管理提供了几个函数。这些函数可以在 <stdlib.h> 头文件中找到。
在 C 语言中，内存是通过指针变量来管理的。指针是一个变量，它存储了一个内存地址，
这个内存地址可以指向任何数据类型的变量，包括整数、浮点数、字符和数组等。
C 语言提供了一些函数和运算符，使得程序员可以对内存进行操作，包括分配、释放、移动和复制等。

序号	函数和描述
1	    void *calloc(int num, int size);
        在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。所以它的结果是分配了 num*size 个字节长度的内存空间，并且每个字节的值都是 0。
2	    void free(void *address);
        该函数释放 address 所指向的内存块,释放的是动态分配的内存空间。
3	    void *malloc(int num);
        在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。
4	    void *realloc(void *address, int newsize);
        该函数重新分配内存，把内存扩展到 newsize。

注意：void * 类型表示未确定类型的指针。C、C++ 规定 void * 类型可以通过类型转换强制转换为任何其它类型的指针。
*/
int main(int argc, char const *argv[])
{
    //程序员开辟空间，本身是没有类型，要使用需要强制类型转换
    //定义一个指针，指针指向开辟的空间
    char* cs=(char*)malloc(4);


    char *cs1=(char*)calloc(4,1);//自动初始化为0
    
    printf("cs=%p\n",cs);//有脏数据
    printf("cs1=%p\n",cs1);//没有脏数据

    strcpy(cs1,"asd");//赋值--将字符串放入指针指向的空间
    puts(cs1);
    //重新对空间进行分配
    cs1=(char*)realloc(cs1,20);
    strcpy(cs1,"asdfghjkl");
    puts(cs1);

    //释放空间，程序员开辟的空间必须手动释放，否则会内存泄漏
    free(cs);
    free(cs1);
    //将指针置为空指针，
    cs=NULL;
    cs1=NULL;
    printf("cs=%p\n",cs);
    printf("cs1=%p\n",cs1);
    
    return 0;
}
