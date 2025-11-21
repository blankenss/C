include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
零长数组 是GUN组织提供的一个出名扩展。
零长数组也被叫做柔性数组，是为了满足需要变长度的结构体；
用法：在一个结构体的最后，申明一个长度为0的数组，就可以使得这个结构体是可变长的，
对于编译器来说此时零长数组并不占用空间，因为数组名本身不占空间，它只是一个偏移量，
数组名这个符号本身代表了一个不可修改的地址常量。
*/
struct student
{
    int id;
    int sno;
    //零长数组必须声明在结构体的最后
    char name[0];
};

int main(int argc, char const *argv[])
{
    //此时char name[];还没有分配空间
    printf("struct student的字节数：%llu\n",sizeof(struct student));//8
    //零长数组不能直接使用

    //分配空间 强转

    int length=sizeof(struct student)+sizeof(char)*10;
    //动态开辟空间 动态内存管理
    struct student *sp=(struct student *)malloc(length);//需要开辟的空间字节数
    printf("sp=%p\n",sp);
    sp->id=9527;
    sp->sno=8848;
    strcpy(sp->name,"abc123");
    printf("id=%d,sno=%d,name=%s\n",sp->id,sp->sno,sp->name);
//程序过程：先编译    后运行代码  故编译期时代码还没有分配空间sizeof(sp->name)的空间为0
    printf("%d\n",strlen(sp->name));//运行期
    printf("%d\n",sizeof(sp->name));//编译期

    //释放内存
    free(sp);

    struct student *sp2=(struct student *)malloc(50);
    printf("sp2%p\n",sp2);
    sp2->id=9528;
    sp2->sno=8849;
    strcpy(sp2->name,"迪丽热巴·迪力木拉提");
    printf("id=%d,sno=%d,name=%s\n",sp2->id,sp2->sno,sp2->name);
    
    printf("%llu\n",strlen(sp2->name));
    printf("%llu\n",sizeof(sp2->name));

    //释放内存
    free(sp2);
    
    return 0;
}
