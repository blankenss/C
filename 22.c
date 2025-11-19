#include <stdio.h>
#include <string.h>

void reverse_string(char *str);
int main(int argc, char const *argv[])
{
    char arr[]={};
    printf("请输入一个字符串：");
    scanf("%s",&arr);
    reverse_string(arr);

    return 0;
}


void reverse_string(char *str)
{
    int len=strlen(str);
    
    for(int i=0;i<len/2;i++)
    {
        char tmp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=tmp;
    }
    printf("%s ",str);
}
