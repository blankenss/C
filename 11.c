#include <stdio.h>
//输出a-z,和输出Z-A
int main(int argc, char const *argv[])
{
    //小写a-z
    char ch1='a';
    int i=('z'-'a')+1;
    while(i--)
    {
        printf("%c ",ch1);
        ch1=ch1+1;
    }printf("\n");

    //大写Z-A
    char ch2='Z';
    int y=('Z'-'A')+1;

    while(y--)
    {
        printf("%c ",ch2);
        ch2=ch2-1;
    }printf("\n");


    //3.优
    char ch3='a';
    int x='z'-'a';
    for(int z=0;z<=x;z++)
    printf("%c ",ch3+z);


    return 0;
}
