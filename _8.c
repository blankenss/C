#include <stdio.h>
#include <string.h>
//保存用户密码，
int main(int argc, char const *argv[])
{
    char input_name[20]="0";
    int input_pwd;
    char output_name [20]="0";
    int output_pwd;
    printf("请输入用户名和密码：");
    scanf("%s %d",&input_name,&input_pwd);

    printf("请再次输入用户名和密码：");
    scanf("%s %d",&output_name,&output_pwd);

    if(strcmp(input_name,output_name)==0 && input_pwd==output_pwd) 
    printf("登录成功");
    else printf("登录失败");
    return 0;
}
