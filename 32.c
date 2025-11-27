#include <stdio.h>

/* 
    C语言的位域bit field 是一种特殊的结构成员，允许我们对成员进行定义，指定其占用的位数
    位域：指定其占用的位数，节约内存空间
    只能指定  整型   int/unsigned int
*/
struct bf{
    int a:4;//只占4个bit
    unsigned int b:4;
    unsigned int :4;//空域，还是占有空间
    signed int c:20;//有符号
};

int main(int argc, char const *argv[])
{
    struct bf b1;
    b1.a=9;
    printf("b1.a=%d\n",b1.a);
    b1.b=10;
    printf("b1.b=%d\n",b1.b);
    b1.c=-6;
    printf("b1.c=%d\n",b1.c);

    printf("%llu\n",sizeof(struct bf));
    return 0;
}
