#include <bits/stdc++.h>
using namespace std;

int N,M,T;
long long cnt[1001];
long long sum;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	
	while(N--){
		cin >> T;
		sum+=T;
		cnt[sum%M]++;
	}
	
	long long ans=cnt[0];	
	for(int i=0;i<M;i++)
		ans+=cnt[i]*(cnt[i]-1)/2;
		
	cout << ans;
}
