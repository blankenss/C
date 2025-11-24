#include <stdio.h>
#include <stdarg.h>

/* 
可变参数：指参数的个数以及类型是可以根据实际应用有所变化的；
C语言函数参数入栈的顺序是从右往左进行的。
应用：
    1.引用 <stdarg.h>有文件
1	va_list
    这是一个适用于 va_start()、va_arg() 和 va_end() 这三个宏存储信息的类型。用于存储可变参数信息的类型。

序号	宏 & 描述
1	void va_start(va_list ap, last_arg)
    这个宏初始化 ap 变量，它与 va_arg 和 va_end 宏是一起使用的。
    last_arg 是最后一个传递给函数的已知的固定参数，即省略号之前的参数。
2	type va_arg(va_list ap, type)
    这个宏检索函数参数列表中类型为 type 的下一个参数。
3	void va_end(va_list ap)
    这个宏允许使用了 va_start 宏的带有可变参数的函数返回。如果在从函数返回之前没有调用 va_end，则结果为未定义。
*/
//求变参数之和
double sum_fun(int num,...);

int main(int argc, char const *argv[])
{
    double res=sum_fun(2,4,5,1,9.9,0.1,0.2,0.3);//第一个数来表示执行后面多少个数
    printf("res=%lf\n",res);
    return 0;
}

double sum_fun(int num,...){
    //变量声明
    va_list list;
    //赋值
    va_start(list,num);

    double sum=0;

    for(int i=0;i<3 && i<num;i++){
        sum+=va_arg(list,int);
    }
    for(int i=3;i<num;i++){
        sum+=va_arg(list,double);
    }
    va_end(list);
    
    return sum;
}








