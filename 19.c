#include <stdio.h>

//宏表达式  计算数组的长度
#define LENGTH(array) (sizeof(array)/sizeof(array[0]))

/* 
数组名的本意是表示整个数组，也就是表示多份数据的集合，但是在使用过程中经常会转换为指向数组index为0的元素的指针。
初学时可以把数组名当作指向index为0的元素的指针使用即可。

数组的指针：指向整块数组的空间
*/
int main(int argc, char const *argv[])
{
    int arr[]={99,88,77,66,75,66,75};
    //数组指针
    int (*ap)[]=&arr;
    //数组首元素的指针
    int *fp=&arr[0];

    printf("ap=%p,fp=%p\n",ap,fp);//0000005a0e7ffcc0
    printf("arr=%p\n",arr);//0000005a0e7ffcc0

    int i1=*fp;
    printf("i1=%d\n",i1);


    //1.数组依次打印
    for(int i=0;i<LENGTH(arr);i++)
    {
        printf("%d ",arr[i]);
    }printf("\n");
    //2.数组指针通过地址打印
    for(int i=0;i<LENGTH(arr);i++)
    {
        printf("%d ",(*ap)[i]);
    }printf("\n");
    //3.通过指针通过首地址打印
    for(int i=0;i<LENGTH(arr);i++)
    {
        printf("%d ",*(fp+i));
    }printf("\n");
    //4.与3类似，arr就是数组的首地址
    for(int i=0;i<LENGTH(arr);i++)
    {
        printf("%d ",*(arr+i));
    }printf("\n");


    return 0;
}
