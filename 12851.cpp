#include <bits/stdc++.h>
using namespace std;
#define X first

int N, K;
int vis[100001];
int cnt;
queue<int> Q;

void check(int k){
	if(k==N){
		cnt++;
		return;
	}
   	if(k!=0&&vis[k-1]==vis[k]-1) check(k-1);
   	if(k!=100000&&vis[k+1]==vis[k]-1) check(k+1);
   	if(!(k%2)&&k!=0&&vis[k/2]==vis[k]-1) check(k/2);
   	return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    
    fill(vis,vis+100001,-1);
    vis[N]=0;
    Q.push(N);
    
    while (vis[K]==-1) {
        auto cur = Q.front(); Q.pop();
        for(int mv:{cur-1,cur+1,cur*2}){
        	if(mv<0||mv>100000)continue;
        	if(vis[mv]!=-1)continue;
        	vis[mv]=vis[cur]+1;
        	Q.push(mv);
		}
    }
    check(K);
    cout << vis[K] << '\n' << cnt;
}
