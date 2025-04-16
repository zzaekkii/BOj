#include <stdio.h>

int year, month, day;
_Bool flag;

int main(){
    scanf("%d-%d-%d",&year,&month,&day);
    
    if(year<2023)flag=1;
    else if(year==2023){
        if(month<9)flag=1;
        else if(month==9&&day<=16)flag=1;
    }
    
    puts(flag?"GOOD":"TOO LATE");
}