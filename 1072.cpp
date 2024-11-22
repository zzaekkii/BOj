// 1072번 게임 - #이분탐색 
#include <bits/stdc++.h>
using namespace std;

long long X, Y;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> X >> Y;
    
    // 승률. 
    int z=(long long)(100*Y)/X;
    
    // 현재 99% 이상이면, 변화 불가능. 
    if(z>=99) cout << -1;
    else{
    	int st=0, en=1'000'000'000;
    	
    	int ans=0;
    	while(st<=en){
    		int md=(long long)(st+en)/2;
    		if((long long)(100*(Y+md))/(X+md)>z){
    			ans=md;
    			en=md-1;
			}
			else st=md+1;
		}
		
		cout << ans;    	
	}
}
