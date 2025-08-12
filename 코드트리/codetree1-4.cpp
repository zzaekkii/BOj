// 삼성 기출 변형 - 술래잡기
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int N, M, H, K; // N*N 격자, 도망자 M명, 나무 H그루, K턴.
vector<tuple<int,int,int>> hider; // 위치, 방향(좌우, 상하).
int hiders[100][100];
bool tree[100][100];
tuple<int,int,int> finder; // 술래 위치, 방향.

int dx[]={-1,0,1,0}, dy[]={0,1,0,-1}; // 상-우-하-좌.

void input(){
    cin >> N >> M >> H >> K;

    // 도망자 위치.
    for(int i=0;i<M;i++){
        int x, y, d;
        cin >> x >> y >> d;
        hider.push_back({x-1,y-1,d});
        hiders[x-1][y-1]++;
    }

    // 나무 위치.
    for(int i=0;i<H;i++){
        int x, y;
        cin >> x >> y;
        tree[x-1][y-1]=1;
    }

    // 술래 위치 (N/2, N/2) 방향 (0)
    finder={N/2,N/2,0};
}


bool in_range(int x, int y){
    if(x>=0&&x<N&&y>=0&&y<N)return 1;
    return 0;
}


// 도망자 이동.
void move_hider(){
    vector<tuple<int,int,int>> next_hider;

    auto [fx, fy, fd]=finder;
    for(auto& a: hider){
        auto& [cur_x, cur_y, dir]=a;

        // 술래와 거리 3 이하.
        if(abs(fx-cur_x)+abs(fy-cur_y)<=3){

            // 격자 벗어나면 방향 반대.
            if(!in_range(cur_x+dx[dir],cur_y+dy[dir]))dir=(dir+2)%4;

            // 술래 없으면 1칸 이동
            int nx=cur_x+dx[dir];
            int ny=cur_y+dy[dir];
            if(nx!=fx||ny!=fy){
                hiders[cur_x][cur_y]--;
                hiders[nx][ny]++;
                next_hider.push_back({nx,ny,dir});
            }
            else next_hider.push_back(a);
        }
        else next_hider.push_back(a);
    }

    hider=move(next_hider);
}


// 술래 이동.
void move_finder(){
    auto& [cur_x,cur_y,dir]=finder;

    cur_x+=dx[dir];
    cur_y+=dy[dir];

    // 각 위치별 코너링.
    // x-y==-1, x<N/2 (좌측상단 코너)
    if(cur_x-cur_y==-1&&cur_x<N/2){
        if(dir==0)dir=1;
        else if(dir==3) dir=2;
    }

    // x+y==N-1, x<N/2 (우측상단 코너)
    if(cur_x+cur_y==N-1&&cur_x<N/2){
        if(dir==1)dir=2;
        else if(dir==0)dir=3;
    }

    // x==y, x>N/2 (우측하단 코너)
    if(cur_x==cur_y&&cur_x>N/2){
        if(dir==2)dir=3;
        else if(dir==1)dir=0;
    }

    // x+y==N-1, x>N/2 (좌측하단 코너)
    if(cur_x+cur_y==N-1&&cur_x>N/2){
        if(dir==3)dir=0;
        else if(dir==2)dir=1;
    }


    // 원점 도착 턴.
    if(cur_x==0&&cur_y==0&&dir==0)dir=2;

    // 중앙 도착 턴.
    if(cur_x==N/2&&cur_y==N/2&&dir==2)dir=0;
}


// 도망자 잡고 점수 반환
int catch_hider(int turn){
    int score=0;

    auto [cur_x,cur_y,dir]=finder;
    for(int i=0;i<3;i++){
        int nx=cur_x+dx[dir]*i;
        int ny=cur_y+dy[dir]*i;

        if(in_range(nx,ny)&&!tree[nx][ny]&&hiders[nx][ny]){
            score+=turn*hiders[nx][ny];

            hider.erase(
                remove_if(hider.begin(),hider.end(),
                    [nx,ny](const tuple<int,int,int>& t){
                        return get<0>(t)==nx&&get<1>(t)==ny;
                    }),
                hider.end()
            );
            hiders[nx][ny]=0;
        }
    }

    return score;
}


int main() {
    input();

    int score=0;
    for(int t=1;t<=K;t++){
        move_hider();
        move_finder();
        score+=catch_hider(t);
    }

    cout << score;
}
