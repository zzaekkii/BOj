#include <bits/stdc++.h>
using namespace std;

int T,N;
int pr[1'000'001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    while(T--){
    	cin >> N;
    	
    	for(int i=0;i<N;i++)
    		cin >> pr[i];
    		
    	int mx=pr[N-1];
      long long ans=0;
    	for(int i=N-2;i>=0;i--)
    		if(pr[i]>mx)mx=pr[i];
    		else ans+=mx-pr[i];
    		
    	cout << ans << '\n';
	}
}
