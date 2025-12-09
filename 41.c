#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd=open("./hello.txt",O_RDWR|O_CREAT,S_IRWXU);
    if(fd==-1)
    {
        perror("open file error");
        return -1;
    }
    //2 写hello 到文件夹 write
    char* content="hello";
    int len=strlen(content)+1;
    ssize_t size=write(fd,content,len);//
    // 3 挪动指针到开始 lseek
    lseek(fd,0,SEEK_SET);

    //4 读取文件内容 read
    char* readdata=malloc(len);
    size = read(fd,readdata,len);
    printf("readdata=%s\r\n",readdata);
    //5 关闭文件 close
    close(fd);
    free(readdata);

    return 0;
}
