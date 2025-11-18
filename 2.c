#include <stdio.h>

int main(int argc, char const *argv[])
{
    int sum=0;
    int count=0;
    for(int i=0;i<=20;i++)
    {
        if(i%3==0)
        {
            sum+=i;
            count++;
        }
    }
    printf("¸öÊý£º%d,ºÍ£º%d",count,sum);
    return 0;
}
