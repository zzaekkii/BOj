// 1766번 문제집 - 골드2 / #위상정렬 #DP 
#include <bits/stdc++.h>
using namespace std;

int N, M; // N문제, 선수과목 M개.
int A, B; // A -> B.

int cnt[32001]; // 해당 과목의 선수과목 수. 
vector<int> pre[32001]; // 해당 과목 이전에 풀어야 하는 문제. 
vector<int> post[32001]; // 해당 과목 이후에 풀 수 있는 문제. 

priority_queue<int, vector<int>, greater<int>> Q; // 대기 과목 큐. 우선순위 큐
vector<int> ans; // 최적의 풀이 순서. 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
	
	while(M--){
		cin >> A >> B;
		
		// A -> B. 
		pre[B].emplace_back(A);
		post[A].emplace_back(B);
		
		// B과목의 선수과목 카운트 증가. 
		cnt[B]++;
	} 
	
	// 선수과목 쉬운 문제 순(오름차순)으로 정렬. 
	for(int i=1;i<=N;i++){
		sort(pre[i].begin(),pre[i].end());
		sort(post[i].begin(),post[i].end());
	}
	
	// 선수과목이 없는 과목 큐에 추가. 
	for(int i=1;i<=N;i++)
		if(!cnt[i])
			Q.push(i);
	
	while(!Q.empty()){
		int cur=Q.top(); Q.pop();
		
		ans.emplace_back(cur);
		
		for(int nxt: post[cur])
			if(!(--cnt[nxt]))
				Q.push(nxt);
	} 
	
	// 최적으로 풀 수 있는 문제 순서 제시. 
	for(int a: ans)
		cout << a << ' ';
}
