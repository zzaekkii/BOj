#include <stdio.h>

int N, M;
int board[101][101];
_Bool vis[101][101][4];

int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

void init(){
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			for(int dir=0;dir<4;dir++)
				vis[i][j][dir]=0;
}

int main(){
    scanf("%d %d", &N, &M);
	
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d", &board[i][j]);
	
	int total=0;
	_Bool rows[101]={0};
	for(int i=0;i<N;i++){
        init();
		int x=i,y=0,dir=0;
		vis[x][y][dir]=1;
		
		while(1){
			int nx=x+dx[dir]*board[x][y];
			int ny=y+dy[dir]*board[x][y];
			
			if(nx>=0&&nx<N&&ny>=0&&ny<M){
				if(vis[nx][ny][dir]){
					total++;
					rows[i]=1;
					break;
				}
				vis[nx][ny][dir]=1;
			}
			else break;
			
			x=nx, y=ny, dir=(dir+1)%4;
		}
	}
	
	printf("%d\n", total);
	for(int i=0;i<N;i++)
		if(rows[i])printf("%d ", i+1);
}