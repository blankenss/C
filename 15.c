#include <stdio.h>
//编程求表达式的值
	//s=1+(1+2)+(1+2+3)+...+(1+2+3+...+n)

int main(int argc, char const *argv[])
{
    int sum=0;

    int n;
    printf("请输入一个整数：\n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        int sum_tmp=0;
        for(int j=1;j<=i;j++)
        {
            sum_tmp+=j;
        }
        sum+=sum_tmp;
    }
    printf("sum=%d\n",sum);
    return 0;
}
