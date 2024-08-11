#include <stdio.h>

int N;

void Dfs(int n){
    if(!n){
        printf("-");
        return;
    }
    Dfs(n-1);
    
    int l=1;
    for(int i=0;i<n-1;i++,l*=3);
    for(int i=0;i<l;i++)
        printf(" ");
    
    Dfs(n-1);
}

int main(){
    while(~scanf("%d",&N)){
        Dfs(N);
        puts("");
    }
}
