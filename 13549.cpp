#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, K;
bool vis[100001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
// 우선 순위 큐 + greater(첫번째 인자 기준 오름차순). 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    
    PQ.push({0,N});
    
    while (!PQ.empty()) {
    	auto cur=PQ.top();PQ.pop();
    	vis[cur.Y]=1;
    	
    	if(cur.Y==K){
    		cout << cur.X;
    		break;
		}
		
		if(cur.Y-1>=0&&!vis[cur.Y-1])
			PQ.push({cur.X+1,cur.Y-1});
		if(cur.Y+1<=100000&&!vis[cur.Y+1])
			PQ.push({cur.X+1,cur.Y+1});
		if(cur.Y*2<=100000&&!vis[cur.Y*2])
			PQ.push({cur.X,cur.Y*2});
    }
}
