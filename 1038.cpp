#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int N;
int cnt;
ll ans=-1;
 
// 자릿수, 현재값. 
void Dfs(int len,ll num){
	if(!len){
		if(cnt==N)ans=num;
		cnt++;
		return;
	}
	
	int last=num%10;
	if(!num)last=10;
	for(int i=0;i<last;i++){
		ll nxt=(num*10)+i;
		if(!num&&!i)continue;
		Dfs(len-1,nxt);
	}
}

// 9876543210이 최대. 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<=10;i++)
		Dfs(i,0);
		
	cout << ans;
}
