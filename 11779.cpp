// 11779번 최소비용 구하기 2 - 골드3 / #데이크스트라 
#include <bits/stdc++.h>
#define INF 200'000'000
using namespace std;

int N, M; // 도시 N개, 버스 M대.
int X, Y, W; // 도시 X에서 Y로 가는 비용 W. 
int A, B; // 도시 A에서 B로 가는 최소 비용 구하기. 

vector<pair<int,int>> bus[1001]; // 도착도시, 비용. 
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
int cost[1001];
int path[1001];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    // 최초 비용 초기화. 
    for(int i=1;i<=N;i++)
    	cost[i]=INF;
    
    // 각 도시간 이동 비용 입력. 
    while(M--){
    	cin >> X >> Y >> W;
    	bus[X].push_back({Y,W});
	}

	// A -> B.
	cin >> A >> B;
	
	// 출발지 비용 0 세팅. 
	cost[A]=0;
	Q.push({0,A});
	
	while(!Q.empty()){
		int curW=Q.top().first;
		int curX=Q.top().second; Q.pop();
		
		// 이미 효율적인 길 찾았으면 패스. 
		if(curW>cost[curX])continue;
		
		for(auto& a: bus[curX]){
			int nxt=a.first;
			int nxt_cost=a.second;
			
			if(curW+nxt_cost<cost[nxt]){
				cost[nxt]=curW+nxt_cost;
				path[nxt]=curX;
				Q.push({cost[nxt],nxt});
			}
		}
	}
	
	int nxt=B;
	while(1){
		ans.emplace_back(nxt);
		if(nxt==A)break;
		nxt=path[nxt];
	}
	
	cout << cost[B] << '\n';
	cout << ans.size() << '\n';
	
	reverse(ans.begin(),ans.end());
	for(auto a: ans)
		cout << a << ' ';
}
