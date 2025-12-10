#include <stdio.h>
#include <library.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    //定义一个链表
    List* list=(List*)malloc(sizeof(List));
    //初始化链表
    Init_Linked_List(list);
    while(1){
    printf("*****************************************\n");
    printf("***************1.添加图书*****************\n");
    printf("***************2.显示所有图书***************\n");
    printf("***************3.删除图书*****************\n");
    printf("***************4.编辑图书*****************\n");
    printf("***************5.查找图书*****************\n");
    printf("***************6.排序图书****************\n");
    printf("***************0.退出程序****************\n");
   printf("请选择你要执行的功能：\n");
    int a;
    scanf("%d",&a);
    switch(a)
    {
        case 1:
        Add_Book(list);
            break;
        case 2:
        Show_Book(list);
            break;
        case 3:
        delete_node(list);
        break;    
        case 4:
        update_node(list);
        break; 
        case 5:
        find_book(list);
        break;
        case 6:
        price_sort(list);
        case 0:
        break;
       default:
        break;
    }
}
    //释放链表空间
    clear_linked_list(list);
    return 0;
}
//library.h
#ifndef LIBRARY_H
#define LIBRARY_H
#define CHAR_MAX 20
//1.定义存放图书的结构体

typedef struct Book{

    char book_name[CHAR_MAX];//书名
    char writer[CHAR_MAX];//作者
    char publication_time[CHAR_MAX];//出版日期
    double book_price;//图书价格

}Book;

//2.定义节点(双链表结构)
typedef struct Node{
    Book *data;

    struct Node *pre;
    struct Node *next;
}Node;

//3.定义链表
typedef struct Linked_list{
    Node *head;
    Node *tail;
    int size;
} List;
/* //4.创建一个新节点
Node* create_node(Book* data); */

//5.初始化链表
void Init_Linked_List(List* list);

//6.添加图书
void Add_Book(List* llist);
//7.展示所有图书
void Show_Book(List* list);
//8.删除图书
void delete_node(List *list);

//9.编辑图书
void update_node(List* list); 
//10.查找对应的图书
void find_book(List* list);
//11.按照价格排序
void price_sort(List* list);

//last.清空链表
void clear_linked_list(List *list);
#endif


