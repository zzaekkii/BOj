#include <stdio.h>
int N, i, f, x;
int T, a[3], s[3];

int main(){
    scanf("%d",&N);
    while(N--)
        for(i=0;i<3;i++){
            scanf("%d",&T);
            a[i]+=T;
            s[i]+=T*T*T*T;
        }
    
    int m=a[0];
    for(i=1;i<3;i++)
        if(m<=a[i]){
            x=i;
            m=a[i];
        }
    
    for(i=0;i<3;i++)if(m==a[i])f++;
    
    if(f>1){
        m=s[0];
        for(i=1;i<3;i++)if(m<s[i])m=s[i];
        int cnt=0;
        for(i=0;i<3;i++)
            if(m==s[i]){
                x=i;
                cnt++;
            }
        if(cnt==1)printf("%d %d",x+1,a[x]);
        else printf("0 %d",a[x]);
    }
    else printf("%d %d",x+1,m);
}