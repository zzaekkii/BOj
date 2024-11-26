// 14627번 파닭파닭 - #이분탐색 
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll S, C; // 파 S개, 주문 C건.
ll L[1'000'001]; // 파 길이들. 
ll sum, use, ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> S >> C;
	
	for(int i=0;i<S;i++){
		cin >> L[i];
		sum+=L[i];
	}
	
	ll st=1,en=1e9;
	while(st<=en){
		ll md=(st+en)/2;
		ll cnt=0;
		
		for(int i=0;i<S;i++)
			cnt+=L[i]/md;
		
		if(cnt>=C){
			use=md;
			ans=sum-C*use;
			st=md+1;
		}
		else en=md-1;
	}
	
	cout << ans;
}
