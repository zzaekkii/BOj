#include <stdio.h>

int main(){
  int N,A,B;
  scanf("%d%d%d",&N,&A,&B);
  puts(A<B?"Bus":A>B?"Subway":"Anything");
}
