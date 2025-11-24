#include <stdio.h>

/* 
枚举是C语言的一种基本数据类型，用于定义一组具有离散值的常量，它可以让数据更简洁，更易读；
枚举类型通常用于为程序中的一组相关的常量取名字，以便于程序的可读性和维护性；
语法：
    enum 枚举标签{常量1,常量2...};
这个常量只能是int类型。
*/

//枚举方案
//如果枚举的第一个值没有赋值，默认值为0
//如果后续没有赋值，在前一个基础上+1

enum week{
    MOD=1,TUE,WED,THU,FRI,SAT,SUN
};

int main(int argc, char const *argv[])
{
    enum week w1=SAT;
    printf("w1=%d\n",w1);
    enum week w2=SAT;
    printf("w2=%d\n",w2);

    //遍历,如果枚举常量是连续可以采用下面的遍历方式，否则不可以
    // for ( w1 = MON; w1 <=SUN; w1++)
    // {
    //     printf("w1=%d\n",w1);
    // }
    return 0;
}
