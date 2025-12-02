//头文件

#ifndef HASH_H
#define HASH_H

#define TABLE_SIZE 10

//1.定义hash table 哈希表中的结点
typedef struct Node
{
    //键值对结构
    //关键字
    int key;
    int value;
    struct Node *next;
}Node;

//2.创建hash table 哈希表
Node* hash_table[TABLE_SIZE];//存放地址的数组

//3.键值对结构
//hash 函数，计算关键字，得到存储位置
int hash_function(int key);

//4.添加数据到hash table 哈希表
void insert_hash_table(int key,int value);

//5.查找  根据key查找，key不能重复
int search(int key);


//.c文件
#include <stdio.h>
#include <stdlib.h>
#include "../inc/common_hash.h"

//3.键值对结构
//hash 函数，计算关键字，得到存储位置
int hash_function(int key){
    return key%TABLE_SIZE;
}

//4.添加数据到hash table 哈希表
void insert_hash_table(int key,int value)
{
    int index=hash_function(key);

    Node* new_node=(Node*)calloc(1,sizeof(Node));

    new_node->key=key;
    new_node->value=value;
    new_node->next=NULL;
    //判断哈希表对应位置是否有结点（该位置是否存放有数据）
    if(hash_table[index]==NULL){
        //哈希表为空，可以存放数据
        hash_table[index]=new_node;
    }else{
        //不为空，哈希冲突，用链表解决
        Node *current=hash_table[index];
        while(current->next!=NULL)
        {   //将链表下一个的地址赋值给current
            //直到下一个地址为空,就找到了最后一个数据的地址
            current=current->next;
        }
        //将新结点插入尾部
        current->next=new_node;
    }
}

//5.查找  根据key查找，key不能重复
int search(int key){
    int index=hash_function(key);

    Node* current=hash_table[index];
    while(current!=NULL)
    {
        if(current->key==key){
            return current->value;
        }
        current=current->next;
    }
    //未找到
    return -1;
}



#endif
