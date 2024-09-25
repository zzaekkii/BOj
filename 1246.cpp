#include <bits/stdc++.h>
using namespace std;

int N,M;
int A[1001];
int mx,res;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	for(int i=0;i<M;i++)
		cin >> A[i];
	
	sort(A,A+M);
	
	for(int i=1;i<=M;i++)
		if(i<=N){
			if(res<A[M-i]*i){
				mx=A[M-i];
				res=mx*i;
			}
		} else break;
	
	
	cout << mx << ' ' << res;
}
