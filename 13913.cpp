#include <bits/stdc++.h>
#define MAX 100'001
using namespace std;

int N,K;
int vis[MAX];
int dr[3]={-1,1};
int path[MAX];
int ans[MAX];
queue<int> Q;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
    
    if(N==K){
        cout << "0\n" << N;
        return 0;
    }
	
	fill(vis,vis+MAX,MAX);
	vis[N]=0;
	Q.push(N);
	int cnt=0;
	
	while(!Q.empty()){
		int cur=Q.front(); Q.pop();		
		dr[2]=cur;
		for(int i=0;i<3;i++){
			int nxt=cur+dr[i];
			cnt=vis[cur];
			
			if(nxt<0||nxt>=MAX)continue;			
			if(nxt==K){
				vis[nxt]=cnt+1;
				path[nxt]=cur;
				cout << vis[K] << '\n';
				int idx=0;
				ans[idx++]=K;
				for(int i=K;i!=N;i=path[i])
					ans[idx++]=path[i];
				for(int i=vis[K];i>=0;i--)
					cout << ans[i] << ' ';
				return 0;
			}
			else if(vis[nxt]>=cnt+1){
				vis[nxt]=cnt+1;
				path[nxt]=cur;
				Q.push(nxt);
			}
		}
	}
}
