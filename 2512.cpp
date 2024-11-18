// 2512번 예산 - 실버2 / #이분탐색 
#include <bits/stdc++.h>
using namespace std;

int N, M; // 지방 N곳, 예산 M원.
int req[10001];
int ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
   	cin >> N;
	
	int en=0; 
	for(int i=0;i<N;i++){
		cin >> req[i];
		en=max(en,req[i]);
	}
	
	cin >> M;
	
	int st=M/N;
	while(st<=en){
		// 일단 얘로 잡아두고, 
		int md=(st+en)/2;
		int gc=0;
		
		// 돈이 얼마나 남나 확인. 
		for(int i=0;i<N;i++)
			if(md>req[i])gc+=md-req[i];
		
		// 돈 좀 더 써도 된다? 
		if(md*N-gc<=M){
			ans=md;
			st=md+1;
		}
		else en=md-1;
	}
	
	cout << ans;
}
