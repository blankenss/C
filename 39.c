//头文件

#ifndef QUEUE_H
#define QUEUE_H

//1.创建结构体

typedef struct Node{
    void* data;
    struct Node* next;
}Node;

typedef struct queue
{
    Node* head;
    Node* tail;
    //队列长度
    int size;
}queue;

void init_queue(queue* q);

//4.入队操作，向队列添加数据
void add_queue(queue* q,void* data);

//5.出队操作
void* dequque(queue* q);

//6.查看头结点的数据,--出队
void *peek(queue* q);

//last.摧毁队列
void clear_queue(queue* q);

#endif

//.c文件
#include <stdio.h>
#include <stdlib.h>
#include "../inc/queue.h"

//3.初始化队列
void init_queue(queue* q){
    q->head=NULL;
    q->tail=NULL;
    q->size=0;
}

//4.入队操作，向队列添加数据
void add_queue(queue* q,void* data){
    Node* new_node=(Node*)calloc(1,sizeof(Node));
    //判断空间是否创建成功
    if(new_node==NULL){
        printf("空间创建失败\n");
        exit(EXIT_FAILURE);
    }
    new_node->data=data;
    //队列在尾部插入
    new_node->next=NULL;
    //判断队列是否为空
    if(q->head!=NULL){
        q->tail->next=new_node;//通过尾结点，找到插入前的最后一个结点
    }else{
        q->head=new_node;
    }
    q->tail=new_node;
    q->size++;
}

//5.出队操作
void* dequque(queue* q){
    //1.判断队列是否为空
    if(q->head==NULL){
        printf("队列为空，无法出队\n");
        return NULL;
    }
    //队列从头部出列
    Node* current=q->head;
    void* data=current->data;
    //更新头结点,头结点的下一个地址
    q->head=current->next;
    //判断是否只有一个结点、
    //这是在下一个结点的地址传递过来后在判断，是否为空队列
    if(q->head==NULL){
        q->tail=NULL;
    }
    //出队后需要释放空间
    free(current);
    //
    q->size--;
    return data;
}

//6.查看头结点的数据
void *peek(queue* q){
    if(q->head==NULL){
        printf("队列为空，无法查看\n");
    }
    return q->head->data;
}

//last.摧毁队列
void clear_queue(queue* q){
    while(q->head!=NULL){
        Node* current=q->head;
        q->head=current->next;
        free(current);
    }
    //清空后
    q->tail=NULL;
    q->size=0;
}


//main.c文件

#include <stdio.h>
#include "../inc/queue.h"

int main(int argc, char const *argv[])
{
    //1.声明队列
    queue my_queue;
    //2.初始化队列
    init_queue(&my_queue);

    //3.先进先出
    int a=10,b=20,c=30,d=40;

    //4.入队
    add_queue(&my_queue,&a);
    add_queue(&my_queue,&b);
    add_queue(&my_queue,&c);
    add_queue(&my_queue,&d);
    int *res=(int*)peek(&my_queue);
    printf("*res=%d\n",*res);


    //5.出队
    res=dequque(&my_queue);
    printf("*res=%d\n",*res);

    //6.查看
    printf("********查看********\n");
    res= (int*)peek(&my_queue);
    printf("*res=%d\n",*res);

    res= (int*)dequque(&my_queue);
    printf("*res=%d\n",*res);

    res= (int*)peek(&my_queue);
    printf("*res=%d\n",*res);

    res= (int*)dequque(&my_queue);
    printf("*res=%d\n",*res);
    
    res= (int*)peek(&my_queue);
    printf("*res=%d\n",*res);

//清空队列
    clear_queue(&my_queue);
    return 0;
}
