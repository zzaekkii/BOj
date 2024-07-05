#include <bits/stdc++.h>
using namespace std;

int N,K;

int arr[20];
int idx,cnt;

void Dfs(int sum){
	if(sum>N)return;
	if(sum==N){
		cnt++;
		if(cnt==K)
			for(int i=0;i<idx;i++){
				cout << arr[i];
				if(i!=idx-1)cout << '+';
			}
		return;
	}
	for(int i=1;i<=3;i++){
		arr[idx++]=i;
		Dfs(sum+i);
		idx--;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	
	Dfs(0);
	
	if(!cnt||cnt<K)cout << -1;
}
