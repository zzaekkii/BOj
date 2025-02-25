#include <stdio.h>
#include <stdlib.h>

int X, N; // 너비 Xcm, 레고 조각 N개.
int L[1000001]; // 각 레고의 길이 L[i]nm (천만nm==1cm)

int cmp(int *a, int*b){
    return *a-*b;
}

int main(){
    while(~scanf("%d",&X)){ // 테케 개수 주어지지 않음. 
		scanf("%d",&N);
				
		for(int i=0;i<N;i++)
            scanf("%d",&L[i]);

		qsort(L,N,sizeof(int),cmp);
		
		X*=10000000; // 나노미터화.
		int st=0, en=N-1;
		
		while(st<en){
            if(L[st]+L[en]>X)en--;
            else if(L[st]+L[en]<X)st++;
            else break;
        }
		
		if(st<en)printf("yes %d %d\n",L[st],L[en]);
		else puts("danger");
	}
}