//头文件 common_tree.h

#ifndef COMMON_TREE_H
#define COMMON_TREE_H

//1.定义红黑树的结点颜色
typedef enum{RED,BLACK}NodeColor;

//2.红黑叔 结点结构
typedef struct RBTreeNode
{
    //结点数据
    void *data;
    //结点颜色
    NodeColor color;
    //父节点指针
    struct RBTreeNode *parent;
    //子结点指针
    struct RBTreeNode *LChild;
    //右子结点指针
    struct RBTreeNode *RChild;
}RBTreeNode;

//3.红黑叔的结构体，红黑树要准备一个哨兵结点
//(代表树操作的边界，通常用一个空空结点表示，红黑树中空结点必须是黑色)
typedef struct RBTree{
    //树 根结点 root结点
    RBTreeNode *root;
    //哨兵结点
    RBTreeNode *nil;
}RBTree;

//4.创建红黑树的结点，新结点默认为红色，新结点的左右子节点，父节点都指向哨兵结点
RBTreeNode* create_node(RBTree* tree,void *data); 

//5.创建红黑树
RBTree* create_tree(); 

//6.左旋：当前结点x 的右子节点y向上提，当前结点下移至其y的左子节点的位置
void left_rotation(RBTree* tree,RBTreeNode *x);

//7.右旋：当前结点y的左子节点x向上提，当前结点下移至其x的右子节点的位置
void right_rotation(RBTree* tree,RBTreeNode *y);

//8.插入修复
void insert_fixup(RBTree* tree,RBTreeNode *z);

//9.1 比较函数 (int 类型比较)
int compare_int(void *a,void *b);

//9.2 插入操作
void insert_RBTree(RBTree* tree,void *data,int (*cmp)(void *a,void *b));

//10.1 示例打印(int类型)
void show_tree_int(RBTreeNode *node);

//10.2 先序遍历
void preorder_traversal(RBTree* tree,RBTreeNode *node,void (*show_data)(RBTreeNode *node));
//10.2 中序遍历
void inorder_traversal(RBTree* tree,RBTreeNode *node,void (*show_data)(RBTreeNode *node));
//10.3 后序遍历
void postorder_traversal(RBTree* tree,RBTreeNode *node,void (*show_data)(RBTreeNode *node));

//last1.释放结点
void destroy_node(RBTree* tree,RBTreeNode *node);

//last2.释放树
void free_tree(RBTree* tree);
#endif

//.c文件
#include <stdio.h>
#include <stdlib.h>
#include "../inc/common_tree.h"

