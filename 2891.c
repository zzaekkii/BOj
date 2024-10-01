#include <stdio.h>

int N,S,R,T;
int pos[11];

int main(){
    scanf("%d %d %d",&N,&S,&R);
    for(int i=1;i<=N;i++)pos[i]=1; // 초기: 멀쩡.
    
    for(int i=0;i<S;i++){
        scanf("%d",&T);
        pos[T]--; // 손상.
    }
    
    for(int i=0;i<R;i++){
        scanf("%d",&T); // 여분 멤버.
        pos[T]++;
    }
    
    for(int i=1;i<=N;i++)
        if(pos[i]>1){
            if(i!=1&&!pos[i-1]){
                pos[i-1]++;
                pos[i]--;
            }
            else if(i!=N&&!pos[i+1]){
                pos[i+1]++;
                pos[i]--;
            }
        }
    
    int cnt=0;
    for(int i=1;i<=N;i++)
        if(!pos[i])cnt++; // 손상 카운트.
    printf("%d",cnt);
}
