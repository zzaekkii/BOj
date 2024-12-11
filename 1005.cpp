// 1005번 ACM Craft - 골드3 / #위상정렬 #DP 
#include <bits/stdc++.h>
using namespace std;

int T, N, K; // 테스트 T번, 건물 1-N개, 건설 순서 K개. 
int D[1001]; // 각 건물 짓는 시간. 
int X, Y, W; // X짓고 나서 Y짓기, 목표 건물 번호 W. 

int cnt[1001]; // 선행 건축물 개수. 
vector<int> pre[1001]; // 먼저 지어야 하는 건물. 
vector<int> post[1001]; // 이거 짓고나서 지을 수 있는 건물.
 
int fin[1001]; // 건설 끝난 시간. 
queue<int> Q; // 건설 대기 큐. 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
	
	while(T--){
		cin >> N >> K;
		
		// 각 건물 짓는데 걸리는 시간 췌크. 
		for(int i=1;i<=N;i++)
			cin >> D[i];
		
		// 건설 순서 입력 (X -> Y) 
		for(int i=0;i<K;i++){
			cin >> X >> Y;
			
			// 건물 Y의 선행 건축물 개수 증가. 
			cnt[Y]++;
			pre[Y].emplace_back(X);
			post[X].emplace_back(Y); 
		}
		
		// 어떤 건물을 짓는 게 목푠가. 
		cin >> W;
		
		for(int i=1;i<=N;i++){
			// 먼저 지어야할 건물이 없는 건물 선별. 
			if(!cnt[i]){
				Q.push(i);
				// 이 건물들은 자기 건설 시간만큼밖에 안걸림. 
				fin[i]=D[i];
			}
		}
		
		while(!Q.empty()){
			int cur=Q.front(); Q.pop();
			
			int mx=0;
			// 건설에 필요한 시간 췌크. 
			int pre_l=pre[cur].size();
			for(int i=0;i<pre_l;i++)
				mx=max(mx,fin[pre[cur][i]]);
			
			// 선행 건축물 중 가장 최근 시간 + 얘 짓는데 걸리는 시간. 
			fin[cur]=max(fin[cur],mx+D[cur]);
			
			// 얘 짓고 지을 수 있는 건물 중, 충족한 애 췌크. 
			int post_l=post[cur].size();
			for(int i=0;i<post_l;i++){
				int nxt=post[cur][i];
				// 지금 건설 가능한 애 바로 건설. 
				if(!(--cnt[nxt])){
					fin[nxt]=fin[nxt]+D[nxt];
					Q.push(nxt);
				}
			}
		}		
		
		// W건물 짓는 데 최종적으로 걸린 시간 출력. 
		cout << fin[W] << '\n';
		
		// 다음 테케를 위해 내용 정리. 
		memset(fin,0,sizeof(fin));
		memset(cnt,0,sizeof(cnt));
		memset(D,0,sizeof(D));
		for(int i=1;i<=N;i++){
			pre[i].clear();
			post[i].clear();
		}
	} 
}
