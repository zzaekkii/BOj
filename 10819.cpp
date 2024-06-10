#include <bits/stdc++.h>
using namespace std;

int N;
int A[10];
bool use[10];
int sum[10];
int ans;

void Dfs(int idx){
	if(idx==N){
		int tmp=0;
		for(int i=0;i<N-1;i++)
			tmp+=abs(sum[i+1]-sum[i]);
		ans=max(ans,tmp);
		return;
	}
	
	for(int i=0;i<N;i++)
		if(!use[i]){
			use[i]=1;
			sum[idx]=A[i];
			Dfs(idx+1);
			use[i]=0;
		}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> A[i];
	
	Dfs(0);
	
	cout << ans;
}
