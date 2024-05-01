#include <stdio.h>
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x) (((x)<0)?-(x):(x))

typedef struct Ing{
    int S,B;
}Ing;

int N;
int ans=0x7FFFFFFF;
Ing ing[11];

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d %d",&ing[i].S,&ing[i].B);
    
    for(int i=1;i<(1<<N);i++){
        int s=1,b=0;
        for(int j=0;j<N;j++){
            if(i&(1<<j)){
                s*=ing[j].S;
                b+=ing[j].B;
            }
        }
        ans=MIN(ans,ABS(s-b));
    }
    
    printf("%d",ans);
}
