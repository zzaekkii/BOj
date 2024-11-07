// 1753번 최단경로 - 골드4 / 최단경로, 데이크스트라.
#include <bits/stdc++.h>
using namespace std;

int V, E, K; // 정점 V개, 간선 E개, 시작점 K. 
int u, v, w; // u에서 v로 가는 가중치 w. 

vector<pair<int,int>> node[20001]; // 정점 N에서 {E로 가는 가중치 W}. 
int dis[20001]; // 최종 경로값. 

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> K;
    
    for(int i=0;i<=V;i++)
    	dis[i]=0x7FFFFFFF;
    
    for(int i=0;i<E;i++){
    	cin >> u >> v >> w;
    	node[u].push_back({v,w});
	}
	
	// 시작점인 자기자신은 거리가 0. 
	dis[K]=0;
	 
	// K까지의 가장 작은 가중치 0.
	// 가중치 기준 우선순위 큐. 
	pq.push({0,K});
	
	while(!pq.empty()){
		int pre=pq.top().first;
		int num=pq.top().second;
		pq.pop();
		
		int l=node[num].size();
		for(int i=0;i<l;i++){
			int x=node[num][i].first;
			int cur=node[num][i].second;
			
			// 지금까지 거리에 x까지 가는 비용을 추가해도 적으면 pick. 
			if(pre+cur<dis[x]){
				dis[x]=pre+cur;
				// 이제부터 V까지는 pre+cur만큼 걸리는 걸로. 
				pq.push({pre+cur,x});
			}
		}
	}
	
	for(int i=1;i<=V;i++)
		if(dis[i]==0x7FFFFFFF)cout << "INF\n";
		else cout << dis[i] << '\n';
}
