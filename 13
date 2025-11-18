#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100 
//寻找最小值
int main(int argc, char const *argv[])
{
    int arr1[SIZE]={0};
    srand((unsigned)time(NULL));
    for(int i=0;i<=SIZE;i++)//生成100个随机数
    {
        arr1[i]=rand()%100;
    }
     printf("随机数组（0-99）：\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%3d ", arr1[i]);
        if ((i + 1) % 10 == 0) printf("\n"); // 每10个换行
    }
    //排序
    int min;
    for(int j=0;j<100;j++)
    {
        min=arr1[0];
        if(min>arr1[j]){
            min=arr1[j];
        }
    }printf("%d ",min);
    return 0;
}
