#include <stdio.h>
//求闰年
int main(int argc, char const *argv[])
{
    int n;
    while(1){
        printf("请输入一个整数：");
        scanf("%d",&n);
        if((n%4==0 && n%100!=0) || n%400==0 ) printf("%d是闰年\n",n);
        else  printf("%d不是闰年\n",n);
    }
    return 0;
}
