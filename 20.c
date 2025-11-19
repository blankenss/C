#include <stdio.h>

//计算大写字母，小写字母，数字和其它字符的个数
int main(int argc, char const *argv[])
{
    char ch[10];
    printf("请输入一个10字符以内的字符串：\n");
    scanf("%s",ch);
    int sz=sizeof(ch)/sizeof(ch[0]);
    printf("sz=%d\n",sz);
        int min_write=0;
        int max_write=0;
        int number=0;
        int other=0;
    for(int i=0;i<sz;i++)
    {
        char ch2=ch[i];
        if((ch2>='0')&&(ch2<='9'))
        {
            number++;
        }
        else if((ch2>='A')&&(ch2<='Z'))
        {
            max_write++;
        }
        else if((ch2>='a')&&(ch2<='z'))
        {
            min_write++;
        }else
        {
            other++;
        }

    }
    printf("数字有：%d,大写字母有：%d,小写字母有：%d,其他字符有：%d",number,max_write,min_write,other);

    return 0;
}
