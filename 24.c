#include <stdio.h>
/* 
以二维数组 为例，学习多维
一维数组  int[size]
二维数组  int[n][m]  n个一维数组(长度为m)
*/

int main(int argc, char const *argv[])
{
    //二维数组
    int arr[3][2]={{1,2},{3,4},{4,5}};
    //打印第二行第一个值
    printf("%d\n",arr[1][0]);
    arr[1][0]=9528;

    //遍历  双重遍历
    //外层 第几个一维数组
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++){
            printf("arr[%d][%d]=%d ",i,j,arr[i][j]);
        }
        printf("\n");
    }
//二维数组本质就是一个一维数组
int arr2[3][2]={1,2,3,4,5,6};
for(int i=0;i<3;i++)
{
    //内层该一维数组的第几个元素
        for (int j = 0; j < 2; j++)
        {
            printf("arr2[%d][%d]=%d ",i,j,arr2[i][j]);
        }
        printf("\n");
}

int arr3[3][2]={9,8,6,5};
    for (int i = 0; i < 3; i++)
    {
        //内层该一维数组的第几个元素
        for (int j = 0; j < 2; j++)
        {
            printf("arr3[%d][%d]=%d ",i,j,arr3[i][j]);
        }
        printf("\n");
    }

   int arr4[3][2]={{1},{2},{3}};
    for (int i = 0; i < 3; i++)
    {
        //内层该一维数组的第几个元素
        for (int j = 0; j < 2; j++)
        {
            printf("arr4[%d][%d]=%d ",i,j,arr4[i][j]);
        }
        printf("\n");
    }//type name[行][列] 可以省略(行)第一个参数，但是(列)第二个不能省略
    int arr5[][3]={9,89,89,8,5,68,9,6,56,5};
    for (int i = 0; i < 4; i++)
    {
        //内层该一维数组的第几个元素
        for (int j = 0; j < 3; j++)
        {
            printf("arr5[%d][%d]=%d ",i,j,arr5[i][j]);
        }
        printf("\n");
    }
    return 0;
}
