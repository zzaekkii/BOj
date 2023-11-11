#include <bits/stdc++.h>
using namespace std;
int T, N;
long long A, B;
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    while(T--){    	
	    cin >> N >> A >> B;
	    
		if(A%2) cout << N << '\n';
		else {
			long long num=pow(2,N);
			for(ans=-1;A!=0;ans++){
				if(A>=num)A-=num;
				num/=2;
			}
			cout << ans << '\n';
		}
	}
}
