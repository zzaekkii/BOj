#include <bits/stdc++.h>
using namespace std;

int N,M;
int A[9];
bool use[9];
int ans[9];

void Dfs(int idx,int cnt){
	if(cnt==M){
		for(int i=0;i<M;i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	
	int prev=0;
	for(int i=idx;i<N;i++)
		if(!use[i]&&prev!=A[i]){
			use[i]=1;
			ans[cnt]=prev=A[i];
			Dfs(i+1,cnt+1);
			use[i]=0;
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
