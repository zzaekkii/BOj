#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[10001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i, tmp;
    cin >> N >> M;
    
    A[0]=0;
    for(i=1;i<=N;i++){
    	cin >> tmp;
    	A[i]=A[i-1]+tmp;
	}
	
	int st=0, en=0, cnt=0;
	while(en<=N){
		long long sum=A[en]-A[st];
		if(sum<=M){
			if(sum==M)cnt++;
			en++;
		}
		else st++;
	}
	cout << cnt;
}
