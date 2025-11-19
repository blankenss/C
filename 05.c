#include <stdio.h>

 void Factorial(int n)
 {
    
        int tmp=n;
        int sum=1;
        if(!n) printf("%d的阶乘为1\n",n);
        else {
                for(n;n>0;n--)
                {
                    sum*=n;
                }
            }
            printf("%d阶乘为%d\n",tmp,sum);    
 }
int main(int argc, char const *argv[])
{
    int n;
    printf("请输入一个整数：");
    scanf("%d",&n);
    Factorial(n);
    return 0;
}
