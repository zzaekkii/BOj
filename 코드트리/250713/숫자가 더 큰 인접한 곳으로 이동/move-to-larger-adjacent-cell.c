#include <stdio.h>

int n, start_r, start_c;
int grid[101][101];

int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};

int main() {
    scanf("%d %d %d", &n, &start_r, &start_c);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Please write your code here.
    while(1){
        int flag=1;
        printf("%d ", grid[start_r][start_c]);

        for(int dir=0;dir<4;dir++){
            int nx=start_r+dx[dir];
            int ny=start_c+dy[dir];

            if(nx>0&&nx<=n&&ny>0&&ny<=n){
                if(grid[nx][ny]>grid[start_r][start_c]){
                    start_r=nx, start_c=ny;
                    flag=0;
                    break;
                }
            }
        }

        if(flag)break;
    }

    return 0;
}