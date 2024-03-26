#include <stdio.h>

int N;
int Arr[101];
int ans;

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&Arr[i]);
    for(int i=N-1;i>0;i--)
        while(Arr[i]<=Arr[i-1]){
            Arr[i-1]--;
            ans++;
        }
    printf("%d",ans);
}
