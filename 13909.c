#include <stdio.h>

int N;
int ans;

int main(){
    scanf("%d",&N);
    for(int i=1;i*i<=N;i++)
        ans++;
    printf("%d",ans);
}