//4.创建红黑树的结点，新结点默认为红色，新结点的左右子节点，父节点都指向哨兵结点
RBTreeNode* create_node(RBTree* tree,void *data)
{
    //4.1动态分配内存,创建新结点
    RBTreeNode* new_node=(RBTreeNode*)calloc(1,sizeof(RBTreeNode));
    if(new_node==NULL){
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    //结点数据
    new_node->data=data;
    //新结点默认为红色
    new_node->color=RED;
    //初始化指针都指向NULL
    new_node->parent=tree->nil;
    new_node->LChild=tree->nil;
    new_node->RChild=tree->nil;
    //返回创建的结点地址
    return new_node;
}
//5.创建红黑树
RBTree* create_tree(){
    RBTree* tree=(RBTree*)calloc(1,sizeof(RBTree));
    if(tree==NULL){
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    //5.2创建哨兵结点
    tree->nil=(RBTreeNode*)calloc(1,sizeof(RBTreeNode));
    //哨兵结点必须为黑色
    tree->nil->color=BLACK;
    //初始树 根节点要为哨兵
    tree->root=tree->nil;
    return tree;
}

//6.左旋：当前结点x 的右子节点y向上提，当前结点下移至其y的左子结点的位置
void left_rotation(RBTree* tree,RBTreeNode *x){
    //6.1设置y为x的右子结点
    RBTreeNode* y=x->RChild;
    //6.2 x的右子结点赋值为y的左结点
    x->RChild=y->LChild;
    //6.3 判断y的左子结点是否为哨兵结点
    if(y->LChild!=tree->nil)
    {
        //不是空结点可以将y的左子结点的父结点赋值为x
        y->LChild->parent=x;

    }
    //将y的父节点赋值为x的父节点
    y->parent=x->parent;
    //判断x的父节点是否是空结点
    if(x->parent==tree->nil)
    {
        tree->root=y;
    }else if(x==x->parent->LChild)
    {
        x->parent->RChild=y;
    }
    //y的左子结点赋值为x
    y->LChild=x;
    //将X的父节点赋值为y
    x->parent=y;
}

//7.右旋：当前结点y的左子节点x向上提，当前结点下移至其x的右子节点的位置
void right_rotation(RBTree* tree,RBTreeNode *y){
    //7.1设置x 为y的左子节点
    RBTreeNode *x=y->LChild;
    //7.2将y的左子节点赋值为x的右子节点
    y->LChild=x->RChild;
    //7.3判断x的右子节点 是否为哨兵结点
    if (x->RChild!=tree->nil)
    {   
        //更新 x的右子节点 的 父节点  为y
        x->RChild->parent=y;
    }

    //7.4 x的父节点 赋值为 y的父节点
    x->parent=y->parent;
    //7.4 判断y的父节点 是否为哨兵
    if (y->parent==tree->nil)
    {   
        //更新x为根结点
        tree->root=x;
    }else if (y==y->parent->LChild)
    {
        //更新 x为 父节点 的左子节点
        y->parent->LChild=x;
    }else
    {
        //更新 x为 父节点 的右子节点
        y->parent->RChild=x;
    }
    //x的右子节点为y
    x->RChild=y;
    //y的父节点为x
    y->parent=x;
}
//8.插入修复
void insert_fixup(RBTree* tree,RBTreeNode *z){
    //当插入结点的父节点为红色时进入修复环节，红黑树不允许红色连续
    while(z->parent->color==RED){
        //判断父节点的位置
        //父节点在祖父结点的左子结点
        if(z->parent==z->parent->parent->LChild)
        {
            //获取叔叔结点
            RBTreeNode *y=z->parent->parent->RChild;
            //情况1：叔叔结点为红色
            if(y->color==RED){
                //父节点为黑，叔叔结点为黑
                z->parent->color=BLACK;
                y->color=BLACK;
                //祖父结点为红
                z->parent->parent->color=RED;
                //继续向上检查父节点是否需要修复
                z=z->parent->parent;
            }else{
                //叔叔结点为黑色
                //情况2  转换为情况3
                //z为父结点的右子结点
                if(z==z->parent->RChild){
                    //当前结点变为父节点
                    z=z->parent;
                    //左旋父节点
                    left_rotation(tree,z);
                }
                //情况3，z为父节点的左子结点
                //祖父为红，父节点为黑
                z->parent->color=BLACK;
                z->parent->parent->color=RED;
                //右旋祖父结点
                right_rotation(tree,z->parent->parent);
            }
            
        }else{
            //处理镜像情况
            //叔叔结点为祖父结点的左子结点，父节点为右子结点
            RBTreeNode *y=z->parent->parent->LChild;
            if(y->color==RED)
            {
                //父节点为黑，叔叔结点为黑
                z->parent->color=BLACK;
                y->color=BLACK;
                //祖父结点为红
                z->parent->parent->color=RED;
                //继续向上检查祖父结点是否需要修复
                z=z->parent->parent;
            }else{
                //叔叔为黑，判断当前结点是父节点的左子节点
                //情况2 当前结点是父节点的左子节点
                if (z==z->parent->LChild)
                {
                    //当前结点 变为 父节点
                    z=z->parent;
                    //右旋父节点
                    right_rotation(tree,z);
                }
                //情况3 当前结点是父节点的右子节点
                //祖父为红，父节点为黑
                z->parent->color=BLACK;
                z->parent->parent->color=RED;
                //左旋祖父结点
                left_rotation(tree,z->parent->parent);
            }
        }

    }
    //根结点为黑色
    tree->root->color=BLACK;
}

//9.1 比较函数（int 类型比较）
int compare_int(void *a,void *b){
    return *(int*)a - *(int*)b;//0相同
}
//9.2 插入操作
void insert_RBTree(RBTree* tree,void *data,int (*cmp)(void *a,void *b)){
    //创建新结点 
    RBTreeNode *z=create_node(tree,data);
    //临时结点  y是父节点
    RBTreeNode *y=tree->nil;
    //从根结点开始比较，找父节点
    RBTreeNode *x=tree->root;
    //寻找父节点
    while (x!=tree->nil)
    {
        y=x;
        if (cmp(z->data,x->data)<0)
        {
            x=x->LChild;
        }else
        {
            x=x->RChild;
        }
    }
    //z的父节点赋值y
    z->parent=y;
    //如果第一次插入结点
    if (y==tree->nil)
    {
        //新结点为根结点
        tree->root=z;
    }else if (cmp(z->data,y->data)<0)
    {
        //插入在父节点的左子树
        y->LChild=z;
    }else
    {
        //插入在父节点的右子树
        y->RChild=z;
    }
    //插入后  调用插入修复
    insert_fixup(tree,z);

}

//10.1 示例打印(int类型)
void show_tree_int(RBTreeNode *node){
    printf("%d(%s) ",*(int*)node->data,node->color?"B":"R");
}

//10.2 先序遍历
void preorder_traversal(RBTree* tree,RBTreeNode *node,void (*show_data)(RBTreeNode *node)){
    //当前结点不能是哨兵结点
    if (node!=tree->nil)
    {   
        //展示中间结点
        show_data(node);
        //左子树
        preorder_traversal(tree,node->LChild,show_data);
        //右子树
        preorder_traversal(tree,node->RChild,show_data);
    }
    
}
//10.2 中序遍历
void inorder_traversal(RBTree* tree,RBTreeNode *node,void (*show_data)(RBTreeNode *node)){
    //当前结点不能是哨兵结点
    if (node!=tree->nil)
    {   
        //左子树
        inorder_traversal(tree,node->LChild,show_data);
        //展示中间结点
        show_data(node);
        //右子树
        inorder_traversal(tree,node->RChild,show_data);
    }
}
//10.3 后序遍历
void postorder_traversal(RBTree* tree,RBTreeNode *node,void (*show_data)(RBTreeNode *node)){
    //当前结点不能是哨兵结点
    if (node!=tree->nil)
    {   
        //左子树
        postorder_traversal(tree,node->LChild,show_data);
        //右子树
        postorder_traversal(tree,node->RChild,show_data);
        //展示中间结点
        show_data(node);
    }
}


//last1.释放结点
void destroy_node(RBTree* tree,RBTreeNode* node)
{
    if(node!=tree->nil)
    {
        destroy_node(tree,node->LChild);
        destroy_node(tree,node->RChild);
        free(node);
    }
}
//last2.释放树
void free_tree(RBTree* tree){
    //从根结点开始释放
    destroy_node(tree,tree->root);
    //释放哨兵结点
    free(tree->nil);
    //释放树本身
    free(tree);
}
