// 1516번 게임 개발 - 골드3 / #위상정렬 
#include <bits/stdc++.h>
using namespace std;

int N, B; // 건물 N개, 건물 번호 B; 

int build_time[501]; // 건물별 건설 시간. 

int cnt[501]; // 해당 건물보다 먼저 지어져야 하는 건물 수. 
vector<int> pre[501]; // 해당 건물 건설 이전에 완공돼야 하는 건물. 
vector<int> post[501]; // 해당 건물 완공 후 지을 건물.

queue<int> Q;
int ans[501]; // 각 건물 다 지어지는 최소 시간. 

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=1;i<=N;i++){
		cin >> build_time[i];
		
		while((cin >> B)&&B!=-1){
			pre[i].push_back(B);
			post[B].push_back(i);
			cnt[i]++;
		}
	}
	
	// 선행 건물 없는 애는 바로 ㄱ. 
	for(int i=1;i<=N;i++)
		if(!cnt[i])Q.push(i);
	
	while(!Q.empty()){
		int cur=Q.front(); Q.pop();
		
		int pre_cnt=pre[cur].size();
		for(int i=0;i<pre_cnt;i++)
			ans[cur]=max(ans[cur],ans[pre[cur][i]]);
		ans[cur]+=build_time[cur];
		
		int post_cnt=post[cur].size();
		for(int i=0;i<post_cnt;i++)
			if(!(--cnt[post[cur][i]]))
				Q.push(post[cur][i]);
	}
	
	for(int i=1;i<=N;i++)
		cout << ans[i] << '\n';
}
