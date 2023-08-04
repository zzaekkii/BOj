#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100001];
int ans = 0x7fffffff;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=0;i<N;i++)
    	cin >> A[i];    
    sort(A, A+N);
    
    int st, en;
    for(st=en=0;st<N;st++){
    	while(en<N && A[en]-A[st]<M) en++;
    	if(en==N) break;
    	ans=min(ans,A[en]-A[st]);
	}
	cout << ans;
}
