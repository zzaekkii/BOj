#include <bits/stdc++.h>
using namespace std;

int N,M;
int A[9];
int ans[9];

void Dfs(int num,int cnt){
	if(cnt==M){
		for(int i=0;i<M;i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	
	int prev=0;
	for(int i=num;i<N;i++)
		if(prev!=A[i]){
			ans[cnt]=prev=A[i];
			Dfs(i,cnt+1);
		}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
		cin >> A[i];
	
	sort(A,A+N);	
	
	Dfs(0,0);
}
