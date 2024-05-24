#include <stdio.h>

int N,K,T,A,B;
int grade[1000001];

int main(){
    scanf("%d %d",&N,&K);
    for(int i=1;i<=N;i++){
        scanf("%d",&T);
        grade[i]=grade[i-1]+T;
    }

    while(K--){
        scanf("%d %d",&A,&B);
        double ans=grade[B]-grade[A-1];
        printf("%.2lf\n",ans/(B-A+1));
    }
}
