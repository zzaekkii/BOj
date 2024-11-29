// 1590번 캠프가는 영식 - #이분탐색 
#include <bits/stdc++.h>
using namespace std;

int N, T; // 버스 N대, 영식쓰 T분에 도착.
int S, I, C; // 버스 S시에 출발해서 I분마다 C번까지 옴.
int mn=0x7FFFFFFF,ans=-1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T;
    
    while(N--){
    	cin >> S >> I >> C;
    	
    	// 첫차, 막차. 
    	int st=1, en=C;
    	while(st<=en){
    		int md=(st+en)/2;
    		
    		if(S+I*(md-1)>=T){
    			ans=mn=min(mn,S+I*(md-1)-T);
    			en=md-1;
			}
			else st=md+1;
		}
	}
	
	cout << ans;	
}
