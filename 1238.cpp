// 1238번 파티 - 골드3 / #데이크스트라 
#include <bits/stdc++.h>
#define INF 200'000'000
using namespace std;

int N, M, X; // 학생 N명, 길 M개, 파티 장소 X.
int A, B, T; // A -> B 가는 시간 T. 

vector<pair<int,int>> path[1001]; // 단방향 도로.

/**
** 각 출발지에서 X로 가는 최단 시간 각 N번 구하고,
** X에서 각 장소로 되돌아가는 최단 시간 각각 구해준 뒤에
** 더하면 왕복 시간 완성 -> 이 중 최대값 고르면 끝. 
**/
int go[1001]; // X로 가는 시간. 
int ret[1001]; // X에서 돌아가는 시간. 

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int ans; // 최단 거리로 가는 애들 중 가장 오래 걸리는 시간. 

// 출발지별 각 마을까지 최단 시간. 
void Dijkstra(int st, int *arr){
	// INF 초기화.
	for(int i=1;i<=N;i++)arr[i]=INF;
	
	arr[st]=0;
	pq.push({0,st});
	
	while(!pq.empty()){
		// 현재 소요 시간, 현재 출발지. 
		int curT=pq.top().first;
		int curX=pq.top().second; pq.pop();
		
		// 더 이득인 길 이미 찾았으면 패스. 
		if(curT>arr[curX])continue; 
		
		for(auto& a: path[curX]){
			int nxtX=a.first;
			int nxtT=curT+a.second;
			
			// 이번에 갈 길이 이전 길보다 좋다. 
			if(nxtT<arr[nxtX]){
				arr[nxtX]=nxtT;
				pq.push({nxtT,nxtX});
			}
		}
	}
} 

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> X;
	
	while(M--){
		cin >> A >> B >> T;
		
		// A -> B로 가는 시간 T. 
		path[A].push_back({B,T});
	}
	
	// 복귀는 X에서 고정이니까 먼저 ㄱ.
	Dijkstra(X, ret);
	
	// 각 출발지별 X까지 가는 최단 시간. 
	for(int i=1;i<=N;i++){
		Dijkstra(i, go);
		ans=max(ans,ret[i]+go[X]);
	}
	
	cout << ans;
}
