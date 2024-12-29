// 1359번 복권 - 실버4 / #확률 
#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int fac[9]={1};

int Comb(int n, int k){
    if(k>n||k<0)return 0;
    return fac[n]/(fac[k]*fac[n-k]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	
	for(int i=1;i<=8;i++)
    	fac[i]=fac[i-1]*i;
	
	int total=Comb(N,M);
	int sum=0;
	
	for(int i=K;i<=M;i++){
		int same=Comb(M,i);
		int diff=Comb(N-M,M-i);
		sum+=same*diff;
	}
	
	double ans=(double)sum/total;
	cout.precision(10);
	cout << ans;
}
