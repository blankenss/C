#include <stdio.h>
/* 
联合体(共用体)：
    从表面上看和结构体很类似，但是本质完全不同，结构体每一个成员属性都有自己独立的内存空间，但是联合体的每一个成员属性共用同一个内存空间(最大成员的空间)
语法”
    union 标签名{}
*/

union teacher{
    int s;
    double d;
    char g[20];
};


int main(int argc, char const *argv[])
{
    //联合体的尺寸（共用一个内存）
    //最大数据类型的整数倍（如double），能够存放最大元素的最小空间
    printf("%llu\n",sizeof(union teacher));//24
    union teacher t1;
    t1.s=9527;
    printf("%d\n",t1.s);//9527
    t1.d=9.9;
    printf("%lf\n",t1.d);//9.9
    printf("%d\n",t1.s);
    //同一时间只有一个成员属性有效，共用同一块内存空间。
    return 0;
}
