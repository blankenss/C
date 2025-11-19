#include <stdio.h>

int main(int argc, char const *argv[])
{
    int sum=0;
    for(int i=10;i<30;i++)
    {
        
        if(i%2!=0)
        {
            sum+=i;
        }
    }printf("%d\n",sum);
    return 0;
}
