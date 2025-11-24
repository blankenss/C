#include <stdio.h>
/* 
    回调函数的定义和基本概念：
        1.回调函数是一种特殊的函数，他将函数作为参数传递给另一个函数，
    并在被调用函数执行完毕后被调用，
        2.回调函数通常用于事件处理、异步编程和处理各种操作系统和框架API；

    回调：指被传入到另一个函数的函数；
    异步编程：指代码执行时不会阻塞程序运行的方式；
    事件驱动：指程序执行是由外部事件触发而不是顺序执行的方式。
*/

//声明回调函数
int ccb_deduction(double money); 
int abc_deduction(double money);

//函数调用方
int wechat(double money,int (*fp)(double));

int main(int argc, char const *argv[])
{
    //建行扣款
    int res=wechat(9.9,ccb_deduction);
    printf("res=%d\n",res);

    //农行扣款
    res=wechat(9.9,abc_deduction);
    printf("res=%d\n",res);
    return 0;
}


//声明回调函数
int ccb_deduction(double money){
    double ye=99999999.000;
    if (ye<money)
    {   
        printf("余额不足!");
        return 0;//余额不足;
    }
    printf("扣款前:ccb 余额:%lf$\n",ye);
    ye-=money;
    printf("扣款后:ccb 余额:%lf$\n",ye);
    return 1;//成功
}


int abc_deduction(double money){
    double ye=199999999.000;
    if (ye<money)
    {   
        printf("余额不足!");
        return 0;//余额不足;
    }
    printf("扣款前:abc 余额:%lf$\n",ye);
    ye-=money;
    printf("扣款后:abc 余额:%lf$\n",ye);
    return 1;//成功
}

int wechat(double money,int (*fp)(double)){
    printf("微信调用银行的扣款!\n");
    return fp(money);
}