//library.c
#include <library.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* //4.创建一个新节点
Node* create_node(Book* data)
{
    Node* new_node=(Node*)calloc(1,sizeof(Node));
    if(new_node == NULL){
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    //初始化节点
    new_node->data=data;
    new_node->next=NULL;
    new_node->pre=NULL;
    return new_node;
} */

//5.初始化链表
void Init_Linked_List(List* list)
{   if(list!=NULL){
    list->head=NULL;
    list->tail=NULL;
    list->size=0;
    }
}

//6.添加图书
void Add_Book(List* list)
{
    //1.创建一个Book结构体空间来存放书籍信息
    Book* new_book=(Book*)malloc(sizeof(Book));
    if(new_book==NULL){
        printf("图书数据存放空间开辟失败");
        exit(EXIT_FAILURE);
    }
    printf("请输入添加书籍的 名称 作者 出版日期(YYYY-MM-DD) 图书价格（中间用空格隔开）\n");
    char book_name[CHAR_MAX];//书名
    char writer[CHAR_MAX];//作者
    char publication_time[CHAR_MAX];//出版日期
    double book_price;//图书价格
    scanf("%s %s %s %lf",book_name,writer,publication_time,&book_price);

     // 将数据存储到 new_book 中
    strcpy(new_book->book_name, book_name);
    strcpy(new_book->writer, writer);
    strcpy(new_book->publication_time, publication_time);
    new_book->book_price = book_price;

//2.创建节点存放book的数据
Node* new_node=(Node*)calloc(1,sizeof(Node));
    if(new_node == NULL){
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    //节点赋值
    new_node->data=new_book;
    if(list->size==0){
        list->head=new_node;
        list->tail=new_node;
    }else{
        new_node->pre=list->tail;
        list->tail->next=new_node;
        list->tail=new_node;
        new_node->next=NULL;
    }
    list->size++;
}

//7.展示所有图书
void Show_Book(List* list)
{
    if(list==NULL || list->size==0){
        printf("图书列表为空\n");
        return ;
    }
    Node* current=list->head;
    //int count=1;

    printf("书籍的\t\t名称\t\t作者\t\t出版日期\t\t图书价格\n");
    while(current!=NULL){
    printf("%s\t\t%s\t\t%s\t\t%lf\t\t\n",current->data->book_name,
                                current->data->writer,
                                current->data->publication_time,
                                current->data->book_price);
    current=current->next;
    }
    
}
//8.删除图书
void delete_node(List *list){

    // 检查链表是否为空
    if(list == NULL || list->head == NULL){
        printf("链表为空，无法删除\n");
        return;
    }
    char book_name[CHAR_MAX];//书名
    printf("请输入要删除书籍的名称\n");
    scanf("%s", book_name); 
    //1.找到书名所在的节点
    Node* current=list->head;
    for(int i=0;i<list->size && current != NULL;i++){
        
        if(strcmp(book_name,current->data->book_name)==0){
            //如果是头结点
            if(current->pre==NULL){
                list->head=current->next;
            }else{
               current->pre->next=current->next; 
            }
            //如果是尾节点
            if(current->next==NULL){
                list->tail=current->pre;
            }else{
                //不是尾节点
                current->next->pre=current->pre;
            }
            free(current->data);
            list->size--;
            free(current);
            break;
        }else{
            current=current->next;
        }
    }
}

//9.编辑图书编辑图书：⽤户可以修改链表中指定图书的作者、出版⽇期或价格。
void update_node(List* list){
    if (list==NULL || list->head==NULL)
    {
        printf("链表为空，无法编辑！\n");
        return;
    }
    char book_name[CHAR_MAX];//书名
    printf("请输入要编辑书籍的名称\n");
    scanf("%s", book_name); 
    //1.找到书名所在的节点
    Node* current=list->head;
    for(int i=0;i<list->size && current != NULL;i++){
        
        if(strcmp(book_name,current->data->book_name)==0){
            printf("请选择你要修改的内容 并输入你要修改的结果（中间用空格隔开）\n");
            printf("1.书名\t2.作者\t3.出版日期\t4.价格:\n");
            int number;
            char str[CHAR_MAX];
            scanf("%d %s",&number,str);
            enum book_edit{NAME=1,WRITE=2,DATE=3,PRICE=4};
            switch(number){
                case NAME:
                strcpy(current->data->book_name,str);
                break;
                case WRITE:
                strcpy(current->data->writer,str);
                break;
                case DATE:
                strcpy(current->data->publication_time,str);
                break;
                case PRICE:
                //强制类型转换 将字符串转换成double类型数据
                char *endptr;//检测符，检测是否有错误
                double num = strtod(str, &endptr);
                
                if (*endptr == '\0') {
                    printf("转换完全成功\n");
                } else {
                    printf("遇到无效字符: %s\n", endptr);
                }
                current->data->book_price=num;
                break;
                default:
                break;
            }
            break;
        }
        current=current->next; 
    }
} 

//10.查找对应的图书
void find_book(List* list){
    char book_name[CHAR_MAX];//书名
    printf("请输入要查找书籍的名称\n");
    scanf("%s", book_name); 
    //1.找到书名所在的节点
    Node* current=list->head;
    int flag=1;
    for(int i=0;i<list->size && current != NULL;i++){
        
        if(strcmp(book_name,current->data->book_name)==0){
            flag=0;
            printf("书籍的\t\t名称\t\t作者\t\t出版日期\t\t图书价格\n");
            printf("%s\t\t%s\t\t%s\t\t%lf\t\t\n",current->data->book_name,
                                current->data->writer,
                                current->data->publication_time,
                                current->data->book_price);
                                break;
        }
        current=current->next;
    }if(flag){
        printf("未找到该书籍\n");
    }
}

//11.按照书籍价格排序
void price_sort(List* list){
    if (list == NULL || list->head == NULL || list->size <= 1) {
        return;  
    }
    

    for(int i=0;i<list->size-1;i++){
        Node* current=list->head;

        for(int j=0;j<list->size-i;j++){
            if (current->next == NULL) {
                break;  // 安全保护
            }
           if(current->data->book_price < current->next->data->book_price){
            
            Book* tmp=current->data;
            current->data=current->next->data;
            current->next->data=tmp;

        } current=current->next;
        } 
    }
}
//last.清空链表
void clear_linked_list(List *list){
    //获取头结点
    Node* current=list->head;
    //获取下一个结点
    while (current!=NULL)
    {
        //头结点不能为NULL
        Node* temp=current;
        current=current->next;
        //释放当前结点
        free(temp);
    }
    //4.初始化链表
    Init_Linked_List(list);
}


