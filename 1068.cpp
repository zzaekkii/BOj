// 1068번 트리 - 골드5 / 트리
#include <bits/stdc++.h>
using namespace std;

int N, T; // 노드 N개, 삭제할 노드 T. 
vector<int> V[51]; // 가진 자식 목록.
int par[51]; // 부모 저장(없으면 -1, 지워진거면 999) 

int ans;

// 노드 일가 몰살 함수 (몰살 안할 거임) 
void Dfs(int x){
	if(x==-1)return;
	
	// 호적 파기. 
	auto it=find(V[par[x]].begin(),V[par[x]].end(),x);
	if(it!=V[par[x]].end())V[par[x]].erase(it);
	
	// x의 자식들에게도 적용. 
	for(auto a: V[x])
		Dfs(a);
	
	V[x].clear();
	par[x]=999;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	// 부모 목록 -1로 초기화.
	for(int i=0;i<50;i++)par[i]=-1; 
	
	// 노드 개수. 
	cin >> N;
	
	// 부모 입력받기. 
	for(int i=0;i<N;i++){
		cin >> par[i];
		
		// 해당 부모의 자식 목록에 추가. 
		if(par[i]!=-1)
			V[par[i]].emplace_back(i);
	}
	
	// 제거할 노드. 
	cin >> T;
	
	// 타고가면서 자식 노드 몰살,, 
	Dfs(T);
		
	// 자식 목록 사이즈 0인 애들 합. 
	for(int i=0;i<N;i++)
		if(V[i].empty()&&par[i]!=999)ans++;
	
	cout << ans;
}
