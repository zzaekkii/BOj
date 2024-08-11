#include <stdio.h>

int R,C,K;
char board[6][6];
_Bool vis[6][6];
int dis,ans;

int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

void Dfs(int x,int y){
    if(x==0&&y==C-1){
        if(dis==K)ans++;
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<R&&ny>=0&&ny<C)
            if(!vis[nx][ny]&&board[nx][ny]!='T'){
                vis[nx][ny]=1;
                dis++;
                Dfs(nx,ny);
                vis[nx][ny]=0;
                dis--;
            }
    }
}

int main(){
    scanf("%d %d %d ",&R,&C,&K);
    for(int i=0;i<R;i++)
        gets(board[i]);
    vis[R-1][0]=dis=1;
    Dfs(R-1,0);
    printf("%d",ans);
}
