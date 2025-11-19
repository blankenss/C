#include <stdio.h>
#include <string.h>

//回文字符串

void reverse_string(char *str);
int main(int argc, char const *argv[])
{
    char arr[20];
    printf("请输入一个字符串：");
    

    scanf("%s",&arr);
    reverse_string(arr);
    return 0;
}
//

void reverse_string(char *str)
{
    int len=strlen(str);//从首地址开始读取到\0之前（不算\0）结束
    char arr[20];
    strcpy(arr,str);

    for(int i=0;i<len/2;i++)
    {
        char tmp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=tmp;
    }
    if(strcmp(arr,str)==0)
    {
        printf("该字符串是回文字符串");
    }else printf("该字符串不是回文字符串");
}
