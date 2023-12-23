#include <stdio.h>
int N=10,T;
int top=1;
int main(){
    while(N--){
        scanf("%d",&T);
        if(T==1){
            top+=1;
            if(top>4)top=1;
        }
        else if(T==2){
            top+=2;
            if(top>4)top=top-4;
        }
        else{
            top-=1;
            if(top<1)top=4;
        }
    }
    puts(top==1?"N":top==2?"E":top==3?"S":"W");
}
