#include <bits/stdc++.h>
using namespace std;

int N,M,P;
int A[200001];
unordered_map<int,int> um;

bool check(){
	for(int i=0;i<M-1;i++)
		if(++um[A[i]]>=P)return 1;
	
	for(int i=M-1;i<N;i++){
		if(++um[A[i]]>=P)return 1;
		um[A[i-M+1]]--;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	P=(9*M+9)/10;
	
	for(int i=0;i<N;i++)
		cin >> A[i];
	
	if(check())cout << "YES";
	else cout << "NO";
}
