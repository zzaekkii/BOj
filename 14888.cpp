#include <bits/stdc++.h>
using namespace std;

int N;
int A[12];
int op[5];
int cur;
int mx=-1'000'000'000,mn=1'000'000'000;

void Calc(int o,int idx){
	op[o]--;
	switch(o){
		case 0: // 덧셈.
			cur+=A[idx];
			break;
		case 1: // 뺄셈. 
			cur-=A[idx];
			break;
		case 2: // 곱셈. 
			cur*=A[idx];
			break;
		case 3: // 나눗셈. 
			cur/=A[idx];
			break;
	}
}

void Dfs(int idx){
	if(idx==N){
		mx=max(mx,cur);
		mn=min(mn,cur);
		return;
	}
	
	for(int i=0;i<4;i++)
		if(op[i]){
			int tmp=cur;
			Calc(i,idx);
			Dfs(idx+1);
			op[i]++;
			cur=tmp;
		}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++)
		cin >> A[i];
	
	for(int i=0;i<4;i++)
		cin >> op[i];
	
	cur=A[0];
	Dfs(1);
	
	cout << mx << '\n' << mn;
}
