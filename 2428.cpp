// 2428번 표절 - #이분탐색 
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int N; // 파일의 개수. 
int S[100001]; // 각 파일 크기.

ll ans;

int BinSrch(int idx){
	// idx보다 크거나 같은 애들이 대상임. 
	int st=idx+1,en=N-1;
    // 최소 자기 위치는 넘겨야 아무고토 없는 거시다..
	int ret=idx;
	
	while(st<=en){
		int md=(st+en)/2;
		if(S[md]*9<=S[idx]*10){
			ret=md;
			st=md+1; 
		}
		else en=md-1;
	}
	return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
    	cin >> S[i];
    
    sort(S,S+N);
    
    for(int i=0;i<N;i++)
    	// 자기랑 비슷한 애 개수가 곧 걔랑 쌍 수. 
    	ans+=BinSrch(i)-i;
    
    cout << ans;
}
