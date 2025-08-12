#include <stdio.h>

int N, M;
int board[101][101];
int zelda[101][101];

int main(){
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            scanf("%d",&board[i][j]);
    
    zelda[1][1]=1; // 출발점.

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(board[i][j])
                if((board[i-1][j]&&zelda[i-1][j])||(board[i][j-1]&&zelda[i][j-1]))
                    zelda[i][j]=1;
    
    puts(zelda[N][M]?"1":"0");
}