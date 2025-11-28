//头文件common.h
#ifndef LINKED_LIST
#define LINKED_LIST

//1.定义双向链表，结点结构体
//定义为指针类型可以存放不同的数据类型（存放的是它们的地址）
typedef struct Node{
    //存放的数据
    void *data;
    //存放上一个结点的指针
    struct Node *prev;
    //存放下一个结点的指针
    struct Node *next;
} Node;

//2.定义双向链表存放头结点和尾结点
//可以定义多个链表,单链表只有一个头和尾结点
typedef struct {
    //头节点
    Node* head;
    //尾结点
    Node *tail;
    //存放的数据个数
    int size;
} linklist;

// 2.定义双向链表
typedef struct
{
    // 头节点
    Node *head;
    // 尾结点
    Node *tail;
    // 存入的结点数量
    int size;
} LinkedList;

// 3.创建一个新结点的函数
Node *create_node(void *data);

// 4.初始化链表
void init_linked_list(linklist* list);

// 5.在链表头部插入 结点
void prepend(linklist *list,void *data);

// 6.在链表尾部插入 结点
void append(linklist *list, void *data);

// 7.在链表中间插入 结点
void insert_after(linklist *list, void *data, Node *prev_node);

// 8.1 int 类型 比较函数
int compare_data(void *a,void *b);

// 8.2 在链表中通过data找到某个node
Node* search_node(linklist* list,void *data,int (*compare)(void*,void*));

// 9.示例：int类型 遍历链表(里面的数据类型要一致)
void show_linked_list(linklist *list);

// 10.修改链表中结点的数据
void update_node(Node *node, void *data);

// 11.删除数据就是删除链表中的结点
void delete_node(linklist *list,Node* node);

// last.清空链表
void clear_linked_list(linklist *list);
#endif


//likendlist.c

#include <stdio.h>
#include<stdlib.h>
#include "../inc/common.h"

//3.创建一个新的结点的函数
Node* create_node(void *data){
    Node* new_node=(Node*)calloc(1,sizeof(Node));
    //判断空间是否创建成功
    if(new_node==NULL)
    {
        printf("内存分配失败\n");
        //结束
        exit(EXIT_FAILURE);
    }
    //内存分配成功,
    //赋值，初始化结点
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=NULL;
    //返回开辟的内存
    return new_node;
}
//4.初始化头尾结点链表，
void init_linked_list(linklist* list)
{
    //初始化,避免脏数据
    list->head=NULL;
    list->tail=NULL;
    list->size=0;
}

//5.在链表头部插入结点
void prepend(linklist *list,void *data)
{
    //(1)创建一个空间来存放结点和数据
    Node* new_node=create_node(data);
    //(2)判断是否是链表的第一个元素
    if(list->head==NULL)//存放的头文件为空，说明Node链表内没有任何元素
    {
        //链表为空，头结点和尾结点指向同一空间地址
        /* 
        链表结构：
list->head ──────→ [new_node] ←────── list->tail
                   [data|next] 
                     ↓
                    NULL 
        */
       list->head=new_node;
       list->tail=new_node;
    }else 
    {//如果不是第一次插入数据

    new_node->next=list->head;//将新插入的数据与后面的结点链接
    //将原来头结点的前驱指针指向新插入的结点，建立双向连接
    list->head->prev=new_node;
    //将新的数据的结点设为头结点
    list->head=new_node;
    }
    //添加完毕之后，链表结点数量+1
    list->size++;
}

