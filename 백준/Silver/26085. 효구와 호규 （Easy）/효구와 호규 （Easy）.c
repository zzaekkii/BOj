#include <stdio.h>

int N, M;
int board[1001][1001];

int cnt0,cnt1;
_Bool flag;

int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int main(){
    scanf("%d %d",&N,&M);
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            scanf("%d",&board[i][j]);
            
            if(board[i][j])cnt1++;
            else cnt0++;
        }
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            for(int dir=0;dir<4;dir++){
                int nx=i+dx[dir],ny=j+dy[dir];
                if(nx>=0&&nx<N&&ny>=0&&ny<M&&board[i][j]==board[nx][ny]){
                    flag=1;
                    break;
                }
            }
    
    puts((cnt0%2)||(cnt1%2)||((N*M)%2)||!flag?"-1":"1");
}