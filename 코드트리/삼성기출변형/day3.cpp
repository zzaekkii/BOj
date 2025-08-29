#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, M, K;
int board[21][21];

deque<pair<int,int>> team[6];
int team_idx;
bool vis[21][21];

int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int total_score;

bool in_range(int x, int y){
    if(x>=0&&x<N&&y>=0&&y<N)return 1;
    return 0;
}

void dfs(int x, int y){
    vis[x][y]=1;
    team[team_idx].push_back({x,y});

    for(int dir=0;dir<4;dir++){
        int nx=x+dx[dir];
        int ny=y+dy[dir];

        if(in_range(nx,ny)&&!vis[nx][ny]){
            if((board[x][y]==1&&board[nx][ny]==2)
                ||(board[x][y]!=1&&(board[nx][ny]==2||board[nx][ny]==3)))
                dfs(nx,ny);
        }
    }
}

pair<int,int> move_next(int x, int y, int no_x, int no_y){
    for(int dir=0;dir<4;dir++){
        int nx=x+dx[dir];
        int ny=y+dy[dir];

        if(in_range(nx,ny)&&board[nx][ny]!=0&&!(nx==no_x&&ny==no_y)){
            return {nx,ny};
        }
    }
    return {-1,-1};
}

void move_all(){
    for(int i=0;i<team_idx;i++){
        auto fst=team[i][0];
        auto sec=team[i][1];
        auto last=team[i].back();

        auto nxt=move_next(fst.X,fst.Y, sec.X,sec.Y);

        team[i].push_front(nxt);
        team[i].pop_back();

        // 보드 최신화
        board[last.X][last.Y]=4;
        board[nxt.X][nxt.Y]=1;
    }
}

int hit_human(int x, int y){
    int human_idx=0;

    // 점수 계산
    for(int i=0;i<M;i++){
        int l=team[i].size();
        for(int j=0;j<l;j++)
            if(team[i][j].X==x&&team[i][j].Y==y){
                human_idx=j+1;

                // 방향 뒤집기
                reverse(team[i].begin(),team[i].end());
                return human_idx*human_idx;
            }
    }

    return 0;
}

int throw_ball(int round){
    round%=4*N;

    pair<int,int> start={0,0};
    pair<int,int> step={0,0};

    if(round<N){
        start={round,0};
        step={0,1};
    }
    else if(round<2*N){
        start={N-1,round-N};
        step={-1,0};
    }
    else if(round<3*N){
        start={N-1-(round-2*N),N-1};
        step={0,-1};
    }
    else{
        start={0,N-1-(round-3*N)};
        step={1,0};
    }

    for(int i=0;i<N;i++){
        int nx=start.X+step.X*i;
        int ny=start.Y+step.Y*i;

        if(board[nx][ny]==1)
            return hit_human(nx,ny);
    }

    return 0;
}

int main(){
    // 입력
    cin >> N >> M >> K;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> board[i][j];
    

    // 각 팀 list로 저장
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(board[i][j]==1){
                dfs(i,j);
                team_idx++;
            }
    // 사람 모두 1로 통일 (숫자가 의미없어짐)    
    for(int i=0;i<team_idx;i++)
        for(auto a: team[i])
            board[a.X][a.Y]=1;


    // 라운드 진행
    for(int round=0;round<K;round++){
        // 1. 팀 이동
        move_all();

        // 2. 공 던지고, 맞점 계산
        total_score+=throw_ball(round);
    }

    cout << total_score;
}

/**
    라운드마다
        1. 각 팀: 머리사람을 따라 한 칸 이동 (사람이 꽉 차 있을 수 있음)
            -> 머리가 1칸 증가, 꼬리 사라
        2. 라운드마다 순서에 맞는 행/열에 공이 던져짐 (좌,상,우,하) -> 4N
        3. 공이랑 최초로 맞는 사람이 점수 획득
            - 머리 사람을 기준으로 K번째라면 K*K 점 획득
            - 공을 획득한 팀은 머리사람과 꼬리사람(진행방향 바뀜)

    팀 마다 사람을 어떻게 저장할 것인가 
**/
