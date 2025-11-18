#include <stdio.h>
//1-1/2+1/3-1/4…..1/100 的和
int main(int argc, char const *argv[])
{
    int n;//1-100
    double sum=0.0;

    double add=0;
    double sub=0;
    for(n=1;n<=100;n++)
    {
        if(n%2!=0)//奇数
        {
            add=add+(1.0/n);
        }else if(n%2==0)
        {
            sub=sub+(1.0/n);
        }
        
    }
    sum=add-sub;
    printf("%lf",sum);


    return 0;
}
