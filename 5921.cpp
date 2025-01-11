// 5921번 Escaping the Farm - 실버2 / #구현 
#include <bits/stdc++.h>
using namespace std;

int N;
int A[21];
int ans=1;

bool Carry(int x,int y){
	for(;x&&y;x/=10,y/=10)
		if(x%10+y%10>9)return 1;
	return 0;
}

void Find(int idx,int cnt,int sum){
	if(cnt>ans)ans=cnt;
	// 남은 거 다 맞아도 본전. 
	if(idx==N||cnt+N-idx<=ans)return;
	
	if(!Carry(sum,A[idx]))Find(idx+1,cnt+1,sum+A[idx]);
	Find(idx+1,cnt,sum);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> A[i];
	
	Find(0,0,0);
	
	cout << ans;
}
