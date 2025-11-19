#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int year;
    int month;
    printf("请输入年份和月份：");
    scanf("%d %d",&year,&month);
    if((year%4==0 && year%100!=0) || year%400==0)
    {
        printf("%d为闰年",year);
        if(month==1 || 
           month==3 || 
           month==5 ||
            month==7 ||
            month==8 ||
            month==10 ||
            month==12) printf("%d月有31天",month);

         else if(month==2) printf("%d月有29天",month);
         
         else printf("%d该月有30天",month);
    }else {
        printf("%d为平年",year);
        if(month==1 || 
           month==3 || 
           month==5 ||
            month==7 ||
            month==8 ||
            month==10 ||
            month==12) printf("%d月有31天",month);
         else if(month==2) printf("%d月有28天",month);
         else printf("%d月有30天",month);
    }
    
    return 0;
}
