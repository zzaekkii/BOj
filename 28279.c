#include <stdio.h>
#define MOD 1000000

int N,O,X;

int dq[1000000];
int head,tail;

int main(){
    scanf("%d",&N);
    
    while(N--){
        scanf("%d",&O);
        switch(O){
            case 1: // 덱 앞에 추가.
                scanf("%d",&X);
                dq[(head-1+MOD)%MOD]=X; // 현 헤드 전에 추가.
                head=(head-1+MOD)%MOD; // 헤드 뒤로 이동.
                break;
            case 2: // 덱 뒤에 추가.
                scanf("%d",&X);
                dq[tail%MOD]=X; // 현 꼬리에 추가.
                tail=(tail+1+MOD)%MOD; // 꼬리 앞으로 이동.
                break;
            case 3: // 덱 head pop().
                if(dq[head]){
                    printf("%d\n",dq[head]);
                    dq[head]=0;
                    head=(head+1+MOD)%MOD;
                }                            
                else puts("-1");
                break;
            case 4: // 덱 tail-1 pop().
                if(dq[head]){
                    printf("%d\n",dq[(tail-1+MOD)%MOD]);
                    dq[(tail-1+MOD)%MOD]=0;
                    tail=(tail-1+MOD)%MOD;
                }
                else puts("-1");
                break;
            case 5: // 덱 원소 개수 출력.
                if(head>tail)printf("%d\n",MOD-head+tail);
                else printf("%d\n",tail-head);
                break;
            case 6: // 덱.empty()
                if(dq[head])puts("0");
                else puts("1");
                break;
            case 7: // 덱 head 출력.
                if(dq[head])printf("%d\n",dq[head]);
                else puts("-1");
                break;
            case 8: // 덱 tail-1 출력.
                if(dq[head])printf("%d\n",dq[(tail-1+MOD)%MOD]);
                else puts("-1");
                break;
        }
    }
}
