#include <stdio.h>
//根据某一个条件决定某一块代码是否需要编译。一般场景是不同的操作系统，编译不同
//1.通过无值来判断，只能判断是否定义
#define H

#define A1 0
#define A2 'Y'
#define A3 999
#define A4 "true"

int main(int argc, char const *argv[])
{
    //无值宏 条件编译
    //定义该宏  编译
    #ifdef H
        printf("H已经定义\n");
    #endif

    //未定义该宏 编译
    #ifndef M
        printf("M 不存在\n");
    #endif

    #if A1
        printf("A1的值为ture   执行,A1=%d\n",A1);
    #elif A2
        printf("A2的值为ture   执行,A2=%d\n",A1);
    #elif A3
        printf("A3的值为ture   执行,A2=%d\n",A1);
    #else
        printf("以上条件均不满足\n");
    #endif



    return 0;
}
