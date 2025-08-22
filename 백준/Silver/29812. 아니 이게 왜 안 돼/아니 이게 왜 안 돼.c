#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))

int N, D, M;
char S[200001];
int cnt[3]; // H(72:0), U(85:1), Y(89:2);

int energy;

int main(){
    scanf("%d ",&N);
    gets(S);
    scanf("%d %d",&D,&M);
    
    int seq=0;
    for(int i=0;S[i];i++){
        switch(S[i]){
            case 72:
            case 85:
            case 89:
                cnt[S[i]%3]++;
                if(seq){
                    energy+=(seq==1?D:min(seq*D,M+D));
                    seq=0;
                }
                break;
            default:
                seq++;
                break;
        }
    }
    
    if(seq)energy+=(seq==1?D:min(seq*D,M+D));
    
    int mn=cnt[0];
    for(int i=1;i<3;i++)
        mn=min(mn,cnt[i]);
    
    if(energy)printf("%d\n",energy);
    else puts("Nalmeok");
    
    if(mn)printf("%d",mn);
    else puts("I love HanYang University");
}