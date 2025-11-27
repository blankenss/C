#ifndef COMMON_H
#define COMMON_H

//顺序表 是一对一的逻辑关系，是一个固定大小的空间
//0.设置数组的最大元素(固定大小)
#define MAX_SIZE 100

//1.定义通用的顺序表数据结构体
typedef struct
{
    //存放具体数据元素，存放数据元素的指针，void* 任意数据类型的指针
    void* data[MAX_SIZE];
    //实际存放元素个数
    int size;
} Array;

//2.创建顺序表
Array* create_array(); 

//3.判断顺序表是否为空，已使用长度为0就是空，反之不为空
int is_empty(Array* array);

//4.判断顺序表是否以满，已使用长度达到最大长度就是满，反之未满
int is_full(Array* array);

//5.添加数据元素，存入的是数据元素的指针，默认在顺序表的末尾添加新元素
void add_array(Array* array,void *element);

//6.获取顺序表内的数据元素，通过index获取对应的数据元素指针  
void* get_array_element(Array* array,int index);

//7.插入数据元素，从指定index插入数据元素
int insert_array(Array* array,int index,void *element);
//8.删除数据元素
int delete_array(Array* array,int index);

//9.修改顺序表数据
int modify_array(Array* array,int index,void *element);

//last. 释放顺序表
void destroy_array(Array* array);  
#endif


#include <stdio.h>
#include <stdlib.h>
#include <../inc/common_array.h>

Array* create_array()
{
    printf("%llu\n",sizeof(Array));
    //开辟空间
    Array* new_array=(Array*)calloc(1,sizeof(Array));//1个sizeof(Array)大小的空间
    if(new_array==NULL)//判断空间是否开辟成功
    {
        printf("内存分配失败\n");
        return NULL;
    }
    //开辟成功
    //只有空间，里面没有元素
    new_array->size=0;//size 元素的个数
    return new_array;//返回该指针
}

//3.判断顺序表是否为空，已使用长度为0就是空，反之不为空
int is_empty(Array* array)
{
    return array->size==0;//就是一个判断语句，返回0或1
}

//4.判断顺序表是否以满，已使用长度达到最大长度就是满，反之未满
int is_full(Array* array)
{
    return array->size>=MAX_SIZE;//就是一个判断语句，返回0或1
}

//5.添加数据元素，存入的是数据元素的指针，默认在顺序表的末尾添加新元素
void add_array(Array* array,void *element)
{
    //(1)判断顺序表是否满，满了就不能添加数据
    if(is_full(array))
    {
        printf("顺序表已满\n");
        return;
    }
    //未满再执行操作
    array->data[array->size]=element;//将指针传递给数组的第一个空间
    array->size++;//添加一个元素个数加1
}
//6.获取顺序表内的数据元素，通过index获取对应的数据元素指针  
void* get_array_element(Array* array,int index)
{   //(1)index 要有效
    if(index<0 || index>=array->size)
    {
        printf("索引无效，无数据\n");
        return NULL;
    }
    return array->data[index];
}

//7.插入数据元素，从指定index插入数据元素
int insert_array(Array* array,int index,void *element)
{
    //(1)判断顺序表是否已满
     if(is_full(array))
    {
        printf("顺序表已满\n");
        return 0;
    }
    //（2）index要有效
    if(index<0 || index>=array->size)
    {
        printf("索引无效，无数据\n");
        return 0;
    }
    //（3）从插入位置index开始，后面所有元素向后移动一位
    //最后一位先向后移，避免前面数据向后移动覆盖后面的数据
    for(int i=array->size;i>index;i--){
        array->data[i]=array->data[i-1];   
    }
    array->data[index]=element;
    array->size++;
    return 1;
}

//8.删除顺序表
int delete_array(Array* array,int index)
{
    //空表没有数据元素，无法删除
    if(is_empty)
    {
        printf("空表，无法删除数据元素\n");
        return 0;
    }
    //（1）index要有效
    if(index<0 || index>=array->size)
    {
        printf("索引无效，无数据\n");
        return 0;
    }
    for(int i=index;i<array->size-1;i++)
    {
        array->data[i]=array->data[i+1];
    }
    array->size--;
}

//9.修改顺序表数据
int modify_array(Array* array,int index,void *element)
{
    // 9.1空表没有数据元素，无法修改
    if (is_empty(array))
    {
        printf("空表，无法修改数据元素\n");
        return 0; // 修改失败
    }

    //（1）index要有效
    if(index<0 || index>=array->size)
    {
        printf("索引无效，无数据\n");
        return 0;
    }

    array->data[index]=element;
    return 1;
}


//释放顺序表空间
void destroy_array(Array* array){
    //释放非NULL的指针
    if(array){
        free(array);
    }
}



