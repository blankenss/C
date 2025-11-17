#include <stdio.h>

//三种形式打印1000-9999的润年
int main(int argc, char const *argv[])
{
    int year;
//1.for
    /* for(year=1000;year<=9999;year++)
    {
        if(( year%4==0 && year%100!=0) || year%400==0)
        {
            printf("%d是闰年\n",year);//可见5756-9996
        }
    } */
//2.while
    /* year=1000;
    while((year++)<9999){
        
        if(( year%4==0 && year%100!=0) || year%400==0)
        {
            printf("%d是闰年\n",year);//可见5756-9996
        }
    } */
//3.do-while
    year=1000;
    do{
        if(( year%4==0 && year%100!=0) || year%400==0)
        {
            printf("%d是闰年\n",year);//可见5788-9996
        }
        year++;
    }while(year<=9999);
    return 0;
}
