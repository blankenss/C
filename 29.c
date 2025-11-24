#include <stdio.h>
#include <stddef.h>
/*
计算结构体的大小：
ps:由于存储变量 受地址对齐规则和编译器优化策略的影响；
    1.偏移量从0开始；
    2.整个结构体的按最大成员的对齐要求来对齐(通常最大成员是按基本类型计算)；
    3.每个成员按照其自身类型的的对齐规则对齐;
    4.结构体整体大小必须是最大对齐数的整数倍；
    5.编译器为了对求，可能在成员之间插入填充字节；
    6.结构体末尾也可能会补；
*/

struct student
{
    int id; 
    int sno;
    double height;        
    char initial_of_name; 
};

// 带数组
struct student2
{
    int id; 
    // 如果下一个成员是数组，则不发生额外偏移
    char name[5];
    char pwd[6];
    double height;        
    char initial_of_name; 
};

// 嵌套结构体
struct student3
{
    int id; // 主键
    struct
    {
        double d1;
        char c2;
    } m1;
    int height;            
    char initial_of_name; 
};

int main(int argc, char const *argv[])
{
    printf("%llu\n", sizeof(struct student));                                                                  // 24字节
    printf("struct student int id的偏移量：%llu\n", offsetof(struct student, id));                             // 0
    printf("struct student int sno的偏移量：%llu\n", offsetof(struct student, sno));                           // 4
    printf("struct student  double height的偏移量：%llu\n", offsetof(struct student, height));                 // 8
    printf("struct student  char initial_of_name的偏移量：%llu\n", offsetof(struct student, initial_of_name)); // 16

    printf("%llu\n", sizeof(struct student2));                                                                   //
    printf("struct student2 int id的偏移量：%llu\n", offsetof(struct student2, id));                             // 0
    printf("struct student2 char name[5]%llu\n", offsetof(struct student2, name));                               // 4
    printf("struct student2 char pwd[5]%llu\n", offsetof(struct student2, pwd));                                 // 9
    printf("struct student2  double height的偏移量：%llu\n", offsetof(struct student2, height));                 // 16
    printf("struct student2  char initial_of_name的偏移量：%llu\n", offsetof(struct student2, initial_of_name)); // 24

    printf("%llu\n", sizeof(struct student3));                                       //32
    printf("struct student3 int id的偏移量：%llu\n", offsetof(struct student3, id)); // 0
    printf("struct student3 m1的偏移量：%llu\n", offsetof(struct student3, m1));//8
    printf("struct student3  double height的偏移量：%llu\n", offsetof(struct student3, height));                 //24
    printf("struct student3  char initial_of_name的偏移量：%llu\n", offsetof(struct student3, initial_of_name)); //28

    return 0;
}
