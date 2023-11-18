#include <stdio.h>
int N;
long long LT,WT,LE,WE;
int main(){
  scanf("%d",&N);
  while(N--){
    scanf("%lld%lld%lld%lld",&LT,&WT,&LE,&WE);
    if(LT*WT>LE*WE)puts("TelecomParisTech");
    else if(LT*WT<LE*WE)puts("Eurecom");
    else puts("Tie");
  }
}
