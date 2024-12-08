// 13702번 이상한 술집 - 실버2 / #이분탐색 #매개변수탐색 
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int N, K; // 주전자 N개, K명.
ll L[10001]; // 용량.

ll ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    
    for(int i=0;i<N;i++)
    	cin >> L[i];
	
	ll st=0,en=INT_MAX;
	while(st<=en){
		ll md=(st+en)/2;
		
		ll cnt=0;		
		for(int i=0;i<N;i++)
			cnt+=L[i]/md;
		
		if(cnt>=K){
			ans=md;
			st=md+1;
		}
		else en=md-1;
	}
	
	cout << ans;
}
