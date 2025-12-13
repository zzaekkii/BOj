#include <stdio.h>

int N;
int book[300001];
int ans;

int main(){
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
        scanf("%d",&book[i]);
    
    for(int i=N-1;i>=0;i--){
        if(book[i]==N)N--;
        else ans++;
    }
    
    printf("%d",ans);
}