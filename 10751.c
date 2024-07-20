#include <stdio.h>

int R,C;
char G[16][16];
int ans;

void Dfs(int x,int y){
    if(x==R-1&&y==C-1){
        ans++;
        return;
    }
    for(int i=x+1;i<R;i++)
        for(int j=y+1;j<C;j++)
            if(G[x][y]!=G[i][j])
                Dfs(i,j);
}

int main(){
    scanf("%d %d ",&R,&C);
    for(int i=0;i<R;i++)
       gets(G[i]);
    
    Dfs(0,0);
    
    printf("%d",ans);
}
