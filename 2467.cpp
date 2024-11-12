// 2467번 용액 - #이분탐색 #투포인터 
#include <bits/stdc++.h>
using namespace std;

int N;
int liq[100'001];
int mx=2'000'000'001;
int ans[2]; // 최소로 만드는 위치. 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++)
    	cin >> liq[i];
    
    sort(liq,liq+N);
    
    int st=0,en=N-1;
    while(st<en){
    	if(abs(liq[st]+liq[en])<mx){
    		mx=abs(liq[st]+liq[en]);
    		ans[0]=st,ans[1]=en;
		}
		if(liq[st]+liq[en]<0)st++;
		else en--;
	}
	
	cout << liq[ans[0]] << ' ' << liq[ans[1]];
}
