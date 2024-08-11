#include <bits/stdc++.h>
using namespace std;

int N;
int rom[]={1,5,10,50};
bool ex[1001];
int ans;

void Dfs(int cnt,int idx,int sum){
	if(cnt==N){
		if(!ex[sum]){
			ex[sum]=1;
			ans++;
		}
		return;
	}
	for(int i=idx;i<4;i++)
		Dfs(cnt+1,i,sum+rom[i]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	Dfs(0,0,0);
	
	cout << ans;
}
