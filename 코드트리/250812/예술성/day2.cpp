#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

int N;
int board[30][30];

int dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
int total;

void print_board(){
    cout << "----------------------\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

void inputs(){
    cin >> N;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> board[i][j];
}

bool in_range(int x, int y){
    if(x>=0&&x<N&&y>=0&&y<N)return 1;
    return 0;
}

void flood_fill(int x, int y, int group_id, int visited[30][30], int group_size[900]){
    queue<pair<int,int>> Q;
    Q.push({x,y});
    visited[x][y]=group_id;
    group_size[group_id]++;

    while(!Q.empty()){
        auto cur=Q.front(); Q.pop();

        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];

            if(in_range(nx,ny)&&board[nx][ny]==board[cur.X][cur.Y]&&!visited[nx][ny]){
                visited[nx][ny]=group_id;
                group_size[group_id]++;
                Q.push({nx,ny});
            }
        }
    }
}

int art_score(){
    // 1. 그룹 나누기.
    int visited[30][30]={0};
    int group_size[900]={0};
    int group_cnt=0;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(!visited[i][j]){
                group_cnt++;
                flood_fill(i,j,group_cnt,visited,group_size);
            }

    // 2. 완전 탐색으로 각 변 모두 탐색.
    // (a 그룹 x b 그룹): (a칸 수 + b칸 수) x a 숫자 값 x b 숫자 값
        // 을 a 그룹과 b 그룹이 맞닿아 있는 변의 수만큼 반복.
    int score=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            for(int dir=0;dir<4;dir++){
                int nx=i+dx[dir];
                int ny=j+dy[dir];

                if(in_range(nx,ny)&&visited[i][j]!=visited[nx][ny]){
                    int group_a=visited[i][j];
                    int group_b=visited[nx][ny];
                    score+=(group_size[group_a]+group_size[group_b]) * board[i][j] * board[nx][ny];
                }
            }
        }

    // 마주보는 변은 두 그룹에서 중첩되니 반으로 나눠줄 것.
    return score/2;
}

void rotate_square(int sx, int sy, int tmp[30][30]){
    for(int i=sx;i<sx+N/2;i++)
        for(int j=sy;j<sy+N/2;j++){
            // (0,0) 기준으로 세팅.
            int ox=i-sx, oy=j-sy;

            // (x, y) -> (y, size-1-x)
            int rx=oy;
            int ry=N/2-1-ox;

            // (0,0) 기준점을 다시 원위치.
            rx+=sx;
            ry+=sy;
            tmp[rx][ry]=board[i][j];
        }
}

void rotate_board(){
    int tmp[30][30]={0};

    // 1. 정중앙 십자 모양 반시계 90도 회전.
    for(int i=0;i<N;i++){
        tmp[N/2][i]=board[i][N/2];
        tmp[i][N/2]=board[N/2][N-1-i];
    }

    // 2. 4개 정사각형은 시계 방향으로 90도 회전.
    rotate_square(0,0,tmp);
    rotate_square(0,N/2+1,tmp);
    rotate_square(N/2+1,N/2+1,tmp);
    rotate_square(N/2+1,0,tmp);

    // 3. tmp 배열 board로 옮기기.
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            board[i][j]=tmp[i][j];
}

int main(){
    // 입력.
    inputs();

    // 초기 예술 점수 합산.
    total+=art_score();

    // 1-3회전 후의 예술 점수 합산.
    for(int i=0;i<3;i++){
        rotate_board();
        total+=art_score();
    }

    // 예술 점수 합 출력.
    cout << total;
}

/**
    - n x n 배열에서 n은 항상 홀수.
    30*30 => 900 | 900 x 10 x 9 x 120 => 최대 int 범위 내.

    - 그룹: 동일한 숫자가 인접해있는 경우.
    - 조화로움(a 그룹 x b 그룹): (a칸 수 + b칸 수) x a 숫자 값 x b 숫자 값 x a 그룹과 b 그룹이 맞닿아 있는 변의 수

    - 초기 예술 점수: 조화로움 값이 0보다 큰 각각의 조합들의 합.

    - 1회전 시,
        1. 정중앙 십자 모양 반시계 90도 회전.
        2. 4개 정사각형은 시계 방향으로 90도 회전.
    
    - 정답: 초기 예술 점수 + 1회전 후 예술 점수 + 2회전 후 예술 점수 + 3회전 후 예술 점수

    - 문제의 관건
        1. 그룹 나누기
        2. 그림 회전
        3. 맞닿아있는 변
**/
