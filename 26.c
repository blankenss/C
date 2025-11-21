#include <stdio.h>

//数独
/* 数独是一种逻辑游戏，玩家需要在9x9的格子中填入数字1到9，
确保每一行、每一列以及每一个3x3的小宫格内数字不重复。
游戏开始时，部分格子已填入数字，玩家需根据这些提示完成整个数独。

题目：使用C语言实现数独求解

题目要求：
1. 编写一个C语言程序，能够解决给定的数独题目。
2. 数独题目是一个9x9的二维数组，其中0表示空白格，需要填充数字1到9。
3. 程序需要检查数独的有效性，并输出一个完整的解。
4. 如果数独无解，程序应输出“No solution exists”。

 示例输入：
以下是一个数独题目的示例输入（0表示空白格）： */

int main(int argc, char const *argv[])
{
    int value;
    int grid[9][9]={0};
//input
    printf("请输入一个0-9的整数(用空格隔开)：");
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&value);
            grid[i][j]=value;
        }
    }//此时输入已完成
//定义1个变量来确定三个比较是否都完成
int count=0;
//判断行
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            for(int z=j+1;z<9;z++)
            {   
                if(grid[i][j]==grid[i][z]) goto end1;
                else ;
            } 
        }      
    }count=1;
    //判断列
for(int j=0;j<9;j++){
        for(int i=0;i<9;i++){
            for(int z=i+1;z<9;z++)
            {   if(grid[i][j]==0) continue;
                else if(grid[i][j]==grid[z][j]) { 
                    
                    goto end2;
                }else ;
            } 
        }
    }count=2;
//判断3*3小方格

//第一个3*3
    int tmp[9];//创建一个数值来存放数据 
    //判断第一个3*3
    for(int i=0;i<3;i++)//第一行的3个3*3
    {
         int count1=0;
        for(int t=0;t<9;t++){
            count1=t/3;
        tmp[t]=grid[count1][t%3+3*i];//t%3->t%3+3*i
        //printf("tmp[%d]=%d ",t,tmp[t]);
        }//printf("\n");//赋值完成
        //判断tmp[]数组的值是否相等的值是否相等
    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(tmp[i]==tmp[j]) {
                printf("第一个\n");
                goto end3;
            }
            
            else ;
        }   
    }//比较完成
    }//循环三个
        
//第2行的3个3*3 
    //判断第一个3*3
    for(int i=0;i<3;i++)//第一行的3个3*3
    {
         int count1=0;
        for(int t=0;t<9;t++){
            count1=t/3+3;
        tmp[t]=grid[count1][t%3+3*i];//t%3->t%3+3*i
        }//赋值完成
        //判断tmp[]数组的值是否相等的值是否相等
    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(tmp[i]==tmp[j]) {
                printf("第二个\n");
                goto end3;}
            else ;
        }   
    }//比较完成
    }//循环三个

    //第3行的3个3*3 
    //判断第一个3*3
    for(int i=0;i<3;i++)//第一行的3个3*3
    {
         int count1=0;
        for(int t=0;t<9;t++){
            count1=t/3+6;
        tmp[t]=grid[count1][t%3+3*i];//t%3->t%3+3*i
        }//赋值完成
        //判断tmp[]数组的值是否相等的值是否相等
    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(tmp[i]==tmp[j]) {
                printf("第三个\n");
                goto end3;}
            else ;
        }   
    }//比较完成
    }//循环三个
count=3;




end1:
end2:
end3:
//printf("count=%d\n",count);//打印计数确定是否成功
if(count==3){
    printf("true\n");
}else printf("false\n");

//output
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",grid[i][j]);
        }printf("\n");
    }
    return 0;
}
