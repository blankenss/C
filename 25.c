#include <stdio.h>

/* 
const修饰指针有两种效果：
    1.常量指针：修饰指针本身，指针本身的值不能被修改，但是指针指向目标的值可以被修改；
        char *const p;
    2.常目标指针：指针本身的值可以被修改，但是不能通过该指针修改指向目标的值；
        const char *p;
        char const *p;
    常量指针用的很少，常目标指针用的很多。
*/
int main(int argc, char const *argv[])
{
     /* //常量
    const int ci=9527;
    printf("ci=%d\n",ci);
    //ci=8848; 常量不能再次赋值
    int *ip=&ci;
    *ip=8848;
    printf("ci=%d\n",ci); */

    char arr[]="Good";
    char msg[]="Heron";
    puts(arr);
    //常量指针
    //相当于cp1=arr绑定了，不能改变;但是可以通过指针改变arr[]中的数据
    char *const cp1=arr; //只能在初始化的赋值
    
    //通过指针修改指向目标的值
    *(cp1+1)='T';
    puts(arr);


    //常目标指针
    const char *cp2=arr;
    cp2=msg;
    puts(cp2);
    //无法通过该指针修改指向目标的值
    //*(cp2+1)='E';

  /*   char *cp3=msg;
    *(cp3+1)='K';
    puts(msg); */

    //常量  常目标 指针,不能指针本身的值也不能通过该指针修改指向目标的值
    //const char *const cp4=arr;
    //cp4=msg;
    //*(cp4+1)='U';

    
    return 0;
}
