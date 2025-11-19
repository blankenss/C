#include <stdio.h>
int main(int argc, char const *argv[])
{
    /* 
        指针的加法：地址向上移动若干单位（每个单位的字节数有指针的类型决定）
        指针的减法：地址向下移动若干单位（每个单位的字节数有指针的类型决定）
    */
   //局部变量，栈  在C语言内存模型中是倒扣的，向下增长

   int a=9527;
   int b=8848;
   int c=666;
   long long d=9;

    int *p1=&a;
    int *p2=&b;
    int *p3=&c;
    long long *p4=&d;

    printf("p1=%p\n",p1);
    printf("p2=%p\n",p2);
    printf("p3=%p\n",p3);
    printf("p4=%p\n",p4);

    //逻辑错误的指针运算，得到 野指针

    printf("p1+1=%p,*(p1+1)=%d\n",p1+1,*(p1+1));//脏数据
    printf("p1+2=%p,*(p1+2)=%d\n",p1+2,*(p1+2));//脏数据

    printf("p3+0=%p,*(p3+0)=%d\n",p3+0,*(p1+0));
    printf("p3+1=%p,*(p3+0)=%d\n",p3+1,*(p1+1));
    printf("p3+2=%p,*(p3+0)=%d\n",p3+2,*(p1+2));

    printf("p1-1=%p,*(p1-1)=%d\n",p1-1,*(p1-1));
    printf("p1-2=%p,*(p1-2)=%d\n",p1-2,*(p1-2));
    printf("p1-5=%p,*(p1-5)=%d\n",p1-5,*(p1-5));
    printf("p1-4=%p,*(p1-4)=%d\n",p1-4,*(p1-4));
    return 0;
}
