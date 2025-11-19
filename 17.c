#include <stdio.h>
#include <string.h>
#define LENGTH(array) (sizeof(array)/sizeof(array[0]))
int main(int argc, char const *argv[])
{
    char ch[]={'a','b','c','d','e'};

    int sz=sizeof(ch)/sizeof(ch[0]);
    for(int i=0;i<sz;i++)
    {
        printf("%c ",ch[i]);
    }printf("\n");
    


//2.  string 字符串
/* 
(1)strong 字符串 本质就是一个插入数组
(2)string 最后一个字符为\0
(3) \0 标记字符串的结束，空字符也被称为结束符，\0转义字符，
      告诉编译器这不是字符0，而是空字符 
字符串占位符  %s

直接打印字符串  puts(ch);     如果字符串没有结束符 \0 就会一直打印下去
      
*/

char ch2[]={'f','g','h','i','j'};

char ch3[]={'k','l','m','n','\0'};

    printf("%s\n",ch2);//（错误）用字符串打印没有结束符，就会一直打印
    puts(ch2);//（错误）用字符串打印没有结束符，就会一直打印
    puts(ch3);


/* 
3.计算字符串长度
lenght=sizeof(arr)/sizeof(arr[0]);
lenght 数组的长度（包括了\0）
strlen 字符串的长度(不包括\0)

*/
char ch4[]="asdfghjkl";//
unsigned long long lenght=sizeof(ch4)/sizeof(ch4[0]);
printf("数组ch4的长度为:%lld\n ",lenght);//10
lenght=strlen(ch4);
printf("字符串长度为：%lld\n ",lenght);//9

/* 
    4. char *strcat(char *dest,const char *src)
        把src 所指向的字符串追加到 dest 所指向的字符串的结尾。
    5. char *strncat(char * dest,const char *src,size_t n)
        把 src 所指向的字符串追加到 dest 所指向的字符串结尾，直到 n 字符长度为止。
*/

    char s_arr1[10]="abc";
    char s_arr2[10]="defghijk";
    //追加不能超过原数组长度
    strcat(s_arr1,s_arr2);//超过本身长度了


    //LENGTH(s_arr1)-1-strlen(s_arr1)是s_arr1剩余空间的大小
    //追加的字符串不能大于原本空间
    strncat(s_arr1,s_arr2,sizeof(s_arr1)-1-strlen(s_arr1));
    puts(s_arr1);
    puts(s_arr2);

/* 
    6.   char *strcpy(char *dest,const char *src)
        把 src 所指向的字符串复制到 dest.
    7. char *strnapy(char * dest,const char *src)
        把src 所指向的字符串复制到 dest ，最多复制n个字符
*/

    strcpy(s_arr1,s_arr2);
    puts(s_arr1);

    strncpy(s_arr1,s_arr2,LENGTH(s_arr1)-1);
    puts(s_arr1); 
    /* 
    8.  int strcmp(const char *str1, const char *str2)
        把 str1 所指向的字符串和 str2 所指向的字符串进行比较。
    9. 	int strncmp(const char *str1, const char *str2, size_t n)
        把 str1 和 str2 进行比较，最多比较前 n 个字节。
    */
    char str1[]="abceef";
    char str2[]="abcdef";
    int res=strcmp(str1,str2);
    printf("res=%d\n",res);//  0相等，正数代表str1大于str2，负数str1小于str2

    res=strncmp(str1,str2,3);
    printf("res=%d\n",res);//  0相等，正数代表str1大于str2，负数str1小于str2

    return 0;
}
