#include <stdio.h>
//3-100的所有素数
int main(int argc, char const *argv[])
{
    int i;
    int count;
    for(i=3;i<=100;i++)
    {
        count=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0) count++;
        }
        if(count==2) printf("%d是素数\n",i);
    }
    return 0;
}
