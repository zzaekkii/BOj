#include <bits/stdc++.h>
#define MAX 100'001
using namespace std;

int N,K;
int vis[MAX];
int dr[3]={-1,1};
queue<int> Q;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
    
    if(N==K){
        cout << "0\n1";
        return 0;
    }
	
	fill(vis,vis+MAX,MAX);
	vis[N]=0;
	Q.push(N);
	
	int cnt=0,min=MAX,ans=0;
	
	while(!Q.empty()){
		int cur=Q.front(); Q.pop();
		dr[2]=cur;
		for(int i=0;i<3;i++){
			int nxt=cur+dr[i];
			cnt=vis[cur];
			
			if(nxt<0||nxt>=MAX||vis[nxt]>min)continue;
			// 마지막 조건은 찾고 이후 탐색 고려.
			
			if(nxt==K){
				vis[nxt]=cnt+1;
				if(min>vis[nxt]){ // 젤 적은 길 첨 발견. 
					min=vis[nxt];
					ans=1; // ans도 새로 카운트. 
				}
				else if(min==vis[nxt])
					ans++;
			}
			else if(vis[nxt]>=cnt+1){
				vis[nxt]=cnt+1;
				Q.push(nxt);
			}
		}
	}
	
	cout << vis[K] << '\n' << ans;
}
