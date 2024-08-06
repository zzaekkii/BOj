#include <bits/stdc++.h>
using namespace std;

int A[10];
int B[10];
int idx,ans;

void Dfs(int cnt){
	if(idx==10){
		if(cnt>=5)
			ans++;
		return;
	}
	
	for(int i=1;i<=5;i++){
		if(idx>1)
			if(B[idx-2]==i&&B[idx-1]==i)continue;
		B[idx++]=i;
		if(B[idx-1]==A[idx-1])Dfs(cnt+1);
		else Dfs(cnt);
		idx--;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for(int i=0;i<10;i++)
		cin >> A[i];
	
	Dfs(0);
	
	cout << ans;
}
