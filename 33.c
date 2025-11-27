#include <stdio.h>
/* 
    1.概念
        宏是一个特殊的字符串，用来直接替换。在预处理阶段就会被替换。
    2.作用
        1.使程序可读性有所提高，用有意义的单词来代表无意义的数。
        2.方便对代码进行迭代更新，如果代码中有多处使用该值，则只需要修改定义即可。
        3.提高程序的代码执行效率，可以使用宏来实现一个比较简单的操作。
*/
//无参宏
#define STATE 9527

//无值宏，一般用来做条件编译的
#define NO_VAL

//宏表达式，尽量要写在一行，这一行称之为逻辑行，如果逻辑代码太长一行写不下用转义字符\去连接
//由于宏是直接替换的，所以容易出现逻辑错误，使用（）提升优先级
#define MAX(a,b)  ((a)>(b)\
?\
(a):(b))

int main(int argc, char const *argv[])
{
    //使用无参宏
    printf("STATE=%d\n",STATE);
    printf("STATE=%d\n",STATE);
    printf("STATE=%d\n",STATE);
    printf("STATE=%d\n",STATE);
    int x=5,y=10;
    int res=MAX(x,y==10?998:1024);
    printf("res=%d\n",res);
    
    return 0;
}
