// 2252번 줄 세우기 - 골드3 / 위상정렬 
#include <bits/stdc++.h>
using namespace std;

int N, M; // 학생 1-N, 비교 횟수 M번.
int A, B; // A보다 B가 큼(뒤). 
int cnt[32001]; // 비교 등장 횟수(많이 나올 수록 뒤)
// 이 횟수를 어떻게 정렬할 건지가 관건. 

vector<int> V[32001]; // 보다 키 큰 애 목록. 
// 이 비교관계는 출현 횟수가 동일한 애들 중,
// 대소 관계를 신경써서 정렬해야 하기 때문에 필요함. 
// ex. 5 4, 3 5
// 1:
// 2: 
// 3: 5, 6
// 4:
// 5: 4
// 6: 5, 4
// 1 2 3 4 5 6
// 0 0 0 2 2 1 이지만, .. 6 5 4가 되어야 함. 

queue<int> Q; // 
int ans[32001]; // 최종 정렬 결과. 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // INPUT
    cin >> N >> M;
    
    while(M--){
    	cin >> A >> B;
    	
    	// 키 비교관계 기억. 
    	V[A].emplace_back(B);
    	cnt[B]++; 
	}
	
	
	// SORT
	// 한번도 등장하지 않은 앞순위 애들. 
	for(int i=1;i<=N;i++)
		if(!cnt[i]) Q.push(i);
	
	for(int i=0;i<N;i++){
		int cur=Q.front(); Q.pop();
		ans[i]=cur;
		
		// 키 대소관계는 사이클이 없어서,
		// 앞에서부터 관계를 순서대로 추적해나가면
		// 꼬일 일이 없음.
		// 앞에 있어야 할 애가 더 없으면,
		// cnt가 0이고 자유임. 
		int l=V[cur].size();
		for(int j=0;j<l;j++){
			int nxt=V[cur][j];
			if(!(--cnt[nxt]))Q.push(nxt); 
		}
	}
	
	for(int i=0;i<N;i++)
		cout << ans[i] << ' ';
}
