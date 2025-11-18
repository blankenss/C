#include <stdio.h>
//输入一个正整数，计算这个整数是几位数？

int main(int argc, char const *argv[])
{
    int n;
    int count=1;
    printf("请输入一个正整数：\n");
    scanf("%d",&n);
    while(count)
    {
        if(n/10!=0)
        {
            n=n/10;
            count++;
        }
        if(n/10==0)
        {
            printf("%d ",count);
            count=1;
            break;
        }
    }
    return 0;
}