//6.在链表尾部插入 结点
void append(linklist * list,void *data){
    //(1)创建新结点
    Node* new_node=create_node(data);
    //(2)判断是否是第一个元素
    if(list->tail==NULL)
    {
        //链表的头结点和尾结点都为新结点
        list->head=new_node;
        list->tail=new_node;
    }else{
        //不是第一个插入的，在链表尾部插入
        new_node->prev=list->tail;//新插入的前驱指针指向尾结点（尾结点是未插入前最后一个结点的地址）
        list->tail->next=new_node;//最后一个结点的后驱指向新插入的结点
        //完成上面两步后，将插入的新结点设置为尾结点
        list->tail=new_node;
    }
    //增加了一个结点，链表结点数+1
    list->size++;
}
//7.在链表中插入结点
void insert_after(linklist *list,void * data,Node* prev_node){
    //(1)判断能否从中间插入
    if(prev_node==NULL){
        printf("前驱结点不能为NULL，插入失败\n");
        return;
    }
    //(2)创建新结点（每次插入都必须创建一个空间来存放数据）
    Node* new_node=create_node(data);
    //（1）设置新结点的前驱和后继指针
    new_node->prev=prev_node;//插入位置前一个结点的地址
    new_node->next=prev_node->next;//prev_node->next原本就指向下一个结点的地址
    //将后面的结点指向插入的新结点
    //要判断后面是否有结点（即prev_node是否是尾结点）
    if(prev_node->next!=NULL)
    {
        //不为NULL
        //就需要将下一个结点的前驱指向新插入的结点
        prev_node->next->prev=new_node;//prev_node->next下一个结点的地址
        //prev_node->next->prev表示下一个结点的前驱
    }else{
        //如果后续没有结点，将插入的结点设置为尾结点
        list->tail=new_node;
    }
    //再将prev_node的后继指向新结点
    prev_node->next=new_node;
    //链表数量+1
    list->size++;
}
//8.1 Int 类型  比较函数
int compare_data(void *a,void *b){
    return *(int*)a-*(int*)b;
}

//8.2 在链表中通过data找到某个node
Node* search_node(linklist* list,void *data,int (*compare)(void*,void*)){
    //从链表 头部开始遍历
    Node *current=list->head;
    //遍历链表
    while(current!=NULL)
    {
        //调用比较函数
        if(!compare(current->data,data))
        {
            //返回找到的结点
            return current;
        }
        //继续遍历下一个
        current=current->next;
    }
    //未找到对应的data
    return NULL;
}

//9.遍历链表
void show_linked_list(linklist *list){
    //获取头结点
    //从链表头部开始遍历
    Node* current=list->head;
    while(current!=NULL){
        printf("%d ",*(int*)(current->data));
        //继续遍历下一个
        current=current->next;
    }
    printf("\n");
}

//10.修改链表中结点的数据
void update_node(Node* node,void *data){
    if(node==NULL){
        printf("node不存在，请重新输入结点\n");
        return ;
    }
    node->data=data;
}

//11.删除数据就是删除链表中的结点、
void delete_node(linklist *list,Node* node){
    if(node==NULL){
        printf("node不存在，请重新输入结点\n");
        return ;
    }
    //执行删除操作
    //判断是否是头结点
    if(node->prev==NULL){
        //是头结点
        //更新被删除结点的下一个头结点
        list->head=node->next;
    }else{
        //如果不是头结点，是尾/中间结点
        //被删除结点的next复制给上一个结点的next
        node->prev->next=node->next;
    }
    //判断是否是尾结点
    if(node->next==NULL){
        //是尾结点
        //更新被删除结点的上一个结点的尾结点
        list->tail=node->prev;
    }else
    {
        //不是尾结点，是头/中间结点
        //被删除结点的prev复制给下一个结点的的prev
        node->next->prev=node->prev;
    }
    //释放被删除结点
    free(node);
    //结点数量-1
    list->size--;
}
//list.清空链表
void clear_linked_list(linklist *list){
    //获取头结点
    Node* current=list->head;
    while(current!=NULL)
    {
        //头结点不能为NULL
        Node* temp=current;
        current=current->next;
        //释放当前结点
        free(temp);//释放的是这个地址指向的空间
    }
    //4.初始化链表
    init_linked_list(list);
}

//mian.c
#include <stdio.h>
#include "..\inc\common.h"


int main(int argc, char const *argv[])
{   
    //1.声明双向链表
    linklist list;
    //2.初始化链表
    init_linked_list(&list);
    int a=9527,b=8848,c=666,d=777;
    //3.头部插入结点
    prepend(&list,&a);
    prepend(&list,&b); // 8848 9527
    //遍历
    show_linked_list(&list);

    //4.尾部插入结点
    append(&list,&c);// 8848 9527 666
    show_linked_list(&list);

    //5.中间插入结点
    Node* p_node=search_node(&list,&a,(*compare_data));
    insert_after(&list,&d,p_node);// 8848 9527 777 666
    show_linked_list(&list);

    //6.修改数据
    int e=888;
    update_node(p_node,&e);
    show_linked_list(&list);

    //7.删除结点
    delete_node(&list,p_node);
    show_linked_list(&list);

    //last.清空链表
    clear_linked_list(&list);
    return 0;
}
