#include <stdio.h>

int N;

int main(){
	scanf("%d",&N);
	if(N!=1&&N!=3){
        puts("EI");
		return 0;
	}
    
	scanf("%d",&N);
	if(N!=6&&N!=8){
        puts("EI");
		return 0;
	}
    
	scanf("%d",&N);
	if(N!=2&&N!=5){
        puts("EI");
		return 0;
	}
    
    puts("JAH");
}