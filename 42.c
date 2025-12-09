#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file =fopen("./.txt","w+");
    if(file==NULL)
    {
        perror("open file fail!");
        return -1;
    }
    //2 write file
    char a[3]={'a','b','c'};
    for(size_t i=0;i<3;i++)
    {
        fputc(a[i],file);
    }
    //3.move pinter
    fseek(file,0,SEEK_SET);

    //4 read file

    char c;
    while((c=fgetc(file))!=EOF){
        printf("%c\r\n",c);
    }

    //5 close file
    if(file!=NULL) fclose(file);
    return 0;
}
