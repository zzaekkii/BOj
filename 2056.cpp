// 2056번 작업 - 골드4 / #위상정렬 
#include <bits/stdc++.h>
using namespace std;

int N, W; // 작업 1-N, 작업: W. 
int C[10001]; // 각 작업들의 선행작업 수 카운트.
int T[10001]; // 각 작업시간. 
vector<int> V[10001]; // 어떤 작업의 선행작업인가.
vector<int> X[10001]; // 어떤 작업을 선행해야 하는가. 
queue<int> Q; // 다음에 실행할 작업 대기큐. 
int ans;
int fin[10001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    // 각 작업별 특성 파악. 
    for(int i=1;i<=N;i++){
    	cin >> T[i] >> C[i];
    	
    	// 선행 작업 목록 저장. 
    	for(int j=0;j<C[i];j++){
    		cin >> W;
    		V[W].push_back(i);
    		X[i].push_back(W); 
		}
	}
	
	// 선행작업 없는 애 슉샥. 
	for(int i=1;i<=N;i++)
		if(!C[i]){
			Q.push(i);
			fin[i]=T[i];
			pp[0]=max(pp[0],T[i]);
		}
	
	// 시간 합산 레스코. 
	while(!Q.empty()){
		int cur=Q.front(); Q.pop();
		
		int mx=0;
		// 시간 누적.
		int l=X[cur].size();
		for(int i=0;i<l;i++)
			mx=max(mx,fin[X[cur][i]]);
		fin[cur]=mx+T[cur];
		mx=fin[cur];
		
		// 선행작업 없는 애 탐색. 
		l=V[cur].size();
		for(int j=0;j<l;j++){
			int nxt=V[cur][j];
			if(!(--C[nxt])){
				fin[nxt]=fin[cur]+T[nxt];
				Q.push(nxt);
			}
		}
		ans=max(ans,fin[cur]);
	}
	
	cout << ans;
}
